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
    Rectangle r1, r2;
    r1.lenght=10;
    r1.breadth=5;
    int s1= r1.area();
    cout<<s1<<endl;
    r2.lenght=10;
    r2.breadth=15;
    int s2= r2.perimeter();
    cout<<s2<<endl;
    return 0;
}

