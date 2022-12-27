#include <iostream>

class Complex {
    public:
        float real, img;
        Complex() { real = img = 0; }

        Complex operator + (Complex &c2);
        Complex operator * (Complex &c2);
        friend std::istream &operator >> (std::istream &in, Complex &c2);
        friend std::ostream &operator << (std::ostream &out, Complex &c2);
};

int main() {
    Complex c1, c2;
    static Complex c3, c4;
    std::cin >> c1 >> c2;
    c3 = c1 + c2;
    c4 = c1 * c2;
    std::cout << std::endl << c3 << std::endl << c4;
    return 0;
}

Complex Complex :: operator + (Complex &c2) {
    Complex temp;
    temp.real = real + c2.real;
    temp.img = img + c2.img;
    return temp;
}

Complex Complex :: operator * (Complex &c2) {
    Complex temp;
    temp.real = (real * c2.real) - (img * c2.img);
    temp.img = (real * c2.img) + (img * c2.real);
    return temp;
}

std::istream &operator >> (std::istream &in, Complex &c2) {
    std::cout << "Enter the real and img part of the complex number: ";
    return in >> c2.real >> c2.img;
}

std::ostream &operator << (std::ostream &out, Complex &c2) {
    return out << c2.real << "+" << c2.img << "i" << std::endl;
}