#include <iostream>
using namespace std;
// Lớp cha (base class)
class Person {
public:
    std::string name;
    int age;
};

// Lớp con (derived class)
class Student : public Person {
public:
    int grade;
    void printInfo() {
        std::cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << std::endl;
    }
};
int main()
{
    Student std1;
    std1.name = "Lan";
    std1. age = 22;
    std1.grade =10;
    std1.printInfo();
}