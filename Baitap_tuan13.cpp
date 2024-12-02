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
void nhap_thong_tin(products &Hang){
     
    
}
void in_hoa_don(products &Hang){
    cout<<Hang.khachhang <<Hang.sanpham<<Hang.soluong_sp<<Hang.money;
}

int main(){
    Queue Hang;
    cout<<"Nhap thong tin"<<endl;
    nhap_thong_tin(&Hang);
    cout<<"Hoa don";
    in_hoa_don(&Hang);

}
