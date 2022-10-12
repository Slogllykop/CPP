#include <iostream>
#include <conio.h>

namespace inp{
    long int input(std::string s){
        long int a;
        std::cout<<s;
        std::cin>>a;
        return a;
    }
}

class clac {
    public:
        bool isDivisible(long int, long int);
};

bool clac::isDivisible(long int a, long int b){
    return a % b == 0;
}

int main(){
    clac C;

    long int first = inp::input("What is the first number: ");
    long int second = inp::input("What is the second number: ");

    std::cout<<(C.isDivisible(first, second) ? "Is Divisible" : "Not Divisible");

    getch();
    return 0;
}