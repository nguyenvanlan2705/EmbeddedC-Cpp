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
        sum=sum+r*r*r;
    }
    if(sum==m) cout<<"Amstrong";
    else cout<<"Not Amstrong";
    return 0;
}   