#include <iostream>
#include <string>
using namespace std;

class SNode {
    int rollNo;
    SNode *next;
    public:
        SNode() {
            rollNo = 0;
            next = NULL;
        }
        void setRoll(int r) { rollNo = r; }
        void setNext(SNode *n) { next = n; }
        int getRoll() { return rollNo; }
        SNode *getNext() { return next; }
};

class Set_operations {
    SNode *start;
    public:
        Set_operations() { start = NULL; }
        void insert_node(int r);
        void display_list();
        void both_v_b_intersection(Set_operations L1, Set_operations L2);
        void union_v_b(Set_operations L1, Set_operations L2);
        void either_b_v_notBoth(Set_operations L1, Set_operations L2); //difference
        void Neither_nor(Set_operations L1,int t);
};

void Set_operations::Neither_nor(Set_operations L1,int t) {
    start = NULL;  //S4 list start set to NULL;
    SNode *temp;
    int cnt = 0;
    for (int i = 1; i <= t; i++) {
        temp = L1.start; int flag = 0;
        while(temp != NULL) {
            if(temp -> getRoll() == i) {
                flag=1; break;
            }
            temp = temp -> getNext();
        }
        if(flag == 0) {
            insert_node(i);
            cnt++;
        }
    }
    cout << "\n neither vanilla nor butterscotch: ";
    display_list();
    cout << "\n Number of students like neither vanilla nor butterscotch:" << cnt;
}

void Set_operations::either_b_v_notBoth(Set_operations L1, Set_operations L2) {
    SNode *temp1, *temp2;
    start = NULL;
    temp1 = L1.start;
    while(temp1 != NULL) {
        int flag = 0;
        temp2 = L2.start;
        while(temp2 != NULL) {
            if(temp1 -> getRoll() == temp2 -> getRoll()) { flag = 1; break;}
            temp2 = temp2 -> getNext();
        } //end of inner while
        if(flag == 0) insert_node(temp1 -> getRoll());
        temp1 = temp1 -> getNext();
    }
    cout << "\n Students like either vanilla or butterscotch or not both are: ";
    display_list();
}

void Set_operations::union_v_b(Set_operations L1, Set_operations L2) {
    SNode *temp1, *temp2;
    start = NULL;
    temp1 = L1.start;
    while(temp1 != NULL) {
        insert_node(temp1 -> getRoll());
        temp1 = temp1 -> getNext();
    }
    temp2 = L2.start;
    while(temp2 != NULL) {
        int flag = 0;
        temp1 = L1.start;
        while(temp1 != NULL) {
            if(temp1 -> getRoll() == temp2 -> getRoll()){ flag=1; break;}
            temp1 = temp1 -> getNext();
        }//end of inner while
        if(flag == 0)  insert_node(temp2->getRoll());
        temp2 = temp2 -> getNext();
    }
    cout << "\n Students like either vanilla or butterscotch or both are: ";
    display_list();
}

void Set_operations::both_v_b_intersection(Set_operations L1, Set_operations L2) {
    SNode *temp1, *temp2;
    temp1 = L1.start;
    while(temp1 != NULL) {//traverse L1
        temp2 = L2.start;
        while(temp2 != NULL) {//traverse L2
            if(temp1 -> getRoll() == temp2 -> getRoll()) { //compared
                insert_node(temp1 -> getRoll()); break;
            }
            temp2 = temp2 -> getNext();
        } //inner while
        temp1 = temp1 -> getNext();
    }
    cout << "\n Students like both vanilla and butterscotch are: ";
    display_list();
}

void Set_operations::insert_node(int r) {
    SNode *pNew, *temp;
    pNew = new SNode();
    pNew -> setRoll(r);
    if(start == NULL) start = pNew;
    else {
        temp = start;
        while(temp -> getNext() != NULL) temp = temp -> getNext();
        //append node
        temp -> setNext(pNew);
    }
}

void Set_operations::display_list() {
    SNode *temp;
    if(start == NULL) cout << "\n List is empty.";
    else {
        temp = start;
        while(temp -> getNext() != NULL) {
            cout << temp -> getRoll() << ", ";
            temp = temp -> getNext();
        }
        cout << temp -> getRoll();//last node display
    }
}

int main() {
    int ch, r;
    Set_operations S1, S2, S3, S4, S5;
    int Total_size;
    while(1) {
        cout << "\n\n Menu:\n 1. Read SET-A(students who like Vanilla icecream) \n 2. Read SET-B(students who like butterscotch icecream) \n 3. Display SET A & B";
        cout << "\n 4.Students who likes both vanilla and butterscotch";
        cout << "\n 5.Students who likes either vanilla or butterscotch or not both";
        cout << "\n 6. Number of students who like neither vanilla nor butterscotch";
        cout << "\n 7. Exit";
        cout << "\n Enter Choice: "; cin >> ch;
        switch(ch) {
            case 1: cout << "\n Enter item value: "; cin >> r;
                    S1.insert_node(r);
                    break;
            case 2: cout << "\n Enter item value: "; cin >> r;
                    S2.insert_node(r);
                    break;
            case 3: cout << "\n Set-A is: ";
                    S1.display_list();
                    cout << "\n Set-B is: ";
                    S2.display_list();
                    break;
            case 4: S3.both_v_b_intersection(S1,S2);
                    break;
            case 5: S3.union_v_b(S1,S2);
                    S4.both_v_b_intersection(S1,S2);
                    S5.either_b_v_notBoth(S3,S4);
                    break;
            case 6: cout << "\n Enter total size of class: "; cin >> Total_size;
                    S3.union_v_b(S1,S2);
                    S4.Neither_nor(S3, Total_size);
                    break; 
            case 7: exit(0);
        }
    }
}


