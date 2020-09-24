#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList():head(nullptr) {}

LinkedList::~LinkedList() {
	Node* temp;
	while (head) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

void LinkedList::add(int val) {
	append(head, val);
}

void LinkedList::append(Node*& curr, int val) {
	if ( !curr ) {
		curr = new Node(val);
	}
	else
		append(curr->next, val);
}

bool LinkedList::find(int val) {
	return seek(head, val);
}

bool LinkedList::seek(Node* curr, int val) {
	if ( !curr )
		return false;
	else if ( curr->value == val ) 
		return true;
	else
		return seek(curr->next, val);
}

bool LinkedList::del(int val) {
	return remove(head, val);
}

bool LinkedList::remove(Node *& curr, int val) {
	if ( !curr )
		return false;
	else if ( curr->value == val ) {
		Node* temp = curr;
		curr = curr->next;
		delete temp;
		return true;
	} else 
		return remove(curr->next, val);
}

int LinkedList::sum() {
	Node* curr = head;
	int sum = 0;

	while ( curr != nullptr ) {
		sum += curr->value;
		curr = curr->next;
	}
	
	return sum;
}

int LinkedList::sumR() {
	return _sumR(head);
}

int LinkedList::_sumR(Node* curr) {
	if ( curr == nullptr )
		return 0;
	else
		return curr->value + _sumR(curr->next);
}

std::ostream& operator<<(std::ostream& out, LinkedList& list) {
	return list.print(list.head, out);
}

std::ostream& LinkedList::print(Node* curr, std::ostream& out) {
	if (curr) {
		out << curr->value << std::endl;
		return print(curr->next, out);
	} else
		return out;
}
