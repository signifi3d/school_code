/*
	ContactList.cpp
	Blake Eakin
	CS 260
	Project 2
	4/25/2019

	IMplementations of ContactList class functions.
*/

#include "ContactList.h"
#include "CustomerContact.h"
#include <iostream>
#include "string.h"



//Constructor
ContactList::ContactList() {
	promotionalList = new CustomerContact*[100];
	top = -1;
}



//Destructor
ContactList::~ContactList() {
}



//Takes a pointer to a CustomerContact and pushes its contents onto the stack
void ContactList::push(const CustomerContact* newContact) {
	++top;
	promotionalList[top] = new CustomerContact(*newContact);
}



//Returns and removes the top CustomerContact from the promotionalList
CustomerContact* ContactList::pop() {
	if ( top == -1 )
		throw "List is empty.";

	CustomerContact* temp = promotionalList[top];
	promotionalList[top] = nullptr;
	--top;

	return temp;
}



//returns a constant reference to the top CustomerContact on the promotionalList
const CustomerContact* ContactList::peek() {
	if ( top == -1 )
		throw "List is empty.";
	return promotionalList[top];
}



//Outputs All of the contacts in the stack starting at the top.
void ContactList::display() {
	for (int i = top; i >= 0; --i) {
		int count = ( top - i ) + 1;
		std::cout << "Promotional Contact " << count << ":" << std::endl;
		std::cout << "Name: " << promotionalList[i]->name << std::endl;
		std::cout << "Email: " << promotionalList[i]->email << std::endl << std::endl;
	}
}


