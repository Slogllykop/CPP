#include <iostream>

class Stack {
    private:
        char infix[50];
        char postfix[50];
    public:
        char stack_arr[50];
        int top;
        Stack() {top = -1; }
        void push(char symbol) {
            if (full()) std::cout << "Stack Overflowed!\n";
            else stack_arr[++top] = symbol;
        }
        char pop() {
            if (empty()) return '#';
            else return stack_arr[top--];
        }
        int full() {
            if (top == 49) return 1;
            else return 0;
        }
        int empty() {
            if (top == -1) return 1;
            else return 0;
        }
        void read() {
            std::cout << "Enter the infix expression: "; std::cin >> infix;
        }
        int white(char symbol) {
            if (symbol == ' ' || symbol == '\0' || symbol == '\t') return 1;
            else return 0;
        }
        int prior(char symbol) {
            switch (symbol) {
                case '^': return 3;
                case '/':
                case '*': return 2;
                case '+':
                case '-': return 1;
                case '(': return 0;
                default: return -1;
            }
        }
        void convert();
};

int main() {
    char choice = 'y';
    Stack e;
    while (choice == 'y') {
        e.read();
        e.convert();
        std::cout << "\n\nDo you want to try another? (y/n): "; std::cin >> choice;
    }
    return 0;
}

void Stack :: convert() {
    int prev, p = 0;
    char entry;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (!white(infix[i])) {
            switch (infix[i]) {
                case '(':
                    push(infix[i]);
                    break;
                case ')':
                    while ((entry = pop()) != '(') postfix[p++] = entry;
                    break;
                case '+':
                case '-':
                case '/':
                case '*':
                case '^':
                    if (!empty()) {
                        prev = prior(infix[i]);
                        entry = pop();
                        while (prev <= prior(entry)) {
                            postfix[p++] = entry;
                            if (!empty()) entry = pop();
                            else break;
                        }
                        if (prev > prior(entry)) push(entry);
                    }
                    push(infix[i]);
                    break;
                default:
                    postfix[p++] = infix[i];
                    break;
            }
        }
    }
    while (!empty()) postfix[p++] = pop();
    postfix[p] = '\0';
    std::cout << "\nThe Postfix expression is: " << postfix << std::endl;
}