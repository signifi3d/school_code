#include <math.h>
#include <iostream>
#include "BigInt.h"

BigInt::BigInt() {
	this->digits = 1;
	this->numArray = new int[digits]();
	this->numArray[0]=0;
}

std::ostream &operator<<(std::ostream &out, const BigInt& toOut) {
	for(int i = toOut.placesNum()-1; i >= 0; i--) {
		out<<toOut[i];
	}
	return out;
}

BigInt &BigInt::operator+(int const &add) {
	
	int toAdd = add, addPlaces = 1;
	while (toAdd/(int)std::pow(10, addPlaces) != 0) {
		addPlaces++;
	}
	int j;
	
	if (addPlaces > this->digits) {
		this->newPlaces(addPlaces - this->digits);
		j = this->digits;
	}	
	else j=addPlaces;

	for (int i = 0; i < j; i++) {
		this->numArray[i] += toAdd % 10;
		toAdd/=10;
		if (this->numArray[i] > 9) {
			this->carryover(i);	
		}
	}
	return *this;
}

BigInt &BigInt::operator=(int const &eq) {
	int toEq = eq;
	int eqDigits = 1;
	while (toEq/(int)std::pow(10,eqDigits) != 0) {
		eqDigits++;
	}
	if (eqDigits > this->digits) {
		this->newPlaces(eqDigits-digits);
	}
	for( int i = 0; i < eqDigits; i++) {
		this->numArray[i] = toEq % 10;
		toEq/=10;
	}

	return *this;
}

int &BigInt::operator[](const int &index) const {
	return numArray[index];
}

int BigInt::placesNum() const  {
	return digits;
}

void BigInt::newPlace(int const &toAppend) {
	int* swapArray = new int[this->digits+1];
	swapArray[this->digits] = toAppend;
	for (int i = this->digits-1; i >= 0; i--) {
		swapArray[i]=this->numArray[i];
	}

	//delete [] numArray;
	this->numArray = swapArray;
	//delete[] swapArray;
	this->digits++;
	//delete statements were causing Segmentation Faults, but I don't really know why, will need to investigate in the future
}

void BigInt::newPlaces(int const& numOfPlaces) {
	int* swapArray = new int[digits+numOfPlaces]();
	for (int i = digits-1; i >=0; i--) {
		swapArray[i]=numArray[i];
	}
	delete[] numArray;
	numArray = swapArray;
	delete[] swapArray;
	digits+= numOfPlaces;
}

void BigInt::carryover(int const &index) {
	if ( digits == index+1 ) {
		numArray[index]%=10;
		newPlace(1);
	}
	else {
		numArray[index+1]++;
		numArray[index]%=10;
		if (numArray[index+1] > 9) carryover(index+1);
	}
}
