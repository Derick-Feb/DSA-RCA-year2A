#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int a): value(a) {
        next = nullptr;
    }
};

void insertAtStart(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << ", ";
        temp = temp->next;
    }
    cout << endl;
}

void delAtStart(Node*& head) {
    if(head == nullptr) {
        cout << "List is already empty!" << endl;
        return;
    }

    Node* temp = head;
    temp->next;

    delete temp;
}

int main() {
    Node* head = new Node(10);

    insertAtStart(head, 10);
    insertAtStart(head, 20);
    insertAtStart(head, 30);

    printList(head);
    delAtStart(head);
    printList(head);

    return 0;
}
