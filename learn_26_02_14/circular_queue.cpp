#include <iostream>
using namespace std;

template <typename T>
class ArrayCircularQueue {
    int front, rear, size; 
    T *arr;

public:
    ArrayCircularQueue(int size) front(-1), rear(-1), size(size){
        arr = new T[size];
    }

    ~ArrayCircularQueue() {
        delete[] arr;
    }

    

}; 

int main() {
    return 0;
}