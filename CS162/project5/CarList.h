/* CS 162 Online Project 5
 * By: Blake Eakin
 * Date: 12/1/2018
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
	
	struct Node {
		Node* next = NULL;
		CarType* carData = NULL;
		~Node() { delete carData; }
	};
	int size;
	Node* head;
	Node* tail;
 };

 #endif
