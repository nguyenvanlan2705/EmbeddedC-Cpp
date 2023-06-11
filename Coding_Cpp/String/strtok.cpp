#include <iostream>
#include<string.h>
using namespace std;

int main() {
    char str[] = "John Doe";
    char *token = strtok(str, " ");
    
    while (token != NULL) {
        cout<< token <<"\n";
        token = strtok(NULL, " ");
    }
    
    return 0;
}