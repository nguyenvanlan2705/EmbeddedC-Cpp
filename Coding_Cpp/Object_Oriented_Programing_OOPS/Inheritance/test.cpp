#include <iostream>
using namespace std;

class test_base
{
private:
    int age;
    string name;

public:
    test_base();
    test_base(int age, string name);
};
test_base::test_base()
{
    cout << "Hi im Lan" << endl;
}
test_base::test_base(int age, string name)
{
    this->name = name;
    this->age = age;
}

class test_derived : public test_base
{
private:
    string htown;

public:
    test_derived();
    test_derived(int age, string name, string htown) : test_base(age, name)
    {
        this->htown=htown;
        cout<<"My name is "<<name<<endl;
        cout<<"Im "<<age<<endl;
        cout<<"My home town is "<<htown<<endl;
    }
};
test_derived::test_derived()
{
    cout << "Im 22 years old";
}

int main()
{
    test_derived t;
}