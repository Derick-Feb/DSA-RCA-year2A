#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        if (top == NULL) {
            return true;
        }
        return false;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;

        cout << value << " pushed into stack." << endl;
    }

    int peek() {
        if (top == NULL) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop." << endl;
            return;
        }

        Node* temp = top;
        cout << temp->data << " popped from stack." << endl;
        top = top->next;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    s.pop();
    s.display();
    return 0;
}
