#include "list.h"

int countEven(node * head) {
	node *curr = head;
	int count = 0;

	while ( curr != NULL ) {
		if ( curr->data % 2 == 0 ) {
			++count;
		}

		curr = curr->next;
	}

	return count;
}

int removeEven(node *& head) {
	node *curr = NULL;
	int count = 0;
	while ( head->data % 2 == 0 ) {
		++count;
		head = head->next;
	}

	curr = head;

	while ( curr->next != NULL ) {
		if ( curr->next->data % 2 == 0 ) {
			++count;
			curr->next = curr->next->next;
			continue;
		}

		curr = curr->next;
	}

	return count;
}
