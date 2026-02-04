#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};

class Queue {
    Node* head;
    Node* tail;
    int size;
    
public:
    Queue(){
        head = NULL;
        tail = NULL;
    }

    int getSize() { return size; }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int ele) {
        Node* n = new Node(ele);
        if(head == nullptr) {
            head = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    void dequeue() {
        if(isEmpty) return;
        Node* temp = head;
        head = head->next;

        delete temp;
        size--;
    }

    int front() {
        if(isEmpty()) return 0;
        return head->data;
    }

    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << "";
            temp = temp->data;
        }
    }

    void display2() {
        while(isEmpty()) {
            cout << front() << endl;
            dequeue();
        }
    }
};

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}
