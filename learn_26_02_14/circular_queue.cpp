#include <iostream>
using namespace std;

template <typename T>
class ArrayCircularQueue {
    int front, rear, size;
    T *arr;

public:
    ArrayCircularQueue(int size): front(-1), rear(-1), size(size){
        arr = new T[size];
    }

    ~ArrayCircularQueue() { delete[] arr; }

    bool isFull() { return (size + 1) % size == front; }

    bool isEmpty() { return rear == -1; }

    void enqueue(T el) {
        if(isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }

        if(isEmpty()) {
            rear = front = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = el;
    }

    void dequeue() {
        if(isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        int element = arr[front];
        if(front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }
};

int main() {
    return 0;
}

/*
so this are the logics
on Enqueue:

1. check if it is full (rear + 1) % size = front;
 */
