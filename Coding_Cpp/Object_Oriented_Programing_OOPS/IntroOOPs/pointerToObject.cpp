#include <iostream>
using namespace std;

class Rectangle
{
private:
    
public:
    int lenght;
    int breadth;
    int area(){
        return lenght*breadth;
    }
    int perimeter(){
        return 2*(lenght*breadth);
    }
};
// Rectangle::Rectangle(/* args */)
// {
// }
int main()
{
    // Rectangle r; // lưu trong stack
    // Rectangle *p;
    // p=&r;
    // r.lenght=10; 
    Rectangle *p= new Rectangle(); // lưu trong heap
    p->lenght=10;
    p->breadth=5;
    cout<<p->area();
    return 0;
}

