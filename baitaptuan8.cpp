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
    if (p == NULL) return NULL; // Kiểm tra xem có tạo được node mới không
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
        ds->last->next = p; // Kết nối node mới vào cuối danh sách
        ds->last = p;       // Cập nhật con trỏ last
    }
}

// Thêm node với hệ số và số mũ cho trước
void attachNode(List* lDT, float hs, int sm) {
    if (hs == 0) return; // Không thêm node nếu hệ số bằng 0
    Node_dt* pDT = makeNode(hs, sm);
    if (pDT == NULL) return; // Kiểm tra nếu không tạo được node mới
    addNode(lDT, pDT); // Thêm node vào danh sách
}

// Tạo đa thức
void taoDT(List* lDT) {
    float hs;
    int sm;
    int i = 0; // Đếm số phần tử
    cout << "Bắt đầu nhập đa thức (nhập hệ số 0 để kết thúc): " << endl;
    do {
        i++;
        cout << "Nhập số phần tử thứ " << i << endl;
        cout << "Nhập hệ số = ";
        cin >> hs;
        if (hs == 0) break; // Thoát khi hệ số bằng 0
        cout << "Nhập số mũ = ";
        cin >> sm;
        attachNode(lDT, hs, sm); // Thêm node vào danh sách
    } while (hs != 0);
    cout << "Kết thúc nhập" << endl;
}

// In đa thức
void inDT(List* lDT) {
    Node_dt* p = lDT->first;
    cout << endl << "f(x) = ";
    while (p != NULL) {
        if (p->heso != 0) { // Chỉ in nếu hệ số khác 0
            cout << p->heso << " * x^" << p->somu;
            if (p->next != NULL) cout << " + "; // In dấu "+" nếu không phải là phần tử cuối
        }
        p = p->next; // Di chuyển đến node tiếp theo
    }
    cout << endl;
}

int main() {
    List DT1;
    List_init(&DT1); // Khởi tạo danh sách
    taoDT(&DT1); // Tạo đa thức
    inDT(&DT1); // In đa thức
    return 0;
}
