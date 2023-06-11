#include <iostream>
using namespace std;

class Rectangle
{
private:
    int lenght;
    int breadth;

public:
    void getLength(int lenght)
    {
        this->lenght = lenght;
    }
    void getBreadth(int breadth)
    {
        this->breadth = breadth;
    }
    int area()
    {
        return lenght * breadth;
    }
    int perimeter()
    {
        return 2 * (lenght * breadth);
    }
};

int main()
{
    Rectangle r;
    r.getLength(10);
    r.getBreadth(6);
    cout << r.area();
}