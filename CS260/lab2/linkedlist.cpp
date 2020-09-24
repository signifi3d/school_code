#include "linkedlist.h"
#include <ostream>
#include <iostream>

LinkedList::LinkedList():head(nullptr) { }

LinkedList::~LinkedList() {

}

void LinkedList::add( char ch ) {
	Node** curr = &head;

	while ( *curr != nullptr ) {
		curr = &((*curr)->next);
	}

	*curr = new Node();
	(*curr)->data = ch;
	
}

bool LinkedList::find( char ch ) {
	Node* curr = head;

	while ( curr != nullptr ) {
		if ( curr->data == ch ) 
			return true;
		curr = curr->next;
	}

	return false;
}

bool LinkedList::del( char ch ) {
	Node** curr = &head;
	Node* temp = nullptr;

	while ( *curr != nullptr ) {
		if ( (*curr)->data == ch ) {
			temp = *curr;
			*curr = (*curr)->next;
			delete temp;

			return true;
		}

		curr = &((*curr)->next);
	}

	return false;
}

std::ostream& operator<<(std::ostream& out, LinkedList& list) {
	Node* curr = list.head;

	while ( curr != nullptr ) {
		out << curr->data;
		curr = curr->next;
	}
	out << std::endl;

	return out;
}
