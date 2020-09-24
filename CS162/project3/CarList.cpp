/* CarList.cpp
 * By: Blake Eakin
 * Date: 10/16/2018
 *
 * Implementation of CarList class functions.
 */

 #include "CarList.h"

 CarList::CarList() {
	size = 0;
 }

int CarList::getSize() const {
	return size;
}

CarType CarList::getCarAt(int carIndex) {
	return list[carIndex];
}

void CarList::addCar(CarType& inCar) {
	
	list[size++] = inCar;

	return;
}

void CarList::removeCarAt(int removalIndex) {

	for (int i = removalIndex+1; i < size; i++) {
		list[i-1] = list[i];
	}
	--size;

	return;
}
