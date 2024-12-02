/*Trong siêu thị người ta xếp hàng để thực hiện thanh toán. Mỗi giỏ hàng với các hàng hoá được coi như một node trong một cấu trúc hàng đợi.  

Khai báo cấu trúc hàng đợi. Các thông tin chứa ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung sau được thực hiện 
Loại bỏ từng người ra khỏi hàng đợi sau khi người đó đã thực hiện thanh toán xong 
Tính tổng số tiền mà thu ngân thu được tại quầy trong một phiên làm việc  
Xác định số lượng một sản phẩm A đã được bán tại quầy thu ngân  */
#include<iostream>
#include<string>
using namespace std;
struct products{
    string sanpham, khachhang;
    int money, soluong_sp;

};
struct gio_hang{
    products hang;
    gio_hang*next;
};
struct Queue{
   gio_hang*head;
};
// tạo node
gio_hang*makenode(products x){
    gio_hang*newnode=new gio_hang();
    newnode->hang=x;
    newnode->next=NULL;
    return newnode;
}

// khởi tạo hàng đợi
void Init(Queue*Hang){
    Hang->head=NULL;
}
// kiểm trang hàng rỗng
bool Empty(Queue *Hang){
    return Hang->head== NULL ;
}
// Thêm thông tin khách hàng vào hàng đợi
void Push_info(Queue*Hang, products x){
    gio_hang*newnode= makenode(x);
    if(Empty(Hang)){
        Hang->head=newnode;
        return;
    }
    gio_hang*temp=Hang->head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
// Xóa thông tin khách hàng ra khỏi hàng đợi
products Pop_infor(Queue* Hang){
    if(Empty(Hang))
    {
        gio_hang*temp=Hang->head;
        Hang->head = temp->next;
        delete temp;
        return temp->hang;
    }
}
// Nhap thong tin
void nhap_thong_tin(Queue,int n){
     cout<<"Ten: "; cin>> Hang->khachhang;     
    for(int i=0;i<n;i++){
        cout<<"  San pham thu"<<i+1<<": "; cin>>Hang[i].sanpham;
        
        cout<<" So luong: "; cin>>Hang[i].soluong_sp;
        cout<<" Don gia: "; cin>>Hang[i].money;
        
    }
    
}    
//Hàm xử lý thanh toán
void xu_ly_thanhtoan(Queue* Hang) {
    if (!Empty(Hang)) {
        products x = Pop_infor(Hang);  // Loại bỏ khách hàng đã thanh toán
        cout << "Khach hang: " << x.khachhang << " thanh toan xong, san pham: " << x.sanpham << endl;
    } else {
        cout << "Hang doi rong, khong co khach hang de thanh toan!" << endl;
    }
}
//In hóa đơn
void in_hoa_don(products *Hang,int n){
    cout<<"Hoa don"<<endl;
    cout<<"Ten khach hang: "<<Hang->khachhang<<endl;
    cout<<"San pham  "<<"So luong   "<<"Don gia    "<< "Thanh tien"<<endl;
    int thanhtoan =0;
    for(int i=0;i<n;i++){
        int thanhtien=Hang[i].soluong_sp * Hang[i].money;
        cout<<Hang[i].sanpham<<"  "<<Hang[i].soluong_sp<<"  "<<Hang[i].money<<"  "<< thanhtien<<endl ;
        thanhtoan+=thanhtien;
    }
    cout<<"Tong thanh toan"<<thanhtoan;
}
//tinh tong tien thu duoc
int tong_tien(Queue*Hang){
    int total=0;
    gio_hang*temp=Hang->head;
    while(temp!=NULL){
    total=temp->hang.soluong_sp*temp->hang.money;
    temp=temp->next;
    }
    return total;
}
//Thong ke so luong san pham
int thongke(Queue*Hang, string ten_sanpham){
    
    gio_hang*temp=Hang->head;
    int tong =0;
    while(temp!=NULL){
       if (temp->hang.sanpham == ten_sanpham) {
            tong += temp->hang.soluong_sp;
        }
        temp=temp->next;
    }
    return tong;
}
int main(){
   

}
