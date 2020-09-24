// Write your functions in this file.
#include "clist.h"

int count(node * head) {
	if ( head == nullptr )
		return 0;
	
	node * curr = head->next;
	int count = 1;

	while ( curr != head ) {
		++count;
		curr = curr->next;
	}

	return count;
}

int countR(node * head) {
	return _countR(head, head->next);
}

int _countR(node * head, node * curr) {
	if ( curr == head )
		return 1;
	else
		return 1 + _countR(head, curr->next);
}

int sum(node * head) {
	if ( head == nullptr )
		return 0;

	node * curr = head->next;
	int sum = head->data;

	while ( curr != head ) {
		sum += curr->data;
		curr = curr->next;
	}

	return sum;
}

int sumR(node * head) {
	return _sumR(head, head->next);
}

int _sumR(node * head, node * curr) {
	if ( curr == head )
		return head->data;

	else
		return curr->data + _sumR(head, curr->next);
}
