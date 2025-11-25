#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << ", ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtStart(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    
    if (head == nullptr){
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
}

// pos are like index
void insertAtPos(Node*& head, int value, int pos) {
    if(pos == 0) {
        insertAtStart(head, value);
        return;
    }

    Node* temp = head;
    for(int i = 0; i < pos - 1; i++) {
        if(temp == nullptr) {
            cout << "Out of bounds!";
            return;
        }

        temp = temp->next;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

int countNodes(Node*& head){
    Node* temp = head;
    int count = 0;
    while(temp != nullptr) {
        count ++;
        temp = temp->next;
    }

    return count;
}

int main() {
    Node* head = nullptr;

    insertAtStart(head, 10);
    insertAtStart(head, 23);
    insertAtStart(head, 14);

    insertAtEnd(head, 43);
    insertAtEnd(head, 23);
    insertAtEnd(head, 20);

    insertAtPos(head, 100, 1);

    cout << "Length of linked-list nodes: " << countNodes(head) << endl;

    printList(head);
}
