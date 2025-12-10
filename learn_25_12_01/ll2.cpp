#include <iostream>
using namespace std;

class Node {
	public:
	int value;
	Node* next;
	
	Node(int value) {
		this->value = value;
		this->next = nullptr;
	}
};

int main() {
	Node* head = new Node(4);
	
	Node* node2 = new Node(5);
    head->next = node2;
	
	Node* node3 = new Node(5);
    node2->next = node3;
	
	Node* current = head;
	while(current != nullptr) {
		cout << current->value << " -> ";
		current = current->next;
	}
}