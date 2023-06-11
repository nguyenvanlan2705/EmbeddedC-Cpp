#include <iostream>
using namespace std;
class comPlex
{
private:
    int real;
    int img;

public:
    comPlex(int, int);
    void display()
    {
        cout << real << "+ i" << img;
    }
    friend comPlex operator+(comPlex c1, comPlex c2);
};
comPlex::comPlex(int r = 0, int i = 0)
{
    this->real = r;
    this->img = i;
};
comPlex operator+(comPlex c1, comPlex c2)
{
    comPlex t;
    t.real = c1.real + c2.real;
    t.img = c1.img + c2.img;
    return t;
};

int main()
{
    comPlex c1(3, 5), c2(5, 6), c3;
    c3 = c1 + c2;
    c3.display();
}
