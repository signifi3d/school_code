//array.cpp 

#include "array.h"


int sumOfArray(int list[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += list[i];
	}

	return sum;
}

int remove(int list[], int& size, int target) {
	int count = 0;
	
	for (int i = 0; i < size; ++i) {
		if (list[i]==target) {
			++count;
			continue;
		}
		else if (count > 0) {
			list[i-count]=list[i];
		}
	}

	size -= count;

	return count;
}

