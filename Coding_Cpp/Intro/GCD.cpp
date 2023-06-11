#include <iostream>
using namespace std;
int n,m;
int main()
{
    cin>>n>>m;
    while(m!=n)
    {
        if(m>n) m-=n;
        else n-=m;
    }
    cout<<"GCD is "<< m;
    return 0;
}