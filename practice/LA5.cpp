#include <iostream>
#define size 10

template <class T> void selectionSort(T arr[size], int length) {
    for(int i = 0; i < length - 1; i++) {
        int min = i;
        for(int j = i + 1; j < length; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        std::swap(arr[i], arr[min]);
    }
}

int main() {
    int A[size]; float B[size];
    int choice, n;
    std::cout << "Enter the number of elements: "; std::cin >> n;
    std::cout << "Which type of number?\n1] int\n2] float\nEnter your choice: "; std::cin >> choice;
    switch (choice)
    {
        case 1:
            for(int i = 0; i < n; i++) std::cin >> A[i];
            selectionSort<int>(A, n);
            for(int i = 0; i < n; i++) std::cout << A[i] << " ";
            break;
        
        case 2:
            for(int i = 0; i < n; i++) std::cin >> B[i];
            selectionSort<float>(B, n);
            for(int i = 0; i < n; i++) std::cout << B[i] << " ";
            break;

        default: break;
    }
    return 0;
}