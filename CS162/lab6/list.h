#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class LinkedList
{
private:
	struct Node
	{
		int data;
		Node * next;
		Node * prev;
	};
	Node * head, * tail;
public:
	LinkedList();
	bool addAtBeginning(int val);
	bool remove(int val);
	void printForward() const;
	void printBackward() const;
};


#endif
