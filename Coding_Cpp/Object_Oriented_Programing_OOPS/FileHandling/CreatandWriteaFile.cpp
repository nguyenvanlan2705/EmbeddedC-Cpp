#include <fstream>
using namespace std;

int main()
{
    ofstream myFile("test.txt"); // tạo ra 1 file
    myFile<<"Nguyen Van Lan 27/05/2001"<<endl; // viết vào file
    myFile.close();// đóng file nên ko thể viết thêm vào đc
    myFile<<"Nguyen Van Lan 27/05/2001"<<endl;
    myFile.open("test.txt", ios::app);
    myFile<<"Nguyen Van Lan 27/05/2001"<<endl;
}