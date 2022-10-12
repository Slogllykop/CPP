/*
Imagine a publishing company which does marketing for book and audio cassette versions.
Create a class publication that stores the title (a string) and price (type float) of publications.
From this class derive two classes: book which adds a page count (type int) and tape which adds
a playing time in minutes (type float).

Write a program that instantiates the book and tape class, allows user to enter data and displays the data members.
If an exception is caught, replace all the data member values with zero values.
*/

#include <iostream>
#include <string>
#include <ios>
#include <limits>
#include <conio.h>

class publications
{
    public:
        std::string title , msg;
        float price = 0 , time = 0;
        int pages = 0;

        void getTitle();
        void getPrice();

        void displayData(int);
};

class book : public publications
{
    public:
        void getPages();
};

class tape : public publications
{
    public:
        void getTime();
};

int main(){

    int choice;
    std::cout << "What do you want to check?\n1] Book\n2] Tape\nEnter your choice: ";
    std::cin >> choice;

    book B;
    tape T;

    switch (choice)
    {
    case 1:
        B.msg = "Number of pages in the book is ";
        B.getTitle();
        B.getPrice();
        B.getPages();
        B.displayData(1);
        break;

    case 2:
        T.msg = "Playing time of the tape is ";
        T.getTitle();
        T.getPrice();
        T.getTime();
        T.displayData(2);
        break;
    
    default:
        break;
    }

    getch();
    return 0;
}

void publications :: displayData(int p)
{
    system("cls");
    std::cout << "\n\nTitle of the publication is " << title << std::endl;
    std::cout << "It costs around " << price << " Rs." << std::endl;

    switch (p)
    {
    case 1:
        std::cout << msg << pages << std::endl;
        break;
    
    case 2:
        std::cout << msg << time << " minutes" << std::endl;
        break;
    }
}

void publications :: getTitle()
{
    std::cout << "Enter title of the publication: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin , title);
}

void publications :: getPrice()
{
    try
    {
        std::cout << "Enter price of the publication: ";
        std::cin >> price;

        if(price < 0)
        {
            throw price;
        }
    }

    catch(float price)
    {
        std::cout << "Price cannot be negative. Enter again: ";
        // didnt use loop 
        std::cin >> price;
    }
}

void book :: getPages()
{
    try
    {
        std::cout << "Enter number of pages: ";
        std::cin >> pages;

        if(pages < 0)
        {
            throw pages;
        }
    }

    catch(int pages)
    {
        std::cout << "Number of pages cannot be negative. Enter again: ";
        // didnt use loop
        std::cin >> pages;
    }
}

void tape :: getTime()
{
    try
    {
        std::cout << "Enter playing time in minutes: ";
        std::cin >> time;

        if(time < 0)
        {
            throw time;
        }
    }

    catch(float time)
    {
        std::cout << "Playing time cannot be negative. Enter again: ";
        std::cin >> time;
    }
}