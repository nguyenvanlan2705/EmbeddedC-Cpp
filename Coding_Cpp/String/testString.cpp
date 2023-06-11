#include <iostream>
#include<string.h>
using namespace std;
int main()
{
    char name[20];
    char s[]= "2345";
    string p;
    int a;
    cout << "Enter your name: ";
    cin.getline(name, 20);
    cout << "Your name is: " << name << endl;
    cout << strlen(name);
    cout<<p;
    a= strtol(s, NULL,10);
    cout <<a ;
    return 0;
}