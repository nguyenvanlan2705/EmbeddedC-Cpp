#include <iostream>
using namespace std;
class Rectangle
{
private: // data hiring
    int length;
    int breadth;

public:
    void setLenght(int l) // Accessor
    {
        this->length = l;
    }
    int getLength() // Mutator
    {
        return this->length;
    }
    void setBreadth(int b)
    {
        this->breadth = b;
    }
    int getBreadth()
    {
        return this->breadth;
    }
    int area()
    {
        return length * breadth;
    }
    int perimeter()
    {
        return 2 * (length + breadth);
    }
};
int main()
{
    Rectangle *r = new Rectangle;
    r->setLenght(10);
    r->setBreadth(20);
    cout << r->area();
}
