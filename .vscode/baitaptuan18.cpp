/*Viết chương trình cài đặt đồ thị cho như trên bảng theo hai cấu trúc lưu trữ 
Sử dụng ma trận lân cận -> nhập thông tin đồ thị 
Sử dụng danh sách lân cận  -> nhập thông tin đồ thị 
Duyệt đồ thị và in thứ tự các đỉnh theo 2 cách duyệt (BFS, DFS)*/
#include <iostream>
using namespace std;


// So dinh
int n;

// Cau truc danh sach ke
struct Node {
    int data;
    Node* next;
};

// Khoi tao danh sach ke
Node* Dsach_ke[100];

// Ham tao nut moi
Node* createNode(int v) {
    Node* newNode = new Node;
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}



// Khoi tao danh sach ke
void taodanhsachke() {
    for (int i = 0; i < n; i++) {
        Dsach_ke[i] = NULL;
    }
}

// Them canh vao danh sach ke
void themdanhsachke(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = Dsach_ke[u];
    Dsach_ke[u] = newNode;

    newNode = createNode(u);
    newNode->next = Dsach_ke[v];
    Dsach_ke[v] = newNode;
}

// Ham chinh
int main() {
    cout << "Nhap so dinh: ";
    cin >> n;
    taodanhsachke();

    int m;
    cout << "Nhap so canh: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Nhap canh " << i + 1 << ": ";
        cin >> u >> v;

        
        themdanhsachke(u, v);
    }
    // In danh sach ke
    cout << "\nDanh sach ke:\n";
    for (int i = 1; i < n; i++) {
        cout << "Dinh " << i << ": ";
        Node* temp = Dsach_ke[i];
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}