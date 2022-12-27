// Implement a class Complex which represents the Complex
// Number data type. Implement the following
// 1. Constructor (including a default constructor which creates the complex number 0+0i).
// 2. Overload operator+ to add two complex numbers.
// 3. Overload operator* to multiply two complex numbers.
// 4. Overload operators << and >> to print and read Complex Numbers.

#include<iostream>
using namespace std;
class Complex
{
    public:
        float real, img;
        Complex() { real = img = 0; }
        Complex operator + (Complex &c2);
        Complex operator * (Complex &c2);
        friend istream &operator >> (istream &in, Complex &c2);
        friend ostream &operator << (ostream &out, Complex &c2);
};

Complex Complex :: operator + (Complex &c2)
{
    Complex temp;
    temp.real = real + c2.real;
    temp.img = img + c2.img;
    return temp;
}

Complex Complex :: operator * (Complex &c2)
{
    Complex temp;
    temp.real = (real*c2.real)-(img*c2.img);
    temp.img = (real*c2.img)+(img*c2.img);
    return temp;
}

istream &operator >> (istream &in, Complex &c2)
{
    cout << "Enter real and imaginary part of the complex number :";
    return in >> c2.real >> c2.img;
}

ostream &operator << (ostream &out, Complex &c2)
{
    return out << c2.real << "+" << c2.img << "i" << endl;
}

int main()
{
    Complex c1, c2, c3;
    cin >> c1 >> c2;
    c3 = c1 + c2;
    cout << "\nThe sum is : " << c3;
    c3 = c1 * c2;
    cout << "The product is : " << c3;
    return 0;
}
