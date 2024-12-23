/*Cài đặt cây AVL để nhập một dãy số cho trước (dãy cho trên lớp) thành một cây AVL 

Yêu cầu:
Cài đặt hàm nhập node mới
Cài đặt hàm xoay đơn/kép
Cài đặt hàm kiểm tra cân bằng
Cài đặt hàm in cây AVL (theo thứ tự duyệt)*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

// Hàm tra ve chieu cao cua node
int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Hàm tao mot node moi
Node* makeNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // node moi duoc thêm vào là node lá
    return node;
}

// Hàm tra ve giá tri lon nhat cua hai so nguyên
int max(int a, int b) {
    if(a>b ) return a;
    return b;
}
// left left
void rotatewithleft(Node*&k2) {
   
   Node*k1 = k2->left;
   k2->left = k1->right;
   k1->right = k2;
   // cap nhat chieu cao
   k2->height = max(height(k2->left),height(k2->right)) +1;
   k1 -> height = max(height(k1->left),k2->height) +1;
   k2=k1;
  
}

// right right
void rotatewithright(Node*& k2) {
    Node* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    // Cập nhật chiều cao
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->right), k2->height) + 1;

    k2 = k1;
}
//left right
void doubleRotateWithleft(Node*&k3){
    rotatewithright(k3->left);
    rotatewithleft(k3);
}
//right left
void doubleRotateWithRight(Node*&k3){
    rotatewithleft(k3->right);
    rotatewithright(k3);
}
//Hàm kiểm tra cân bằng
int test_balance(Node*t){
    if(t==NULL) return 0;
    return height(t->left)-height(t->right);
}
//Hàm thêm node
    void add_node(Node*&t,int x){
        if(t==NULL){
            t=makeNode(x);
            return;
        }
        else if(x<t->data){
            add_node(t->left,x);
        }
        else {
            add_node(t->right,x);
        }
        //cập nhật chiều cao;
        t->height=max(height(t->left),height(t->right))+1;
        //kiểm tra cân bằng
        int balance=test_balance(t);
        //cân bằng
        if(balance>1&&x<t->left->data){
           rotatewithleft(t);
        }
        else if(balance<-1&&x>t->right->data){
            rotatewithright(t);
        }
        else if(balance>1&&x>t->left->data){
             doubleRotateWithleft(t);
        }
        else if (balance<-1&&x<t->right->data){
           doubleRotateWithRight(t);
        }
       
    }
    //Hàm nhập cây AVL

    void input(Node*& head) {
    int n;
    int arr[1000];
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        add_node(head, arr[i]);
    }
}
    //Hàm in cây AVL
   void output(Node* head) {
    if (head != NULL) {
        output(head->left);
        cout << head->data << " ";
        output(head->right);
    }
}
    int main() {
    Node* head = NULL;
    input(head);
    cout << "Cay AVL : ";
    output(head);
    return 0;
}





