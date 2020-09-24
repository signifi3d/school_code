/* CarList.cpp
 * By: Blake Eakin
 * Date: 10/16/2018
 *
 * Implementation of CarList class functions.
 */

 #include "CarList.h"
 #include <iostream>
 #include <iomanip>

const char LINEBREAK[] =  "+-------+--------------------------------------------------+-------------+-----------+--------------+------------+-------------+--------------+-------------+--------+";


 CarList::CarList(int initSize = 0) {
	size = initSize;
	list = new CarType[size];
 }

 CarList::~CarList() {
	delete [] list;
 }

CarList::CarList(const CarList& toCopy) {
	for (int i = 0; i < size; i++) {
		delete &list[i];
	}
	size = toCopy.size;
	list = new CarType[size];
	
	for (int i = 0; i < size; i++) {
		list[i] = toCopy.list[i];
	}
}

CarList& CarList::operator=(const CarList& toAssign) {
	for (int i = 0; i < size; i++) {
		delete &list[i];
	}
	size = toAssign.size;
	list = new CarType[size];
	
	for (int i = 0; i < size; i++) {
		list[i] = toAssign.list[i];
	}

	return *this;
}

std::ostream& operator<<(std::ostream& out, const CarList& outList) {
	out << LINEBREAK << std::endl;
	out << "| " << std::setw(6) << "Index" << "| " << std::setw(49) << std::left << "Car Name" << "| " << std::setw(12) << "MGP" << "| " << std::setw(10) << "Cylinders" << "| " << std::setw(13) << "Displacement" << "| " << std::setw(11) << "Horsepower" << "| " << std::setw(12) << "Weight" << "| " << std::setw(13) << "Acceleration" << "| " << std::setw(12) << "Model" << "| " << std::setw(7) << "Origin" << "|" << std::endl;
	out << LINEBREAK << std::endl;

	for (int i = 0; i < outList.size; ++i) {
		out << outList.list[i] << std::endl; 
		out << LINEBREAK << std::endl;
		if (i % 25 == 0) {
			out << "| " << std::setw(6) << "Index" << "| " << std::setw(49) << std::left << "Car Name" << "| " << std::setw(12) << "MGP" << "| " << std::setw(10) << "Cylinders" << "| " << std::setw(13) << "Displacement" << "| " << std::setw(11) << "Horsepower" << "| " << std::setw(12) << "Weight" << "| " << std::setw(13) << "Acceleration" << "| " << std::setw(12) << "Model" << "| " << std::setw(7) << "Origin" << "|" << std::endl;
			out << LINEBREAK << std::endl;
		}
	}
	
	return out;
}

int CarList::getSize() const {
	return size;
}

CarType* CarList::getCarAt(int carIndex) const {
	return &list[carIndex];
}

void CarList::addCar(CarType* inCar) {
	CarType* newList = new CarType[++size];
	
	for (int i = 0; i < size-1; i++) {
		newList[i] = list[i];
	}
	newList[size-1] = *inCar;	
	delete [] list;
	list = newList;
	if (list[size-1].getIndex() == 0) {
		list[size-1].setIndex(size-1);
	}

	return;
}

void CarList::removeCarAt(int removalIndex) {
	CarType* newList = new CarType[--size];
	int offset = 0;

	for (int i = 0; i < size; i++) {
		if (i == removalIndex) { 
			++offset;
		}
		newList[i] = list[i+offset];
		if (offset > 0) {
			newList[i].setIndex(i);
		}
	}
	delete [] list;

	list = newList;

	return;
}
