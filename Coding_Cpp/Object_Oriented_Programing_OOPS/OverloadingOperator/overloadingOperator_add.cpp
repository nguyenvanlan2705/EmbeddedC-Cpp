#include <iostream>
using namespace std;

class comPlex
{
private:
    /* data */
public:
    int real;
    int img;
    comPlex /*tham số thứ nhất".""*/add(comPlex n /*Tham số thứ 2(c2)*/)
    {
        comPlex temp;
        temp.real        /*giá trị phần thực của kết quả cần tìm (c3)*/
            = this->real /*giá trị phần thực của tham số thứ nhất(c1)*/
              + n.real;  /*giá trị phần thực của tham số thứ nhất(c1)*/
        temp.img         /*giá trị phần ảo của kết quả cần tìm (c3)*/
            = this->img  /*giá trị phần ảo của tham số thứ hai(c2)*/
              + n.img;   /*giá trị phần ảo của tham số thứ hai(c2)*/
        return temp;
    }
};

int main()
{
    comPlex c1, c2, c3;
    c1.real = 5;
    c1.img = 10;
    c2.real = 3;
    c2.img = 4;
    c3 = c1.add(c2); /*c3=c1+c2*/
    cout << c3.real << "+" << c3.img << "i" << endl;
}
