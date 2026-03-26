#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // ================= INSERT OPERATIONS =================

    // Insert at beginning (top)
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Insert at position
    void insertAtPosition(int value, int pos) {
        if (pos == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range.\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // ================= DELETE OPERATIONS =================

    // Delete from beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    // Delete from position
    void deleteFromPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (pos == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Position out of range.\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // ================= ACCESS =================

    // Get value at position
    int get(int pos) {
        Node* temp = head;

        for (int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range.\n";
            return -1;
        }

        return temp->data;
    }

    // ================= TRAVERSAL =================

    void display() {
        Node* temp = head;

        if (temp == NULL) {
            cout << "List is empty.\n";
            return;
        }

        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // ================= SORTING (Bubble Sort) =================

    void sort() {
        if (head == NULL) return;

        bool swapped;
        Node* ptr1;
        Node* lptr = NULL;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->data > ptr1->next->data) {
                    // swap data
                    int temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    // ================= SEARCH =================

    void search(int key) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Not found.\n";
    }
};

// ================= MAIN FUNCTION (TESTING) =================

int main() {
    LinkedList list;

    // Insertions
    list.insertAtBeginning(30);
    list.insertAtBeginning(10);
    list.insertAtEnd(50);
    list.insertAtPosition(20, 2);

    list.display();

    // Access
    cout << "Element at position 3: " << list.get(3) << endl;

    // Deletions
    list.deleteFromBeginning();
    list.display();

    list.deleteFromEnd();
    list.display();

    list.deleteFromPosition(2);
    list.display();

    // Insert more for sorting
    list.insertAtEnd(40);
    list.insertAtEnd(5);
    list.insertAtEnd(25);

    list.display();

    // Sorting
    list.sort();
    cout << "After sorting:\n";
    list.display();

    // Search
    list.search(25);

    return 0;
}
