#include "list.h"
#include <iostream>
using namespace std;

bool insert(int position, int val, int intList[], int& size)
{	
	if (position > size) return false;
	if (size == 0) {
		intList[position] = val;
		++size;
		return true;
	}

	int swap = 0;
	++size;
	for (int i = position; i < size; i++) {
		swap = intList[i];
		intList[i] = val;
		val = swap;
	}

	return true;
}

bool remove(int position, int& val, int intList[], int& size)
{
	if (position >= size) return false;
	if (position == size-1) {
		val = intList[position];
		intList[position] = 0;
		--size;
		return true;
	}
	val = intList[position];
	for (int i = position + 1; i < size; i++) {
		intList[i-1] = intList[i];
	}
	--size;

	return true;
}

void print(const int intList[], int size)
{
	cout << endl << "[ ";
	for(int i=0; i<size; i++)
	{
		cout << intList[i] << " ";
	}
	cout << "]" << endl;
}



