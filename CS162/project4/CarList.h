/* CS 162 Online Project 3
 * By: Blake Eakin
 * Date: 10/16/2018
 * 
 * Class definition of list to hold Car database information.
 */

#include "CarType.h"
#include <iostream>

#ifndef CARLIST_H
#define CARLIST_H

 class CarList {
	public:

	CarList(int);
	~CarList();
	CarList(const CarList&);
	CarList& operator=(const CarList&);
	friend std::ostream& operator<<(std::ostream&,const CarList&);
	int getSize() const;
	CarType* getCarAt(int) const;
	void addCar(CarType*);
	void removeCarAt(int);

	private:
	
	int size;
	CarType* list;
 };

 #endif
