#include <iostream>
using namespace std;

class Rectangle {
    private:
        int width;
        int height;
    public:
        // The constructor
        // Rectangle(){} //Default constructor
        Rectangle(int w, int h) { //Parameterized constructor
            width = w;
            height = h;
            cout << "A new Rectangle has been created." << endl;
        }
        // The destructor
        ~Rectangle() {
            cout << "The Rectangle has been destroyed." << endl;
        }
        // A method to calculate the area of the rectangle
        int area() {
            return width * height;
        }
};

int main() {
    // Create a new Rectangle object using the constructor
    Rectangle rect(5, 7); //Parameterized constructor
    // Call the area method to calculate the area of the rectangle
    int area = rect.area();
    cout << "The area of the rectangle is: " << area << endl;
    // The destructor will be called automatically when the object goes out of scope
    return 0;
}
