#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>


class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(int val);
	bool find(int val);
	bool del(int val);
	int sum();				// sum of ints in list, calculated iteratively
	int sumR();				// sum of ints in list, calculated recursively

	friend std::ostream& operator<<(std::ostream& out, LinkedList& list);
private:
	struct Node
	{
		Node(int value) : value(value), next(nullptr) {}
		Node(int value, Node* next) : value(value), next(next) {}

		int		value;
		Node*	next;
	};
	Node* head;

	void append(Node*& curr, int val);
	bool seek(Node* curr, int val);
	bool remove(Node*& curr, int val);
	int _sumR(Node* curr);
	std::ostream& print(Node* curr, std::ostream& out);

};

#endif // _LINKED_LIST_
