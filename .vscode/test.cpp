#include <iostream>
#include <string>
using namespace std;

// Node của cây biểu diễn mục lục
struct Node {
    string name;          // Tên của mục (chapter, section, ...)
    int pages;            // Số trang của mục
    Node* firstChild;     // Con đầu tiên
    Node* nextSibling;    // Anh em kế tiếp

    Node(string n, int p) : name(n), pages(p), firstChild(nullptr), nextSibling(nullptr) {}
};

// Hàm đệ quy đếm số chương của cuốn sách
int countChapters(Node* root) {
    if (!root) return 0;
    int count = 0;
    if (root->name.find("Chapter") != string::npos) {
        count = 1;
    }
    return count + countChapters(root->firstChild) + countChapters(root->nextSibling);
}

// Hàm đệ quy tìm chương dài nhất
Node* findLongestChapter(Node* root, Node*& longest) {
    if (!root) return longest;
    if (root->name.find("Chapter") != string::npos && 
        (!longest || root->pages > longest->pages)) {
        longest = root;
    }
    findLongestChapter(root->firstChild, longest);
    findLongestChapter(root->nextSibling, longest);
    return longest;
}

// Hàm đệ quy tìm và xóa một mục
bool deleteNode(Node*& root, const string& target) {
    if (!root) return false;
    if (root->name == target) {
        Node* temp = root;
        root = root->nextSibling;  // Bỏ qua node hiện tại
        delete temp;               // Giải phóng bộ nhớ
        return true;
    }
    if (deleteNode(root->firstChild, target)) return true;
    return deleteNode(root->nextSibling, target);
}

// Hàm tạo cây và ví dụ sử dụng
int main() {
    // Tạo root (tên sách)
    Node* book = new Node("Book Title", 0);

    // Thêm các chương
    Node* chapter1 = new Node("Chapter 1: Introduction", 10);
    Node* chapter2 = new Node("Chapter 2: Basics", 20);
    Node* chapter3 = new Node("Chapter 3: Advanced Topics", 15);

    // Thêm các mục con
    Node* section1 = new Node("Section 1.1: Overview", 5);
    Node* section2 = new Node("Section 2.1: Details", 7);

    // Xây dựng cây
    book->firstChild = chapter1;
    chapter1->nextSibling = chapter2;
    chapter2->nextSibling = chapter3;
    chapter1->firstChild = section1;
    chapter2->firstChild = section2;

    // Đếm số chương
    cout << "Number of chapters: " << countChapters(book) << endl;

    // Tìm chương dài nhất
    Node* longest = nullptr;
    findLongestChapter(book, longest);
    if (longest) {
        cout << "Longest chapter: " << longest->name 
             << " with " << longest->pages << " pages." << endl;
    }

    // Xóa một mục
    string target = "Chapter 2: Basics";
    if (deleteNode(book->firstChild, target)) {
        cout << "Deleted: " << target << endl;
    } else {
        cout << "Target not found: " << target << endl;
    }

    // Đếm lại số chương sau khi xóa
    cout << "Number of chapters after deletion: " << countChapters(book) << endl;

    return 0;
}
