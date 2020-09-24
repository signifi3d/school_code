/*
	CustomerContact.cpp
	Blake Eakin
	CS 260
	Project 2
	4/23/2019

	Implements constructors of CustomerContact struct.
*/

#include "CustomerContact.h"
#include "string.h"



//data provided constructor
CustomerContact::CustomerContact(const char* newName, const char* newEmail) {
	name = new char[strlen(newName)];
	strcpy(name, newName);
	email = new char[strlen(newEmail)];
	strcpy(email, newEmail);
}



//copy constructor
CustomerContact::CustomerContact(const CustomerContact& toCopy) {
	name = new char[strlen(toCopy.name)];
	strcpy(name, toCopy.name);
	email = new char[strlen(toCopy.email)];
	strcpy(email, toCopy.email);
}



//destructor
CustomerContact::~CustomerContact() {
	delete name;
	delete email;
}
