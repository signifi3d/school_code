#include "list.h"

int main()
{
	LinkedList aList;

	aList.addAtBeginning(3);
	aList.addAtBeginning(10);
	aList.addAtBeginning(1);
	aList.addAtBeginning(7);
	aList.addAtBeginning(9);
	aList.addAtBeginning(12);
	aList.printForward();
	aList.printBackward();
	aList.remove(3);
	aList.remove(1);
	aList.remove(7);
	aList.remove(12);
	aList.printForward();
	aList.printBackward();

	return 0;
}

