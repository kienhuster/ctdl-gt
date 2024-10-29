/*Cài đặt danh sách quản lý danh sách quản lý dân số, 
để tìm số năm có cùng số lượng người sinh ra,
in ra các năm có số lượng người sinh ra là lớn nhất và bé nhất 
*/
#include<iostream>
using namespace std;

struct danso {
    int luongnguoi[50];
    int nam[50];
};

struct danso danSO;


void nhapdanhsach(int n) {
    cout << "Nhap danh sach nam va luong nguoi tuong ung :" << endl;
    for (int i = 0; i < n; i++) {
        cin >>danSO.nam[i]>> danSO.luongnguoi[i]  ;
    }
}


void danhsach(int n) {
    cout << "         Danh sach         " << endl;
    cout<<" Nam "<<"    "<<" Luong nguoi "<<endl;
    for (int i = 0; i < n; i++) {
        cout <<danSO.nam[i]<<"   " << danSO.luongnguoi[i] << endl;
    }
}


int main() {
    nhapdanhsach(50);  
    danhsach(50);
    int min=0;
    int max=0;
    for(int j=1;j<3;j++){
        if(danSO.luongnguoi[min]>danSO.luongnguoi[j]){
            min=j;
        }
        }
   for(int i=1;i<3;i++){
        if(danSO.luongnguoi[max]<danSO.luongnguoi[i]){
           max=i;
        }
    }
    cout <<" nam co so nguoi it nhat: " << danSO.nam[min]<< endl;
    cout<< " nam co so nguoi nhieu nhat: " << danSO.nam[max]<<endl;
    return 0;
}
