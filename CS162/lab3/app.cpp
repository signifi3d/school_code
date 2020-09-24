#include <iostream>
using namespace std;
#include "list.h"

const int ARRAY_CAP = 100;
int main()
{
	int aList[ARRAY_CAP];
	int size = 0;
	int val;

	print(aList, size);
	insert(0, 10, aList, size);
	insert(1, 20, aList, size);
	insert(0, 4, aList, size);
	insert(1, 40, aList, size);
	insert(2, 25, aList, size);
	print(aList, size);
	if(!remove(5, val, aList, size))
	{
		cout << "remove failed" << endl;
	}
	else
	{
		cout << val << " is removed!" << endl;
	}
	if(!remove(1, val, aList, size))
	{
		cout << "remove failed" << endl;
	}
	else
	{
		cout << val << " is removed!" << endl;
	}
	print(aList, size);
	return 0;
}
