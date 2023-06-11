#include <iostream>
using namespace std;

class outerClass
{
private:
    string name;
    int age;

public:
    class innerClass
    {
    private:
        /* data */
    public:
        void setNameandAge(outerClass &o, string name, int age)
        {
            o.name=name;
            o.age= age;
        }
        string getName(outerClass &o)
        {
            return o.name;
        }
        int getAge(outerClass &o)
        {
            return o.age;
        }
    };
};

int main()
{
    outerClass out;
    outerClass::innerClass in;
    in.setNameandAge(out, "Lan", 22);
    cout<<in.getName(out)<<" "<<in.getAge(out);
}