#include <iostream>
#include <conio.h>

class two{
    public:
        int input2()
};

class one:public two{
    public:
        int input1();
};

int two::input2(){
    int b;
    std::cout<<"Enter the 2nd number: ";
    std::cin>>b;
    return b;
}

int one::input1(){
    int a;
    std::cout<<"Enter the 1st number: ";
    std::cin>>a;
    return a;
}

int Divisible(int a, int b) {
    return (((a%b)==0)? 1:0);
}

int main(){ 
    one A;
    std::cout<<((Divisible(A.input1(),A.input2())==0)? "Not divisible":"Divisible");

    getch();
    return 0;
}