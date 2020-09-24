//array.cpp 

#include "array.h"
#include <iostream>


int numOfEven(int list[], int size) {
	int count = 0;
	for (int i = 0; i < size; ++i) {
		if (list[i] % 2 == 0) ++count;
	}

	return count;
}

void insert(int list[], int& size, int newInt, int position) {
	int swap = 0;
	++size;
	for (int i = size-1; i > position; --i) {
		list[i] = list[i-1];
	}
	list[position] = newInt;
}
