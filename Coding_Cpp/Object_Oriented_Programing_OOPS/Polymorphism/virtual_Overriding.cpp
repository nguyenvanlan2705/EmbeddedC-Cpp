#include <iostream>
using namespace std;
class Shape
{
public:
    virtual void draw()
    {
        cout << "Ve 1 hinh dang" << endl;
    }
};
class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Ve 1 hinh tron" << endl;
    }
};

class Square : public Shape
{
public:
    void draw() override
    {
        cout << "Ve mot hinh vuong" << endl;
    }
};
int main()
{
    Shape *obj1 = new Circle();
    Shape *obj2 = new Square();

    obj1->draw();
    obj2->draw();

    delete obj1;
    delete obj2;

    return 0;
}
