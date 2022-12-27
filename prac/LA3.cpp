// Imagine a publishing company which does marketing for book
// and audio cassette versions. Create a class publication that
// stores the title (a string) and price (type float) of publications.
// From this class derive two classes: book which adds a page
// count (type int) and tape which adds a playing time in minutes (type float).
// Write a program that instantiates the book and tape class,
// allows user to enter data and displays the data members. If an
// exception is caught, replace all the data member values with
// zero values.

#include<iostream>
#include<string>
using namespace std;

class Publication {
    public:
        float price;
        string title;

        void getdata() {
            try {
                cout<<"\ntitle of the publication:";
                cin.ignore();
                getline(cin,title);
                cout<<"price of the publication:";
                cin>>price;
                if(price<=0) {
                    throw price;
                }
            }

            catch(float b) {
                while(price<=0){
                    cout<<"\nInvalid price!!"<<endl;
                    cout<<"Title of the publication = 0"<<endl;
                    cout<<"Price of the publication = 0"<<endl;
                    cout<<"\ntitle of the publication:";
                    cin.ignore();
                    getline(cin,title);
                    cout<<"price of the publication:";
                    cin>>price;
                }
            }
        }
};

class Book:public Publication {
    public:
        Book(){
            cout<<"Book \n";
        }
        int pagecount;
        void count(){
            try {
                cout<<"number of pages:"; 
                cin>>pagecount;

                if(pagecount<=0){
                    throw pagecount;
                }
            }
            catch(int b) {
                while(pagecount<=0){
                cout<<"\npage count is invalid!!\n"<<endl;
                cout<<"Title of the publication = 0"<<endl;
                cout<<"Price of the publication = 0"<<endl;
                cout<<"Page Count of the book = 0"<<endl;
                cout<<"\ntitle of the publication:";
                cin.ignore();
                getline(cin,title);
                cout<<"price of the publication:";
                cin>>price;
                cout<<"number of pages of the book:";
                cin>>pagecount;
                }
            }
        }
        void display() {
            cout<<"\nTITLE OF THE PUBLICATION: "<<title<<endl;
            cout<<"PRICE OF THE PUBLICATION: "<<price<<endl;
            cout<<"PAGE COUNT OF THE BOOK: "<<pagecount<<endl;
        }
};

class Tape: public Publication{
    public:
        Tape(){
            cout<<"\ntape \n";
        }
        int playingtime;
        void play() {
            try {
                cout<<"playing time of tape in minutes: ";
                cin>>playingtime;
                if(playingtime<=0){
                    throw playingtime;
                }
            }
            catch(int b) {
                while(playingtime<=0) {
                    cout<<"\nplaying time is invalid! \n"<<endl;
                    cout<<"Title of the publication = 0"<<endl;
                    cout<<"Price of the publication = 0"<<endl;
                    cout<<"Playing time of the tape = 0"<<endl;
                    cout<<"\ntitle of the publication:";
                    cin.ignore();
                    getline(cin,title);
                    cout<<"price of the publication:";
                    cin>>price;
                    cout<<"playing time of tape in minutes: ";
                    cin>>playingtime;
                }
            }
        }
        void display() {
            cout<<"\nTITLE OF THE PUBLICATION: "<<title<<endl;
            cout<<"PRICE OF THE PUBLICATION: "<<price<<endl;
            cout<<"PLAYING TIME OF THE TAPE: "<<playingtime<<" minutes."<<endl;
        }
};

int main(){
    Book b;
    b.getdata();
    b.count();
    b.display();
    Tape t;
    t.getdata();
    t.play();
    t.display();
    return 0;
}