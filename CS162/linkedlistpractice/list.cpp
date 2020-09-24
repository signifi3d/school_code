#include "list.h"
#include <vector>

int sumOfList(node * head) {
	int sum = 0;
	node * curr = head;
	while (curr != NULL) {
		sum += curr->data;
		curr = curr->next;
	}

	return sum;
}

void insert(node *& head, int position, int newInt) {
	node * insertNode = new node();
	insertNode->data = newInt;
	node * curr = head;
	if ( position == 0 ) {
		insertNode->next = curr;
		head = insertNode;
		return;
	}
	for (int i = 0; i < position-1; i++) {
		curr = curr->next;
	}
	insertNode->next = curr->next;
	curr->next = insertNode;

	return;
}

bool hasCycle(node * head) {
	std::vector<node*> visitedNodes;
	node * curr = head;
	while ( curr != NULL ) {
		visitedNodes.insert(&curr);
		curr = curr->next;
	}
	return false;
}
