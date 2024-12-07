/*Cài đặt cây biểu thức cho biểu thức trên lớp ngày 3/12/2024, và in ra biểu thức theo các cách biểu diễn Trung tố, hậu tố, và tiền tố.
Định nghĩa và khai báo các hàm sau:
Cài đặt thuộc tính cho 1 node trên cây 
Cài đặt hàm khởi tạo cây (không được bỏ qua hàm kiểm tra rỗng)
Cài đặt hàm nhập phần tử (bổ sung) vào cây 
In các phần tử trên cây theo 3 giải thuật duyệt */
#include<iostream>
#include<string>
using namespace std;

struct Node{
    string data;
    Node* right;
    Node* left;
};

struct Cay{
    Node* head;
};

// Hàm khởi tạo cây
void cay(Cay* x){
    x->head = NULL;
}

// Kiểm tra cây rỗng
bool empty(Node*node){
    return node == NULL;
}

// Hàm tạo node mới
Node* makenode(string value){
    Node* newnode = new Node;
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Hàm tạo cây 
Node* create_Cay() {
    // Tạo cây  theo cấu trúc từ biểu thức: a * 5 - b * c^6 / d + (h - f) * e^1 / 2
    Node* root = makenode("+");

    // Nhánh trái
    Node* left1 = makenode("-");
    left1->left = makenode("*");
    left1->left->left = makenode("a");
    left1->left->right = makenode("5");
    left1->right = makenode("/");
    left1->right->left = makenode("*");
    left1->right->left->left = makenode("b");
    left1->right->left->right = makenode("^");
    left1->right->left->right->left = makenode("c");
    left1->right->left->right->right = makenode("6");
    left1->right->right = makenode("d");

    // Nhánh phải
    Node* right1 = makenode("*");
    right1->left = makenode("-");
    right1->left->left = makenode("h");
    right1->left->right = makenode("f");
    right1->right = makenode("/");
    right1->right->left = makenode("^");
    right1->right->left->left = makenode("e");
    right1->right->left->right = makenode("1");
    right1->right->right = makenode("2");

    // Kết nối nhánh trái và phải vào gốc
    root->left = left1;
    root->right = right1;

    return root;
}

// Hàm duyệt hậu tố 
void LRN(Node* node) {
    if (!empty(node)) {
        LRN(node->left);  // Duyệt nhánh trái
        LRN(node->right); // Duyệt nhánh phải
        cout << node->data << " "; 
    }
}
//Hàm duyệt trung tố
void LNR(Node*node) {
    if (!empty(node)) {
        LNR(node->left);  // Duyệt nhánh trái
        cout << node->data << " "; 
        LNR(node->right); // Duyệt nhánh phải
    }
}
//Hàm duyệt tiền tố
void NLR(Node*node) {
    if (!empty(node)) {
       cout << node->data << " ";
        NLR(node->left);  // Duyệt nhánh trái
        NLR(node->right); // Duyệt nhánh phải
           
    }
}

int main() {
    Cay tree;
    cay(&tree); 
    tree.head = create_Cay();
    cout << "Duyet hau to: ";
    LRN(tree.head);
    cout << endl;
    cout << "Duyet trung to: ";
    LNR(tree.head);
    cout << endl;
    cout << "Duyet tien to: ";
    NLR(tree.head);
    cout << endl;
    return 0;
}

