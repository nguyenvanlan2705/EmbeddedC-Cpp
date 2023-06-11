#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
string myText;
int main()
{
    ifstream inFile("test.txt");
    while (getline(inFile, myText))
    {
        cout << myText;
    }
}