/* CS 162 Online Project 3
 * By: Blake Eakin
 * Date: 10/16/2018
 * 
 * Class definition of list to hold Car database information.
 */

#include "CarType.h"

#ifndef CARLIST_H
#define CARLIST_H

 class CarList {
	public:

	CarList();
	int getSize() const;
	CarType getCarAt(int);
	void addCar(CarType&);
	void removeCarAt(int);

	private:
	
	int size;
	CarType list[500];
 };

 #endif
