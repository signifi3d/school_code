/*
	ContactList.h
	Blake Eakin
	CS 260
	Project 2
	4/25/2019

	Class definition of stack containing most recent customers interested in promotional material.
*/
#pragma once

#include "CustomerContact.h"

class ContactList {
	public:
		ContactList();
		~ContactList();
		void push(const CustomerContact*);
		CustomerContact* pop();
		const CustomerContact* peek();
		void display();
	private:
		CustomerContact** promotionalList;
		int top;
};
