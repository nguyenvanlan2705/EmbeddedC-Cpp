#include <iostream>
using namespace std;
int n, rev=0,r;
int main()
{
    cin>>n;
    while (n>0)
    {
        r=n%10;
        n/=10;
        rev=rev*10+r;
    }
    cout<<rev;
    return 0;
}   