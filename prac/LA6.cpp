// Write C++ program using STL for sorting and searching user
// defined records such as personal records
// (Name, DOB, Telephone number etc) using vector container.

#include <iostream>    
#include <algorithm>    
#include <vector>    
using namespace std;

class Item        
{
    public:
        char name[50];
        int quantity;
        int cost;
        int code;

        bool operator == (const Item & i1) {
            if(code==i1.code) {
                return 1;
            }                                          
            return 0;
        }

        bool operator < (const Item & i1) {
            if(code<i1.code){
                return 1;
            }                                            
            return 0;
        }
};

vector<Item> o1;

void print(Item &i1) {
    cout<<"\n";
    cout<<"\nItem Name : "<<i1.name;
    cout<<"\nItem Quantity : "<<i1.quantity;
    cout<<"\nItem Cost : "<<i1.cost;
    cout<<"\nItem Code : "<<i1.code;
}

void display() {
    for_each(o1.begin(),o1.end(),print);
}

void insert() {
    Item i1;
    cout<<"\nEnter Item Name : "; cin>>i1.name;
    cout<<"Enter Item Quantity : "; cin>>i1.quantity;
    cout<<"Enter Item Cost : "; cin>>i1.cost;
    cout<<"Enter Item Code : "; cin>>i1.code;
    o1.push_back(i1);
}

void search() {
    vector<Item>::iterator p;
    Item i1;
    cout<<"\nEnter the Item Code to searched for : ";
    cin>>i1.code;

    p=find(o1.begin(),o1.end(),i1);

    if(p==o1.end()) {
        cout<<"\nItem you are seaching for could not be found.";
    }
    else {
        cout<<"\nItem Found.\n";
    }
}

void Delete() {
    vector<Item>::iterator p;
    Item i1;
    cout<<"\nEnter the Item Code to deleted : ";
    cin>>i1.code;
    p=find(o1.begin(),o1.end(),i1);
    if(p==o1.end())
    {
        cout<<"\nItem that you want to delete could not be found.";
    }
    else
    {
         o1.erase(p);  // deletes specified element
        cout<<"\nItem Deleted.\n";
    }
}

bool compare(const Item &i1, const Item &i2)
{
    return i1.cost < i2.cost;
}

int main(){
    int ch;
        do {  
            cout<<"\n\n\t  ** MENU **\n";
            cout<<"\n1.Insert the details for the item ";
            cout<<"\n2.Display the details for all the items stored";
            cout<<"\n3.Search for a particular item ";
            cout<<"\n4.Sort the items on the basis of its cost";
            cout<<"\n5.Delete an item and its corresponding details";
            cout<<"\n6.Exit";
            cout<<"\n\nEnter your choice : ";
            cin>>ch;

            switch(ch){
                case 1:
                    insert();
                    break;

                case 2:
                    display();
                    break;

                case 3:
                    search();
                    break;

                case 4:
                    sort(o1.begin(),o1.end(),compare);  
                    cout<<"\n\n Sorted on Cost --> \n";
                    display();
                    break;

                case 5:
                    Delete();
                    break;

                case 6:
                    cout<<"\nTHANKYOU !!"<<endl<<endl;
                    exit(0);
            }
        } while(ch!=7);
    return 0;
}