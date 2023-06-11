#include <iostream>
using namespace std;
class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom)
    {
        numerator = num;
        denominator = denom;
    }

    friend ostream &operator<<(ostream &os, const Fraction &f)
    {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
};
int main()
{
    Fraction frac(1, 2);
    cout << "The value of frac is: " << frac << endl;
}
