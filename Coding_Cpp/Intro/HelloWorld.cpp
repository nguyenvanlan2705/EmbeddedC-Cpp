#include <iostream>

using namespace std;
int n,s=0;
int i;
int main()
{
    cout<<"hi";
    cin>>n;
    for( i=1; i<=n; i++)
    {
        if(n%i==0) s+=i;
    }
    cout<<s<<endl;
    if(2*n==s) cout<<"perfect no";
    else cout<<"not";
    return 0;
}