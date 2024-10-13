#include<iostream>
#include<string>
using namespace std;
int  mahoa1(const std::string& color) {
    
    if (color == "do") {
        return 0;  // "d?" du?c mã hóa thành 0
    }
    else if (color == "xanh") {
        return 1; 
     } // "vàng" du?c mã hóa thành 1
    else if( color == "trang"){
        return 2;
    }
    
}
std::string mahoa2(int number) {
    
      if (number == 0) {
        return "do";   // 0 du?c gi?i mã thành "d?"
    } else if (number == 1) {
        return "trang"; } // 1 du?c gi?i mã thành "vàng"
    else if (number == 2){ 
        return "xanh";}
    
}
        
   

 void arrange(int n,int arr[]){
    for (int i=1;i<n;i++){
        int x = arr[i];
        int j=i;
        while( j>0 && arr[j-1]>x){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=x;
    }
 }
 

int main(){
    std::string color[]{"xanh", "do", "xanh", "do", "do", "trang", "do", "xanh", "trang"};
   
    int daymahoa[10];
    for(int i=0;i<9;i++ ){
        daymahoa[i]=mahoa1(color[i]);
    }
    arrange(9,daymahoa);
    
    string daymau[10];
     for(int i=0;i<9;i++ ){
        daymau[i]=mahoa2(daymahoa[i]);
    }
    for(int i=0;i<9;i++ ){
       cout<< daymau[i]<<" ";
    }
    return 0;

}		
	

