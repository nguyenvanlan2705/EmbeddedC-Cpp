#include <iostream>

// Khai báo template function sum
template <class T>
T sum(T a, T b)
{
    return a + b;
}
int main()
{
    // Sử dụng template function sum
    std::cout << sum(1, 2) << std::endl; // Output: 3
    std::cout << sum(1.5, 2.7) << std::endl; // Output: 4.2
    return 0;
}
