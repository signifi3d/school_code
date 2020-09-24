/*
	ContactDatabase.cpp
	Blake Eakin
	CS 260
	Project 2
	4/29/2019

	implementation of ContactDatabase class functions
*/

#include "ContactDatabase.h"
#include "CustomerContact.h"
#include <fstream>
#include <iostream>



//Constructor
ContactDatabase::ContactDatabase() {
	db = new std::fstream("contacts.txt");
}



//Destructor
ContactDatabase::~ContactDatabase() {
	db->close();
	delete db;
}



//Takes in customer contact information and stores it in database file.
void ContactDatabase::store(const CustomerContact* newContact) {
	db->seekp(0, db->end);
	(*db) << newContact->name << std::endl;
	(*db) << newContact->email << std::endl;
}



//Writes all the contents of the database to standard out
void ContactDatabase::display() {
	char *dbInput = new char[500];
	db->seekg(0, db->beg);

	while ( db->getline(dbInput, 500) ) {
		std::cout << dbInput << std::endl;
	}

	delete dbInput;
}
