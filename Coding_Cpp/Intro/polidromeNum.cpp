/*amstrong là số có tổng = tổng lập phương các chữ số trong số*/
#include <iostream>
using namespace std;
int n,m, sum=0,r;
int main()
{
    cin>>n;
    m=n;
    while (n>0)
    {
        r=n%10;
        n/=10;
        sum=sum*10+r;
    }
    if(sum==m) cout<<"Polidrome";
    else cout<<"Not polidrome";
    return 0;
}   