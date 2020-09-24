#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

struct Node {
	Node* next = nullptr;
	char data;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(char ch);
	bool find(char ch);
	bool del(char ch);

	friend std::ostream& operator<<(std::ostream& out, LinkedList& list);
private:
	Node* head;
};

#endif // _LINKED_LIST_
