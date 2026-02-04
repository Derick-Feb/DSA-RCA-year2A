#include <iostream>
using namespace std;

template <typename T>
class Node {
    T data;
    Node<T> *next;
    
    public:
    Node(T data) {
        this->data = data;
        next = nullptr;
    }
};

template <typename T>
class Stack {
    Node<T> *head;
    int size;

public:
    Stack() {
        head = nullptr;
        size = 0;
    }

    bool isEmpty() { return size == 0; }

    void push(T element) {
        if(isEmpty()) {
            head = new Node<T>(element);
        } else {
            Node<T> *temp = head;
            head = new Node(element);
            head->next = temp;
        }
    }

    void pop() {
        if(isEmpty()) {
            cout << "Stack empty";
            return;
        }
        
        Node<T> *temp = head;
        head = head->next;
        
        // delete temp;
    }
    
    T top() {
        if(isEmpty()) {
            cout << "Stack empty";
            return;
        } else {
            return head->data;
        }
        
    }
    
    void display() {
        while(temp->next != nullptr) {
            temp = temp->next;
        }
    }
};

int main() {
    Stack<int> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.isEmpty()<<endl;

    return 0;
}
