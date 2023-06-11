#include <iostream>
using namespace std;

float a[]={1,3,5.3,5.69,8,7};
int main()
{
    for(auto x:a) //auto: tự động in ra tất cả giá trị không phụ thuộc vào kiểu dữ liệu
    // auto x:a có nghĩa là với mỗi giá trị của x tương ứng trong a[]
    // không phụ thuộc vào kích thước của mảng
    {
        cout<<x<<endl; 
       /*in ra 
        x= 1
        x= 3   
        x= 5.3 
        x= 5.69
        x= 8   
        x=7*/
    }
}