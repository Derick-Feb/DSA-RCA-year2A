#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;
	
	Node(int value){
		this->value = value;
		this->next = nullptr;
	}
};

namespace ll {
	void addBeg(Node*& head, int value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}
	
	void addEnd(Node*& head, int value) {
		Node* newNode = new Node(value);
		Node* current = head;
		
		while(current->next != nullptr) current = current->next;
		
		current->next = newNode;
	}
	
	void addPos(Node*& head, int pos, int value) {
		Node* newNode = new Node(value);
		if(pos == 0 && head == nullptr) {
			newNode->next = head;
			head = newNode;
			return;
		}
		
		Node* current = head;
		for(int i=0; i<pos-1; i++) current = current->next;
		
		if(current == nullptr){
			cout << "Out of bounds!\n";
			delete current;
			return;
		}
		
		newNode->next = current->next;
		current->next = newNode;
	}
	
	void printll(Node*& head) {
		Node* current = head;
		while(current != nullptr) {
			cout << current->value;
			if(current->next != nullptr) cout << " -> ";
			current = current->next;
		}
		cout << endl;
	}
	
	int len(Node*& head) {
		Node* current = head;
		int i=0;
		for(; current != nullptr; i++) current = current->next;
		
		return i;
	}
	
	void delBeg(Node*& head) {
		if(head == nullptr) return;
		
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	
	void delEnd(Node*& head) {
		if(head == nullptr) return; // null ll;
		
		if(head->next == nullptr) { // 1 element;
			delete head;
			head = nullptr;
			return;
		}
		
		Node* current = head;
		while(current->next->next != nullptr) current = current->next;
		
		delete current->next;
		current->next = nullptr;
	}
	
	void delPos(Node*& head, int pos) {
		if(head == nullptr) return;
		
		if(pos == 0) {
			Node* temp = head;
			head = temp->next;
			delete temp;
			return;
		}
		
		Node* current = head;
		for(int i=0; i < pos-1 && current->next != nullptr; i++) current = current->next;
		
		if(current->next == nullptr) return;
		
		Node* temp = current->next;
		current->next = temp->next;
		delete temp;
	}
}

namespace ll_adv {
	void reverse(Node*& head) {
		Node* current = head;
		if(current->next == nullptr || current == nullptr) return;
		
		Node* prev = nullptr;
		Node* current = head;
		Node* next = nullptr;
		
		while(current != nullptr) {
			next = current->next;
			current->next = prev;
			
			prev = current;
			current = next;
		}
	}
}

int main() {
	Node* head = new Node(6);
	
	ll::addBeg(head, 5);
	ll::addBeg(head, 7);
	ll::addBeg(head, 5);
	ll::addBeg(head, 2);
	ll::addBeg(head, 2);
	
	ll::addPos(head, 3, 4);
	ll::addPos(head, 0, 8);
	ll::addPos(head, 2, 11);
	
	ll::addEnd(head, 3);
	ll::addEnd(head, 4);
	ll::addEnd(head, 6);
	
	ll::printll(head);
}
