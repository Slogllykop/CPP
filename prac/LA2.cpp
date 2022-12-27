// Develop a program in C++ to create a database of student’s
// information system containing the following information:
// Name, Roll number, Class, Division, Date of Birth, Blood
// group, Contact address, Telephone number, Driving license
// no. and other. Construct the database with suitable member
// functions. Make use of constructor, default constructor, copy
// constructor,
// destructor, static member functions, friend class, this pointer,
// inline code and dynamic memory allocation operators-new and
// delete as well as exception handling.

#include<iostream>            
#include<string.h>            
using namespace std;            
#define max 100;

class per_info{
    string lic, dob, bldgrp;    
    public:
    per_info();                
    per_info(per_info &);      
    ~per_info() { cout<<"\nDESTRUCTOR IS CALLED!!!!!"<<endl<<"RECORD DELETED SUCCESSFULLY"<<endl; }

    friend class student;                    
};

class student{
    string name, address, year;                
    char divi;
    int roll_no;
    long mob;
    static int cnt;                        
    public:
    void create(per_info &);                
    void display(per_info &);            

    inline static void inccnt() { cnt++; }

    inline static void showcnt() { cout<<"\nTOTAL NO OF RECORDS ARE : "<<cnt; }

    student();                          
    student(student &);                
    ~student() { cout<<"\nDESTRUCTOR IS CALLED!!!"<<endl<<"RECORD DELETED SUCCESSFULLY"<<endl; }
};

int student::cnt;              
student::student()                
{
    name="ANAGHA";
    address="PUNE";
    year="2";
    divi='A';
    roll_no=42;
    mob=942329999;
}
per_info::per_info(){
    lic="4676745656";
    dob="02/11/2002";
    bldgrp="A-";
}

student::student(student &obj){
    this->name=obj.name;            
    this->address=obj.address;
    this->year=obj.year;
    this->divi=obj.divi;
    this->roll_no=obj.roll_no;
    this->mob=obj.mob;
}
per_info::per_info(per_info &obj){
    lic=obj.lic;
    dob=obj.dob;
    bldgrp=obj.bldgrp;
}

void student::create(per_info &obj){
    cout<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"NAME: "; cin>>name;
    cout<<"ADDRESS: "; cin>>address;
    cout<<"DATE OF BIRTH: "; cin>>obj.dob;
    cout<<"YEAR: "; cin>>year;
    cout<<"DIVISION: "; cin>>divi;
    cout<<"ROLL NUMBER: "; cin>>roll_no;
    cout<<"BLOOD GROUP: "; cin>>obj.bldgrp;
    cout<<"LICENSE NUMBER: "; cin>>obj.lic;
    cout<<"PHONE NUMBER: "; cin>>mob;
}

void student::display(per_info &obj){
    cout<<"\n***********************"<<endl;
    cout<<"NAME OF STUDENT: "<<name<<endl;
    cout<<"ADDRESS OF STUDENT: "<<address<<endl;
    cout<<"DATE OF BIRTH: "<<obj.dob<<endl;
    cout<<"YEAR: "<<year<<endl;
    cout<<"DIVISION: "<<divi<<endl;
    cout<<"ROLL NO: "<<roll_no<<endl;
    cout<<"BLOOD GROUP: "<<obj.bldgrp<<endl;
    cout<<"LICENSE NUMBER: "<<obj.lic<<endl;
    cout<<"PHONE NUMBER: "<<mob<<endl;
    cout<<"***********************"<<endl;
}

int main(){
    int n, ch;

    cout<<"ENTER NO OF STUDENTS: ";
    cin>>n;
    cout<<"\n***********************"<<endl;
    student *sobj=new student[n];                
    per_info *pobj=new per_info[n];

    do {
        cout<<"\n Menu \n 1. Create Database \n 2. Display Databse \n 3. Copy Constructor\n 4. Default Constructor \n 5. Delete (Destructor) \n 6. Quit";
        cout<<"\n Enter your Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                for(int i=0;i<n;i++) {
                    sobj[i].create(pobj[i]);
                    sobj[i].inccnt();
                }
                break;
            
            case 2:
                sobj[0].showcnt();
                for(int i=0;i<n;i++){
                    sobj[i].display(pobj[i]);
                }
                break;

            case 3: {
                student obj1;
                per_info obj2;
                obj1.create(obj2);
                student obj3(obj1);        
                per_info obj4(obj2);        
                cout<<"\nCopy Constructor is called ";
                obj3.display(obj4);
                break;
            }
            case 4: {
                student obj1;    
                per_info obj2;    
                cout<<"\nDefault Constructor is called ";
                obj1.display(obj2);
                break;
            }
            case 5:
                delete [] sobj;            
                delete [] pobj;        
                break;
            case 6:
                cout<<"Thankyou!"<<endl;
                break;
        }
    } while(ch!=6);

    return 0;
}