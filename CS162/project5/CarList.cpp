/* CarList.cpp
 * By: Blake Eakin
 * Date: 12/1/2018
 *
 * Implementation of CarList class functions.
 */

 #include "CarList.h"
 #include <iostream>
 #include <iomanip>

const char LINEBREAK[] =  "+-------+--------------------------------------------------+-------------+-----------+--------------+------------+-------------+--------------+-------------+--------+";

 CarList::CarList(int initSize = 0) {
	size = initSize;
	head = tail = new Node();
 }

 CarList::~CarList() {
 	Node* iterator = head;
	Node* deleteNode = NULL;
	while (iterator != NULL) {
		deleteNode = iterator;
		iterator = iterator->next;
		delete deleteNode;
	}
 }

CarList::CarList(const CarList& toCopy) {
	size = toCopy.size;
	Node* iterator = toCopy.head;
	Node* newListIterator = head;
	while (iterator != NULL) {
		newListIterator->next = new Node();
		newListIterator = newListIterator->next;
		*newListIterator->carData = *iterator->carData;
		iterator = iterator->next;
	}
}

CarList& CarList::operator=(const CarList& toAssign) {
	size = toAssign.size;
	Node* iterator = toAssign.head;
	Node* newListIterator = head;
	while (iterator != NULL) {
		newListIterator->next = new Node();
		newListIterator = newListIterator->next;
		*newListIterator->carData = *iterator->carData;
		iterator = iterator->next;
	}

	return *this;
}

std::ostream& operator<<(std::ostream& out, const CarList& outList) {
	CarList::Node* iterator = outList.head->next;
	out << LINEBREAK << std::endl;
	out << "| " << std::setw(6) << "Index" << "| " << std::setw(49) << std::left << "Car Name" << "| " << std::setw(12) << "MGP" << "| " << std::setw(10) << "Cylinders" << "| " << std::setw(13) << "Displacement" << "| " << std::setw(11) << "Horsepower" << "| " << std::setw(12) << "Weight" << "| " << std::setw(13) << "Acceleration" << "| " << std::setw(12) << "Model" << "| " << std::setw(7) << "Origin" << "|" << std::endl;
	out << LINEBREAK << std::endl;

	for (int i = 0; i < outList.size; ++i) {
		out << *iterator->carData << std::endl; 
		out << LINEBREAK << std::endl;
		if (i % 25 == 0) {
			out << "| " << std::setw(6) << "Index" << "| " << std::setw(49) << std::left << "Car Name" << "| " << std::setw(12) << "MGP" << "| " << std::setw(10) << "Cylinders" << "| " << std::setw(13) << "Displacement" << "| " << std::setw(11) << "Horsepower" << "| " << std::setw(12) << "Weight" << "| " << std::setw(13) << "Acceleration" << "| " << std::setw(12) << "Model" << "| " << std::setw(7) << "Origin" << "|" << std::endl;
			out << LINEBREAK << std::endl;
		}
		iterator = iterator->next;
	}
	
	return out;
}

int CarList::getSize() const {
	return size;
}

CarType* CarList::getCarAt(int carIndex) const {
	Node* iterator = head->next;

	while (iterator != NULL) {
		if (iterator->carData->getIndex() == carIndex) {
			return iterator->carData;
		}
		iterator = iterator->next;
	}
	return NULL;
}

void CarList::addCar(CarType* inCar) {
	tail->next = new Node();
	tail = tail->next;
	if (inCar->getIndex() == 0) {
		inCar->setIndex(size);
	}
	tail->carData = new CarType();
	*tail->carData = *inCar;
	++size;

	return;
}

void CarList::removeCarAt(int removalIndex) {
	Node* iterator = head;
	bool nodeRemoved = false;

	for (int i = 0; i < size; ++i) {
		if (iterator->next->carData->getIndex() == removalIndex) {
			Node* nodeToRemove = iterator->next;
			iterator->next = iterator->next->next;
			delete nodeToRemove;
			--size;
			if ( i == size ) {
				tail = iterator;
				return;
			}
			nodeRemoved = true;
		}
		if (nodeRemoved == true) {
			iterator->next->carData->setIndex(iterator->next->carData->getIndex()-1);
		}
		iterator = iterator->next;
	}

	return;
}
