#include <iostream>
#include <utility>

class Person {
   public:
    std::string name;
    int age;

    // Default constructor
    Person() : name(""), age(0) {}

    // Parameterized constructor
    Person(std::string name, int age) : name(name), age(age) {}

    // Copy constructor
    Person(const Person& other) : name(other.name), age(other.age) {}

    // Move constructor
    Person(Person&& other) noexcept : name(std::move(other.name)), age(std::move(other.age)) {}

    ~Person(){};
};

int main() {
    // Create a new person object using parameterized constructor
    Person person1("Alice", 25);

    // Move the person object using move constructor
    Person person2 = std::move(person1);

    // Print out the details of both persons
    std::cout << "Person 1: " << person1.name << ", " << person1.age << std::endl;
    std::cout << "Person 2: " << person2.name << ", " << person2.age << std::endl;

    return 0;
}
