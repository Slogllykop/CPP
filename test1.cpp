/*Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set
B of students like butterscotch ice-cream. Write C++ program to store two sets using
linked list. compute and display
a) Set of students who like both vanilla and butterscotch
b) Set of students who like either vanilla or butterscotch
c) No. of students who like neither vanilla nor butterscotch*/
#include<iostream>
#include<string.h>
using namespace std;


//This Program uses Singly linked list to store the sets

class Node{
    private:
    int roll;
    Node *next;
    public:
    Node(){
        roll = 0;
        next = NULL;
    }
    friend class Icecream; // so that class Icecream can access private members of Node
};


class Icecream{
    Node *head,*tail;
    public:
    Icecream(){
        head = tail = NULL;
    }
    void print();
    void addNode(int data);
    void deleteNode(int data);
    Icecream unionLL(Icecream a,Icecream b); //a = set of Vanilla , b = set of Butterscotch
    Icecream interLL(Icecream a,Icecream b);
    Icecream eitherLL(Icecream uni,Icecream inter); //uni = Union of a&b , inter = Intersection of a&b
};

void Icecream::print(){
    Node *temp;
    temp = head;
    while(temp!=NULL){
        cout<<"["<<temp->roll<<"]"<<endl;
        temp= temp->next;
    }
}

void Icecream::addNode(int data){
    Node *temp = new Node;// creates a new node with specified roll no. as data 
    temp->roll = data;
    if(head==NULL && tail==NULL) {// i.e. the list is empty so create a list
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

void Icecream::deleteNode(int data){
    Node *todel,*prev; //here the prev pointer points to previous node to the note to be deleted
    todel = head;
    prev = NULL;
    while(todel!=NULL){
        prev = todel;
        if(head->roll == data){//If the node to be deleted itself is the head
            head = head->next;//Then point the head to next node and delete old head
            delete todel;
            break;
        }
        else{//if any other node is to be deleted than head
        if(todel->roll == data){//find the node to be deleted
            prev->next = todel->next;//point the prev node to the next to next node
            delete todel;
            break;
            if(todel->next == NULL){//if the last node is to be deleted
                prev->next = NULL;//then point the previous to null
                delete todel;
                break;
            }
        }}
        todel= todel->next;
    }
}

Icecream Icecream :: unionLL(Icecream a, Icecream b) {
        Icecream unionSLL;
        Node *temp1,*temp2;//Here we create two temporary pointers to iterate through 
        temp1 = a.head; //the both sets
        while(temp1 != NULL){
            unionSLL.addNode(temp1->roll);//first we will add all elements of set a 
            temp1 = temp1->next;// in the union SLL
        }
        temp2 = unionSLL.head;
        while(temp2!=NULL){
            Node *x;
            x = b.head;
            int flag = -1;
            while(x != NULL){//This loop performs a linear search on unionSLL
                if(x->roll == temp2->roll)//to check if the roll no already exists
                    flag++;
                x = x->next;
            }
            if(flag==-1)//if it doesn't then it adds the roll to the unionSLL
                unionSLL.addNode(temp2->roll);
            temp2 = temp2->next;
        }
        return unionSLL;
}

Icecream Icecream :: interLL(Icecream a, Icecream b) {
        Icecream interSLL;
        Node *temp1 = a.head;
        while(temp1 != NULL){
            Node *temp2 = b.head;
            while(temp2 != NULL){
                if(temp1->roll == temp2->roll){//if the roll exists in both set a and b
                    interSLL.addNode(temp1->roll);//then it is added to the interSLL
                    break;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return interSLL;
}

Icecream Icecream::eitherLL(Icecream uni, Icecream inter) {
    Icecream eitherSLL;
    Node *temp,*temp2,*find;
    temp = uni.head;
    while(temp!= NULL){//to make a copy of union set
        eitherSLL.addNode(temp->roll);
        temp = temp->next;
    }
    find = inter.head;
    while(find != NULL){
        temp2 = eitherSLL.head;
        while(temp2 != NULL){
        if(temp2->roll == find->roll)
        eitherSLL.deleteNode(find->roll);//to delete intersection elements from union set
        temp2 = temp2->next;
        }
        find = find->next;
    }
    return eitherSLL;
}

void menu(){
    Icecream van, butter, uni, inter,either;
    int opt,roll,count=0;
    char ch = 'y';
    
    cout<<"WELCOME TO THE ICECREAM DATABASE SYSTEM!"<<endl;
    // again:
    while(ch=='y'){
        cout<<"ENTER STUDENT ROLL NO.: ";
        cin>>roll;
        cout<<"Please enter his liking:\n1.Vanilla\n2.Butterscotch\n3.Both\n4.Neither\n5.Exit"<<endl;
        cout<<"Option no.: ";
        cin>>opt;
        switch(opt){
            case 1: van.addNode(roll);
                    break;
            case 2: butter.addNode(roll);
                    break;
            case 3: van.addNode(roll);
                    butter.addNode(roll);
                    break;
            case 4 : count++;
                    break;
            case 5 : cout<<"THANK YOU FOR USING OUR DATABASE SYSTEM!";
                    exit(0);
            default:
                cout<<"INVALID OPTION! TRY AGAIN!"<<endl;
                // goto again; 
    }
    cout<<"Do you want to add another student's liking?(y/n)"<<endl;
    cin>>ch;
}
    cout<<"WE ARE OUT OF THE LOOP!"<<endl;
    inter = inter.interLL(van,butter);
    cout<<"Set of students who like both Vanilla and Butterscotch: ";
    inter.print();
    cout<<endl;
    uni = uni.unionLL(van,butter);
    either = either.eitherLL(uni,inter);
    cout<<"Set of students who like either Vanilla or Butterscotch: ";
    either.print();
    cout<<endl;
    cout<<"No. of students who like neither vanilla nor butterscotch: "<<count;
}
int main(){
    menu();
    return 0;
}