#include <iostream>
using namespace std;
class Myclass
{
public:
    Myclass();
    static int myNum;
    static void myMethod(/* args */);
};
Myclass::Myclass()
{
    cout<<"My name is ";
}
int Myclass::myNum=27052001;
void Myclass::myMethod(){
    cout<<"Lan";
}
int main()
{
    cout << Myclass::myNum << endl;
    Myclass Myclass;
    Myclass::myMethod();
    return 0;
}