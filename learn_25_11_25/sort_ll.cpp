#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void append(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node* mergeLists(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->data <= b->data) {
        a->next = mergeLists(a->next, b);
        return a;
    } else {
        b->next = mergeLists(a, b->next);
        return b;
    }
}

void splitList(Node* head, Node*& first, Node*& second) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
 
    first = head;
    second = slow->next;
    slow->next = nullptr;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next)
        return head;

    Node *first, *second;
    splitList(head, first, second);

    first = mergeSort(first);
    second = mergeSort(second);

    return mergeLists(first, second);
}

int main() {
    Node* head = nullptr;

    append(head, 40);
    append(head, 10);
    append(head, 30);
    append(head, 5);
    append(head, 20);

    cout << "Original list: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted list:   ";
    printList(head);

    return 0;
}
