/*Mục lục của một cuốn sách được lưu trữ dưới dạng một cây trong đó mỗi node có thể là chapter, section, subsection, subsubsection.  
Khai báo cấu trúc cây để biểu diễn cuốn sách. Các thông tin chứa ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung sau được thực hiện:  
Xác định số chương của cuốn sách 
Tìm chương dài nhất của cuốn sách 
Thực hiện tìm một mục và xoá mục đó khỏi sách. Lưu ý cập nhật lại số trang của từng mục.  */
/*
Mục lục của một cuốn sách được lưu trữ dưới dạng một cây trong đó mỗi node có thể là chapter, section, subsection, subsubsection.  
Khai báo cấu trúc cây để biểu diễn cuốn sách. Các thông tin chứa ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung sau được thực hiện:

1. Xác định số chương của cuốn sách.
   - Một chương là các node con trực tiếp của node gốc (root).

2. Tìm chương dài nhất của cuốn sách.
   - Chương dài nhất là node con của root có số trang lớn nhất.

3. Thực hiện tìm một mục và xoá mục đó khỏi sách.
   - Nếu xóa một mục (node), cần cập nhật lại liên kết giữa các node còn lại.
   - Giải phóng bộ nhớ của node bị xóa và tất cả các node con của nó.
*/

#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    string title;         // Tiêu đề của mục
    int pageCount;        // Số trang của mục
    TreeNode* firstchild; // Con đầu tiên
    TreeNode* next_ae;    // Anh em kế tiếp
};

TreeNode* makeNode(const string& t, int p) {
    TreeNode* newNode = new TreeNode();
    newNode->title = t;
    newNode->pageCount = p;
    newNode->firstchild = nullptr;
    newNode->next_ae = nullptr;
    return newNode;
}

void clearTree(TreeNode* node) {
    if (!node) return;
    clearTree(node->firstchild);
    clearTree(node->next_ae);
    delete node;
}

TreeNode* inputNode() {
    string title;
    int pageCount;
    cout << "Nhap tieu de: ";
    getline(cin, title);
    cout << "Nhap so trang: ";
    cin >> pageCount;
    cin.ignore(); 
    return makeNode(title, pageCount);
}

void inputTree(TreeNode* parent) {
    int childCount;
    cout << "Nhap so muc con cua \"" << parent->title << "\": ";
    cin >> childCount;
    cin.ignore(); 

    TreeNode* prevChild = nullptr;
    for (int i = 0; i < childCount; i++) {
        cout << "\nNhap thong tin muc con thu " << i + 1 << " cua \"" << parent->title << "\":"<<endl;
        TreeNode* child = inputNode();

        if (!prevChild) {
            parent->firstchild = child; // Gắn con đầu tiên
        } else {
            prevChild->next_ae = child; // Liên kết anh em kế tiếp
        }
        prevChild = child;

        inputTree(child); // Nhập dữ liệu cho con
    }
}

int countChapters(TreeNode* node) {
    if (!node || !node->firstchild) return 0;

    int count = 0;
    TreeNode* current = node->firstchild;
    while (current) {
        count++;
        current = current->next_ae;
    }
    return count;
}

TreeNode* findLongestChapter(TreeNode* node, TreeNode*& longest) {
    if (!node) return longest;

    // Duyệt qua các con của node gốc thay vì node gốc
    TreeNode* current = node->firstchild;
    while (current) {
        if (!longest || current->pageCount > longest->pageCount) {
            longest = current; // Cập nhật chương dài nhất
        }

        // Tìm tiếp trong các con và anh em của current
        findLongestChapter(current->firstchild, longest);
        current = current->next_ae;
    }

    return longest;
}

bool removeNode(TreeNode* parent, const string& title) {
    TreeNode* current = parent->firstchild;
    TreeNode* prev = nullptr;

    while (current) {
        if (current->title == title) {
            if (prev) {
                prev->next_ae = current->next_ae; // Bỏ qua nút cần xóa
            } else {
                parent->firstchild = current->next_ae; // Cập nhật con đầu tiên
            }

            clearTree(current); // Xóa nút và các con
            return true;
        }
        prev = current;
        current = current->next_ae;
    }

    // Tìm tiếp trong các con
    current = parent->firstchild;
    while (current) {
        if (removeNode(current, title)) {
            return true;
        }
        current = current->next_ae;
    }

    return false;
}

struct Tree {
    TreeNode* root;
};

void initTree(Tree& tree) {
    tree.root = nullptr;
}

bool findAndRemove(Tree& tree, const string& title) {
    if (!tree.root) return false;

    if (tree.root->title == title) {
        // Xóa gốc cây
        clearTree(tree.root);
        tree.root = nullptr;
        return true;
    }

    return removeNode(tree.root, title);
}

int main() {
    Tree book;
    initTree(book); // Khởi tạo cây

    cout << "Nhap thong tin cuon sach:" << endl;
    book.root = inputNode();
    inputTree(book.root);

    cout << endl << "So chuong cua cuon sach: " << countChapters(book.root) << endl;

    TreeNode* longestChapter = nullptr;
    findLongestChapter(book.root, longestChapter);

    if (longestChapter) {
        cout << "Chuong dai nhat: " << longestChapter->title
             << " (" << longestChapter->pageCount << " trang)" << endl;
    } else {
        cout << "Khong co chuong nao trong sach." << endl;
    }

    string titleToRemove;
    cout << endl << "Nhap tieu de muc can xoa: ";
    getline(cin, titleToRemove);
    if (findAndRemove(book, titleToRemove)) {
        cout << "Da xoa muc \"" << titleToRemove << "\" khoi sach." << endl;
    } else {
        cout << "Khong tim thay muc \"" << titleToRemove << "\"." << endl;
    }

    // Giải phóng bộ nhớ
    clearTree(book.root);
    return 0;
}
