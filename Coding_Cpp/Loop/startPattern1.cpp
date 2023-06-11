#include <iostream>
using namespace std;
void Draw(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i+j<=n-1)
                cout<<"* ";
            else
                cout<<"  ";
        }
        cout<<endl;
    }
    //Draw Pattern given in description for n x n dimensions
}
int main()
{
    Draw(5);
    int *p= new int[5];
}