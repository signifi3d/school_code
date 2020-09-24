/* CarType.cpp
 * By: Blake Eakin
 * Date: 10/16/2018
 * 
 * Implements CarType class functions.
 */

#include <cstring>
#include "CarType.h"


CarType::CarType() {
	strcpy(carName, " ");
	mpg = 0.0;
	cylinders = 0;
	displacement = 0.0;
	horsepower = 0.0;
	weight = 0.0;
	acceleration = 0.0;
	model = 0;
	origin = US;
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

double CarType::getMPG() {
	return mpg;
}

int CarType::getCylinders() {
	return cylinders;
}

double CarType::getDisplacement() {
	return displacement;
}

double CarType::getHorsepower() {
	return horsepower;
}

double CarType::getWeight() {
	return weight;
}

double CarType::getAcceleration() {
	return acceleration;
}

int CarType::getModel() {
	return model;
}

Cat CarType::getOrigin() {
	return origin;
}
