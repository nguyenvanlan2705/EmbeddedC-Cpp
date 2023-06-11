#include <iostream>
using namespace std;

int a[]={1,3,53,5,6,9,8,7};
int l=0, h=8;
int key, mid;
int main()
{
    cin>>key;
    while(l<=h)
    {
        mid= (h+l)/2;
        if(key==a[mid]) {
            cout<<"Found at "<<mid;
            return 0;
        }
        else if(key < a[mid]) h=mid-1;
        else l=mid+1;
    }
    cout<<"Not Found ";
}