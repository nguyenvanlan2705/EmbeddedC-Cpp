#include <iostream>
using namespace std;

class outerClass
{
public:
    class nestedClass
    {
    private:
        string name;
        int age;

    public:
        void setNameandAge( string name, int age)
        {
            this->name = name;
            this->age = age;
        }
        string getName()
        {
            return name;
        }
        int getAge()
        {
            return age;
        }
    };
};

int main()
{
    outerClass out;
    outerClass::nestedClass in;
    in.setNameandAge( "Lan", 22);
    cout << in.getName() << " " << in.getAge();
}