/* CarType.cpp
 * By: Blake Eakin
 * Date: 12/1/2018
 * 
 * Implements CarType class functions.
 */

#include <cstring>
#include "CarType.h"
#include <iostream>
#include <iomanip>

CarType::CarType() {
	carName = new char[50];
	mpg = 0.0;
	cylinders = 0;
	displacement = 0.0;
	horsepower = 0.0;
	weight = 0.0;
	acceleration = 0.0;
	model = 0;
	origin = US;
	index = 0;
}

CarType::~CarType() {
	delete [] carName;
}

CarType::CarType(const CarType& toCopy) {
	strcpy(carName, toCopy.carName);
	mpg = toCopy.mpg;
	cylinders = toCopy.cylinders;
	displacement = toCopy.displacement;
	horsepower = toCopy.horsepower;
	weight = toCopy.weight;
	acceleration = toCopy.acceleration;
	model = toCopy.model;
	origin = toCopy.origin;
	index = toCopy.index;
}

CarType& CarType::operator=(const CarType& toAssign) {
	strcpy(carName, toAssign.carName);
	mpg = toAssign.mpg;
	cylinders = toAssign.cylinders;
	displacement = toAssign.displacement;
	horsepower = toAssign.horsepower;
	weight = toAssign.weight;
	acceleration = toAssign.acceleration;
	model = toAssign.model;
	origin = toAssign.origin;
	index = toAssign.index;

	return *this;
}

std::ostream& operator<<(std::ostream& out, const CarType& toOut) {
	std::cout << "| " << std::setw(6) << toOut.index <<  "| " << std::setw(49) << std::left << toOut.carName << "| " << std::setw(12) << toOut.mpg << "| " << std::setw(10) << toOut.cylinders << "| " << std::setw(13) << toOut.displacement << "| " << std::setw(11) << toOut.horsepower << "| " << std::setw(12) << toOut.weight << "| " << std::setw(13) << toOut.acceleration << "| " << std::setw(12) << toOut.model << "| ";
	switch (toOut.origin) {
		case 0:
			std::cout << std::setw(7) << "US" << "|";
			break;
		case 1:
			std::cout << std::setw(7) << "Europe" << "|";
			break;
		case 2:
			std::cout << std::setw(7) << "Japan" << "|";
			break;
		default:
			std::cout << std::setw(7) << "Unknown" << "|" ; 
	}
	
	return out;
}

void CarType::setName(char* inName) {
	strcpy(carName, inName);
}

void CarType::setMPG(double inMPG) {
	mpg = inMPG;
}

void CarType::setCylinders(int inCyl) {
	cylinders = inCyl;
}

void CarType::setDisplacement(double inDis) {
	displacement = inDis;
}

void CarType::setHorsepower(double inHorse) {
	horsepower = inHorse;
}

void CarType::setWeight(double inWeight) {
	weight = inWeight;
}

void CarType::setAcceleration(double inAcc) {
	acceleration = inAcc;
}

void CarType::setModel(int inModel) {
	model = inModel;
}

void CarType::setOrigin(Cat inOrigin) {
	origin = inOrigin;
}

 char* CarType::getName() {
	return carName;
}

 double CarType::getMPG()   {
	return mpg;
}

 int CarType::getCylinders()   {
	return cylinders;
}

 double CarType::getDisplacement()   {
	return displacement;
}

 double CarType::getHorsepower()   {
	return horsepower;
}

 double CarType::getWeight()   {
	return weight;
}

 double CarType::getAcceleration()   {
	return acceleration;
}

 int CarType::getModel()   {
	return model;
}

 Cat CarType::getOrigin()   {
	return origin;
}

int CarType::getIndex() {
	return index;
}

void CarType::setIndex(int i) {
	index = i;
}
