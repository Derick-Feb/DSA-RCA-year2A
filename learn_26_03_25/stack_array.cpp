#include <iostream>
using namespace std;

#define MAX 5

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (top == MAX - 1) {
            return true;
        }
        return false;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow. Cannot push." << endl;
            return;
        }

        top++;
        arr[top] = value;
        cout << value << " pushed into stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop." << endl;
            return;
        }

        cout << arr[top] << " popped from stack." << endl;
        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    return 0;
}
