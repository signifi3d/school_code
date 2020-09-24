/*
	PartyQueue.h
	Blake Eakin
	CS 260
	Project 2
	4/23/2019

	Definition of a class for managing the queue of parties in line for a table at a restaurant.
	Implements a queue using a circular linked list.
*/

#pragma once

#include "PartyInfo.h"

class PartyQueue {
	public:
		PartyQueue();
		~PartyQueue();
		void enqueue(const PartyInfo*);
		PartyInfo* dequeue();
		const PartyInfo* peek();
		void display();
	private:
		PartyInfo* head;
		PartyInfo* tail;
		
		void _display(const PartyInfo*);

};
