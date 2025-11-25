#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node *next;

    Node(T A){
        data = A,
        next = nullptr;
    }
    
    static void display(Node<T> *head){
        while(head != NULL){
            cout << head->data<<", ";
            head = head->next;
        }
    };
};

    
int main() {

    Node<int> *n1 = new Node(10);
    Node<int> *n2 = new Node(31);
    Node<int> *n3 = new Node(21);
    Node<int> *n4 = new Node(14);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Node<int>::display(n1);

    return 0;
}