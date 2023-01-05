#include <iostream>

struct Node {
    int seat, status;
    std::string id;
    Node *next, *prev;
};

class Cinemax {
    public:
        Node *head, *tail, *temp;
        Cinemax() { head = NULL; tail = NULL; this -> create(); }
        void create();
        void display();
        void book();
        void cancel();
};

int main() {
    Cinemax A;
    int flag = 1, choice;
    while (flag) {
        A.display();
        std::cout <<"Choose one option\n"
                    "1] Book seat\n"
                    "2] Cancel seat\n"
                    "3] Exit\n"
                    "Enter index: "; std::cin >> choice;
        switch (choice) {
            case 1: A.book(); break;
            case 2: A.cancel(); break;
            case 3: flag = 0; break;
            default: std::cout << "Invalid choice!\n";
        }
    }
    std::cout << "\nThanks for using our system!";
    return 0;
}

void Cinemax :: create() {
    Node *temp;
    temp = new Node;
    temp -> seat = 1;
    temp -> status = 0;
    temp -> id = "NULL";
    head = tail = temp;
    for (int i = 2; i < 71; i++) {
        Node *p;
        p = new Node;
        p -> seat = i;
        p -> status = 0;
        p -> id = "NULL";
        tail -> next = p;
        p -> prev = tail;
        tail = p;
        tail -> next = head;
        head -> prev = tail;
    }
}

void Cinemax :: display() {
    int count = 0;
    Node *t;
    t = head;
    std::cout <<"==============================================================\n"
                "                 WELCOME TO CINEMAX THEATRE\n"
                "==============================================================\n"
                "                      ALL EYES THIS WAY\n"
                "==============================================================\n";
    do {
        if (!(t -> seat / 10)) {
            if ((t -> status)) std::cout << "S0" << t -> seat << "|_B_|" << " ";
            else std::cout << "S0" << t -> seat << "|___|" << " ";
        } else {
            if ((t -> status)) std::cout << "S" << t -> seat << "|_B_|" << " ";
            else std::cout << "S" << t -> seat << "|___|" << " ";
        }
        count++;
        if (!(count % 7)) { std::cout << std::endl; }
        t = t -> next;
    } while (t != head);
    std::cout << "==============================================================\n";
}

void Cinemax :: book() {
    int _seat;
    std::string _id;
    Node *t;
    t = new Node;
    t = head;
    tryagain:
    std::cout << "Enter the seat number to book (1-70): "; std::cin >> _seat;
    while (_seat < 1 || _seat > 70) {
        std::cout << "Invalid seat number!\n";
        goto tryagain;
    }
    std::cout << "Enter the id: "; std::cin >> _id;
    while (t -> seat != _seat) t = t -> next;
    if (t -> status) std::cout << "\nSeat already booked!\n";
    else {
        t -> status = 1;
        t -> id = _id;
        std::cout << "\nSeat booked successfully!\n";
    }
}

void Cinemax :: cancel() {
    int _seat;
    std::string _id;
    Node *t;
    t = new Node;
    t = head;
    tryagains:
    std::cout << "Enter the seat number to cancel (1-70): "; std::cin >> _seat;
    while (_seat < 1 || _seat > 70) {
        std::cout << "Invalid seat number!\n";
        goto tryagains;
    }
    while (t -> seat != _seat) t = t -> next;
    if (!(t -> status)) std::cout << "\nSeat not booked!\n";
    else {
        tryagaini:
        std::cout << "Enter the id: "; std::cin >> _id;
        while (t -> id != _id) {
            std::cout << "ID does not match!\n";
            goto tryagaini;
        }
        t -> status = 0;
        t -> id = "NULL";
        std::cout << "\nSeat cancelled successfully!\n";
    }
}