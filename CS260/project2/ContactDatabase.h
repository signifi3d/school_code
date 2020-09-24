/*
	ContactDatabase.h
	Blake Eakin
	CS 260
	Project 2
	4/29/2019

	class prototypes for ContactDatabase, responsible for interfacing with the storage and retrieval
	of old customer contact information.
*/
#pragma once

#include "CustomerContact.h"
#include <fstream>

class ContactDatabase {
	public:
		ContactDatabase();
		~ContactDatabase();
		void store(const CustomerContact*);
		void display();
	private:
		std::fstream *db;
};
