#include <iostream>
using namespace std;
class Complex_mulTiple
{
private:
    /* data */
public:
    int real;
    int img;
    Complex_mulTiple multi(Complex_mulTiple m)
    {
        Complex_mulTiple temp;
        temp.real = (this->real*m.real) - this->img* m.img;
        temp.img = this-> real* m.img + this->img* m.real;
        return temp;
    }
};

int main()
{
    Complex_mulTiple m1,m2,m3;
    m1.real=10;
    m1.img= 8;
    m2.real=4;
    m2.img= 6;

    m3=m1.multi(m2);
    cout<< m3.real << "+ i"<<m3.img;
}
