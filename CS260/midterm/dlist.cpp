#include "dlist.h"
#include <iostream>

//put the implmenetation of the required functions here
int countEven(node * head) {
	if ( head->next == nullptr ) {
		if ( head->data % 2 == 0 )
			return 1;
		else
			return 0;
	}
	else {
		if ( head->data % 2 == 0 )
			return 1 + countEven(head->next);
		else
			return countEven(head->next);
	}
}

int removeEven(node *& head) {
	if ( head == nullptr )
		return 0;
	if ( head->data % 2 == 0 ) {
		node * del = head;
		if ( head->next != nullptr )
			head->next->previous = head->previous;
		if ( head->previous != nullptr ) {
			head->previous->next = head->next;
			delete del;
			return 1 + removeEven(head);
		}
		else {
			head = head->next;
			delete del;
			return 1 + removeEven(head);
		}
		delete del;
		return 1 + removeEven(head->next);
	} else {
		return removeEven(head->next);
	}
	
}
