#include <iostream>
using namespace std;

// định nghĩa hàm có kiểu void và 2 tham số int
void add(int a, int b){
   cout << a+b << endl;
}

int main(){
   // khai báo một biến con trỏ hàm có kiểu void và 2 tham số int
   void (*ptr)(int, int);
   
   // gán địa chỉ của hàm add cho con trỏ ptr
   ptr = &add;
   
   // sử dụng function pointer để gọi hàm add
   (*ptr)(2, 3);

   return 0;
}
