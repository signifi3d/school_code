#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

struct Node {
	Node* next;
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

	void append(Node*& curr, char ch);
	bool seek(Node* curr, char ch);
	bool remove(Node*& curr, char ch);
	std::ostream& print(Node* curr, std::ostream& out);

};

#endif // _LINKED_LIST_
