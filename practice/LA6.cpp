#include <iostream>    
#include <algorithm>    
#include <vector>
#include <iterator>
#include <string>

class Item {
    public:
        std::string name;
        int quantity, cost, code;

        bool operator == (const Item &i1) {  return code == i1.code ? 1 : 0; }
};

void print(Item &i1) {
    std::cout << "\n\nItem Name : " << i1.name << "\nItem Quantity : " << i1.quantity;
    std::cout << "\nItem Cost : " << i1.cost << "\nItem Code : " << i1.code;
}

std::vector <Item> o1;

void display() { std::for_each(o1.begin(), o1.end(), print); }

void insert() {
    Item i1;
    std::cout << "\nEnter Item Name : "; std::cin >> i1.name;
    std::cout << "Enter Item Quantity : "; std::cin >> i1.quantity;
    std::cout << "Enter Item Cost : "; std::cin >> i1.cost;
    std::cout << "Enter Item Code : "; std::cin >> i1.code;
    o1.push_back(i1);
}

void search() {
    std::vector<Item>::iterator p;
    Item i1;
    std::cout << "\nEnter the Item Code to searched for : "; std::cin >> i1.code;

    p = find(o1.begin(), o1.end(), i1);

    if(p != o1.end()) std::cout << "\nItem Found.\n";
    else std::cout << "\nItem you are seaching for could not be found.";
}

void Delete() {
    std::vector<Item>::iterator p;
    Item i1;
    std::cout << "\nEnter the Item Code to deleted : "; std::cin >> i1.code;

    p = find(o1.begin(), o1.end(), i1);

    if(p != o1.end()) o1.erase(p);
    else std::cout << "\nItem that you want to delete could not be found.";
}

bool compare(Item &i1, Item &i2) { return i1.cost < i2.cost; }

int main() {
    int ch;
    do {
        std::cout << "\n===============================================";
        std::cout << "\n1.Insert the details for the item ";
        std::cout << "\n2.Display the details for all the items stored";
        std::cout << "\n3.Search for a particular item ";
        std::cout << "\n4.Sort the items on the basis of its cost";
        std::cout << "\n5.Delete an item and its corresponding details";
        std::cout << "\n6.Exit";
        std::cout << "\nEnter your choice : ";
        std::cin >> ch;
        switch(ch) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4:
                sort(o1.begin(), o1.end(), compare);  
                std::cout<<"\n Sorted";
                display();
                break;
            case 5:
                Delete();
                break;
            case 6: exit(0);
        }
    } while(ch);
    return 0;
}