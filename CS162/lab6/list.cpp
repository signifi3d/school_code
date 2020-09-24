#include "list.h"
#include <iostream>

LinkedList::LinkedList() {
	head = tail = nullptr;
}

bool LinkedList::addAtBeginning(int val) {
	Node* insertNode = new Node();
	insertNode->data = val;
	insertNode->next = insertNode->prev = nullptr;
	if (head == nullptr) {
		head = tail = insertNode;
	}
	else {
		insertNode->next = head;
		head->prev = insertNode;
		head = insertNode;
	}

	return true;
}

bool LinkedList::remove(int val) {
	Node* iterator = head;
	while (iterator != nullptr) {
		if (iterator->data == val) {
			if (iterator->next != nullptr) {
				iterator->next->prev = iterator->prev;
			}
			else {
				tail = iterator->prev;
			}
			if (iterator->prev != nullptr) {
				iterator->prev->next = iterator->next;
			}
			else {
				head = iterator->next;
			}
			delete iterator;
			return true;
		}
		iterator = iterator->next;
	}
	return false;
}

void LinkedList::printForward() const {
	Node* iterator = head;
	while (iterator != nullptr) {
		std::cout << iterator->data << " ";
		iterator = iterator->next;
	}
	std::cout << std::endl;

	return;
}

void LinkedList::printBackward() const {
	Node* iterator = tail;
	while (iterator != nullptr) {
		std::cout << iterator->data << " ";
		iterator = iterator->prev;
	}
	std::cout << std::endl;

	return;
}
