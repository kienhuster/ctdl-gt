/*Cài đặt danh sách móc nối để nhập và in một đa thức với phương thức cấp phát động tối ưu 
Có kiểm tra điều kiện nhập hệ số bằng 0 thì sẽ giải phóng cấp phát phần tử và không liên kết vào hàm tạo đa thức 
submit lên git và chụp ảnh kết quả chạy trên màn hình 
*/
#include <iostream>
using namespace std;

struct Node_dt {
    float heso;      // Hệ số đa thức
    int somu;        // Số mũ của đa thức
    Node_dt* next;   // Con trỏ trỏ tới phần tử tiếp theo
};

struct List {
    Node_dt* first;  // Con trỏ đến phần tử đầu tiên
    Node_dt* last;   // Con trỏ đến phần tử cuối cùng
};

// Khởi tạo danh sách
void List_init(List* danhsach) {
    danhsach->first = danhsach->last = NULL; // Danh sách rỗng
}

// Tạo một node mới
Node_dt* makeNode(float hs, int sm) {
    Node_dt* p = new Node_dt; // Gán địa chỉ của một node mới cho p
    if (p == NULL) return NULL; 
    p->heso = hs;
    p->somu = sm;
    p->next = NULL;
    return p; // Trả về con trỏ p trỏ đến node được tạo
}

// Thêm node vào danh sách
void addNode(List* ds, Node_dt* p) {
    if (ds->first == NULL) {   // Danh sách rỗng
        ds->first = ds->last = p; // Con trỏ đầu tiên và con trỏ cuối cùng đều trỏ đến node mới p
    } else {
        ds->last->next = p; // Gán địa chỉ node cuối bằng p
        ds->last = p;       // Chuyển p thành node cuối
    }
}

// Thêm node với hệ số và số mũ cho trước
void attachNode(List* l_DT, float hs, int sm) {
    
    Node_dt* p_DT = makeNode(hs, sm);// con trỏ p_DT trỏ vào Node mới đc tạo trong hàm makeNode
    if (p_DT == NULL) return; 
    addNode(l_DT, p_DT); // khai báo hàm thêm node vào danh sách
}

// Tạo đa thức
void create_DT(List* lDT) {
    float hs;
    int sm;
    int i = 0; 
    cout << "               Hay nhap da thuc " << endl;
    cout<<"Luu y: neu nhap he so bang 0 chuong trinh se ket thuc! "<<endl;
    do {
        i++;
        cout << "Nhap phan tu " << i << endl;
        cout << "Nhap he so = ";
        cin >> hs;
        if (hs == 0) break; // Thoát khỏi vòng lặp khi hệ số bằng 0
        cout << "Nhap so mu = ";
        cin >> sm;
        attachNode(lDT, hs, sm); // Thêm node vào danh sách
    } while (hs != 0); 
    cout << "Ket thuc nhap" << endl;
}

// In đa thức
void print_DT(List* lDT) {
    Node_dt* p = lDT->first;//con trỏ p trỏ đến phần tử đầu(node đầu)
    cout << endl << "f(x) = ";
    while (p != NULL) {
        if (p->heso != 0) { 
            cout << p->heso << " . x^" << p->somu;
            if (p->next != NULL) cout << " + "; // In dấu "+" nếu không phải là phần tử cuối
        }
        p = p->next; // Di chuyển đến node tiếp theo
    }
    cout << endl;
}

int main() {
    List DT;
    List_init(&DT); // Khai báo hàm khởi tạo danh sách
    create_DT(&DT); // Khai báo hàm ạo đa thức
    print_DT(&DT); // khai báo hàm in đa thức
    return 0; 
}
