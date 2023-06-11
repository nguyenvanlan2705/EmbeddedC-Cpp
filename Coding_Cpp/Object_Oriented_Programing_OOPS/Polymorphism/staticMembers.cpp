#include <iostream>
using namespace std;

class staticMembers
{
private:
    /* data */
public:
    static int count;
    staticMembers()
    {
        count ++;
    }
    static int getCount()
    {
        return count;
    }
};
int staticMembers:: count=0;

int main()
{

    staticMembers t1,t2,t3;
    cout<<staticMembers::count<<endl;
    cout<<staticMembers::getCount();
}