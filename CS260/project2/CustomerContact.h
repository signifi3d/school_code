/*
	CustomerContact.h
	Blake Eakin
	CS 260
	Project 2
	4/23/2019

	Defines the structure holding the customer contact information to receive promotional materials.
*/

#pragma once

struct CustomerContact {
	char* name;
	char* email;

	CustomerContact():name(nullptr),email(nullptr) {}
	CustomerContact(const char*, const char*);
	CustomerContact(const CustomerContact&);
	~CustomerContact();
};
