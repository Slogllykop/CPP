#include<iostream>
using namespace std;
class complex
{
    private:
        int real,img;
    public:
    complex();
    complex operator + (complex c1);
    complex operator * (complex c2);
    friend void operator>>(istream &cin , complex &c1)
    {
        cout<<"enter the compleX number :";
        
        cout<<"enter the real part ";
        cin>>c1.real;
        cout<<"enter the imaginary part ";
        cin>>c1.img;
    }
    friend void operator<<(ostream &cout , complex &c1)
    {
        cout<<"\n"<<c1.real<<"+"<<c1.img<<"i";
    }
};
complex::complex()
{
    real=0; 
    img=0;
}
complex complex::operator +(complex c2)
{
    complex c3;
    c3.real=real+c2.real;
    c3.img=img+c2.img;
    return c3;
}
complex complex::operator*(complex c2)
{
    complex c3;
    c3.real=(real*c2.real)-(img*c2.img);
    c3.img=(real*c2.img)+(img*c2.real);
    return c3;
}
int main()
{
    int c1,c2,c3,c4;
    cin>>c1;
    cin>>c2;
    c3=c1+c2;
    c4=c1*c2;
    cout<<"\nAddition is : "<<c3;
    cout<<"\nMultiplication is : "<<c4;
    return 0;
}