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

void LinkedList::add(char ch) {
	append(head, ch);
}

void LinkedList::append(Node*& curr, char ch) {
	if ( !curr ) {
		curr = new Node();
		curr->data = ch;
	}
	else
		append(curr->next, ch);
}

bool LinkedList::find(char ch) {
	return seek(head, ch);
}

bool LinkedList::seek(Node* curr, char ch) {
	if ( !curr )
		return false;
	else if ( curr->data == ch ) 
		return true;
	else
		return seek(curr->next, ch);
}

bool LinkedList::del(char ch) {
	return remove(head, ch);
}

bool LinkedList::remove(Node *& curr, char ch) {
	if ( !curr )
		return false;
	else if ( curr->data == ch ) {
		Node* temp = curr;
		curr = curr->next;
		delete temp;
		return true;
	} else 
		return remove(curr->next, ch);
}

std::ostream& operator<<(std::ostream& out, LinkedList& list) {
	return list.print(list.head, out);
}

std::ostream& LinkedList::print(Node* curr, std::ostream& out) {
	if (curr) {
		out << curr->data << std::endl;
		return print(curr->next, out);
	} else
		return out;
}
