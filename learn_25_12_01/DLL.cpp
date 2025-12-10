#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

void addBeg(Node*& head, int value) {
    Node* n = new Node(value);
    if (head == nullptr) {
        head = n;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
}

void addEnd(Node*& head, int value) {
    Node* n = new Node(value);
    if (head == nullptr) {
        head = n;
        return;
    }
    Node* cur = head;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = n;
    n->prev = cur;
}

void addPos(Node*& head, int pos, int value) {
    if (pos == 0) {
        addBeg(head, value);
        return;
    }
    Node* cur = head;
    for (int i = 0; i < pos - 1 && cur != nullptr; i++) cur = cur->next;
    if (cur == nullptr) return;
    Node* n = new Node(value);
    n->next = cur->next;
    n->prev = cur;
    if (cur->next != nullptr) cur->next->prev = n;
    cur->next = n;
}

void delBeg(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    delete temp;
}

void delEnd(Node*& head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* cur = head;
    while (cur->next != nullptr) cur = cur->next;
    cur->prev->next = nullptr;
    delete cur;
}

void delPos(Node*& head, int pos) {
    if (head == nullptr) return;
    if (pos == 0) {
        delBeg(head);
        return;
    }
    Node* cur = head;
    for (int i = 0; i < pos && cur != nullptr; i++) cur = cur->next;
    if (cur == nullptr) return;
    cur->prev->next = cur->next;
    if (cur->next != nullptr) cur->next->prev = cur->prev;
    delete cur;
}

void reverse(Node*& head) {
    if (head == nullptr || head->next == nullptr) return;
    Node* cur = head;
    Node* temp = nullptr;
    while (cur != nullptr) {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }
    if (temp != nullptr) head = temp->prev;
}

void printForward(Node* head) {
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void printBackward(Node* head) {
    if (head == nullptr) return;
    while (head->next != nullptr) head = head->next;
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->prev;
    }
    cout << endl;
}

int middle(Node* head) {
	Node* slow = head;
	Node* fast = head;
	
	while(fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	
	return slow->value;
}

int main() {
    Node* head = nullptr;

    addBeg(head, 3);
    addBeg(head, 2);
    addBeg(head, 1);

    addEnd(head, 4);
    addEnd(head, 5);

    addPos(head, 3, 99);

    printForward(head);
    printBackward(head);

    delBeg(head);
    delEnd(head);
    delPos(head, 2);

    printForward(head);
    reverse(head);
    printForward(head);
	
	cout << "\nMiddle node: " << middle(head) << "\n";
}
