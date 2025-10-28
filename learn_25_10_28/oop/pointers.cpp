#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int x = 10;
    int* ptr = &x;
    cout << "The pointer is: " << ptr << '\n';
    
    // *: reference operator
    // &: address-of operator
    
    *ptr = 20;
    cout << "The value of x: " << x << '\n';
    
    int** ptr2 = &ptr;
    cout << "The pointer2 is: " << ptr2 << '\n';
    
    **ptr2 = 10;
    cout << "The value of x: "  << x << '\n';

    char name[] = "Fundamentals of Programming Language";
    char* token = strtok(name, " ");
    
    while (token != nullptr) {
        cout << "Token: " << token << '\n';
        token = strtok(nullptr, " ");
    }
    cout << '\n';
    
    int* arr = new int[5];
    // for(int i = 0; i < 5; i++) {
    //     arr[i] = i * 10;
    // }

    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    delete[] arr;

    return 0;
}
