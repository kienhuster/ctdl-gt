/*
Bài 2:  Một câu tiếng việt cấu thành từ nhiều từ khác nhau. Mỗi từ được lưu thành một node trong một danh sách liên kết đơn  

1.Khai báo cấu trúc danh sách liên kết. Các thông tin chứa ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung sau được thực hiện. 
2.Xác định từ xuất hiện nhiều nhất trong câu  
3.Nếu xuất hiện từ láy (cấu thành từ hai từ giống nhau ví dụ: xanh xanh), thực hiện loại bỏ một từ .
4.Thực hiện đếm số từ vựng xuất hiện trong câu. 
*/
#include<iostream>
#include<string>
using namespace std;
struct node_tu {
  string tu;
  node_tu*next;
};
struct Cau{
    node_tu*head;
};
void cauTiengViet(Cau*Tu){
    Tu->head=NULL;
}
//Tao từ 
node_tu*tao_tu(string tuMoi){
    node_tu*tu_moi= new node_tu();
    if(tu_moi=NULL) return NULL;
    tu_moi->tu=tuMoi;
    tu_moi->next=NULL;
    return tu_moi;
}
// Hàm tạo câu theo trình tự từ từ nhập trước sẽ ở vị trí trước từ nhập sau
void tao_cau(Cau*Tu,string tuMoi){
    node_tu*tu_moi= tao_tu(tuMoi);
    node_tu*temp=Tu->head;
    if(Tu->head==NULL){
        Tu->head=tu_moi;
        return;
    }
    while(temp!=NULL){
        temp=temp->next;
    }
    temp->next=tu_moi;
}    
//Hàm nhap tu 
void nhap_tu(Cau*Tu){
    string tumoi;
   while(cin>>tumoi ){
    if(tumoi==" ") break;
    tao_cau(Tu,tumoi);
   }
}
// Hàm tìm từ xuất hiện nhiều nhất
void tim_tu_xuat_hien_nhieu_nhat(Cau*Tu){
node_tu* temp1 = Tu->head;
    string tu_nhieu_nhat;
    int max_count = 0;

    while (temp1 != NULL) {
        int count = 1;
        node_tu* temp2 = temp1->next;
        while (temp2 != NULL) {
            if (temp1->tu == temp2->tu) {
                count++;
            }
            temp2 = temp2->next;
        }
        if (count > max_count) {
            max_count = count;
            tu_nhieu_nhat = temp1->tu;
        }
        temp1 = temp1->next;
    }

    if (max_count > 1) {
        cout << "Tu xuat hien nhieu nhat: " << tu_nhieu_nhat << " (" << max_count << " lan )" << endl;
    } else {
        cout << "Moi tu chi xuat hien mot lan." << endl;
    }
}
//Hàm loại bỏ từ xuất hiện nhiều nhất
void loai_bo_tu_lay(Cau* cau) {
    node_tu* temp = cau->head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->tu == temp->next->tu) {
            node_tu* tu_lay = temp->next;
            temp->next = tu_lay->next;
            delete tu_lay;
        } else {
            temp = temp->next;
        }
    }
}




