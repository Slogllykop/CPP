#include <iostream>
#include <limits>
#include <ios>
#include <string>

class Publications {
    public:
        std::string title;
        float price, time; int pages;

        Publications() { price = time = pages = 0; }

        void getTitle();
        void getPrice();

        void displayData(int);
};

class Book : public Publications { public: void getPages(std::string); };
class Tape : public Publications { public: void getTime(std::string); };

int main() {
    int choice;
    std::cout << "Which type of publication?\n1] Book\n2] Tape\n Enter your choice: ";
    std::cin >> choice;
    
    switch (choice) {
        case 1: {
            Book b;
            b.getTitle();
            b.getPrice();
            b.getPages("Enter the number of pages: ");
            b.displayData(1);
            break;
        }
        case 2: {
            Tape b;
            b.getTitle();
            b.getPrice();
            b.getTime("Enter the running time: ");
            b.displayData(0);
            break;
        }
        default: std::cout << "Invalid choice!";
    }

    return 0;
}

void Publications ::  getTitle() {
    std::cin.ignore(std::numeric_limits <std::streamsize> :: max(), '\n');
    std::cout << "\nEnter the title of the publication: ";
    std::getline(std::cin, title);
}

void Publications :: getPrice() {
    try {
        float tp;
        std::cout << "Enter the price: ";
        std::cin >> tp;
        if (tp < 0 ) throw tp;
        else price = tp;
    } catch (float tp) {
        std::cout << "Invalid price! Try again: ";
        std::cin >> price;
    }
}

void Publications :: displayData(int choice) {
    std::cout << "\nTitle: " << title;
    std::cout << "\nPrice: " << price << " Rs.";
    if (choice) std::cout << "\nNumber of pages: " << pages;
    else std::cout << "\nRunning time: " << time << " mins";
}

void Book :: getPages(std::string msg) {
    try {
        int tpg;
        std::cout << msg;
        std::cin.ignore(std::numeric_limits <std::streamsize> :: max(), '\n');
        std::cin >> tpg;
        if (tpg <= 0) throw tpg;
        else pages = tpg;
    } catch (int tpg) {
        std::cout << "Invalid pages! Try again: ";
        std::cin >> pages;
    }
}

void Tape :: getTime(std::string msg) {
    try {
        float tt;
        std::cout << msg;
        std::cin.ignore(std::numeric_limits <std::streamsize> :: max(), '\n');
        std::cin >> tt;
        if (tt <= 0) throw tt;
        else time = tt;
    } catch (float tt) {
        std::cout << "Invalid Time! Try again: ";
        std::cin >> time;
    }
}