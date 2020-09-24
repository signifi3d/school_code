/*
	PartyInfo.cpp
	Blake Eakin
	CS 260
	Project 2
	4/23/2019

	Implements copy constructor and destructor for PartyInfo struct
*/

#include "PartyInfo.h"
#include "string.h"
#include <iostream>

//Copy Constructor
PartyInfo::PartyInfo(const PartyInfo& toCopy) {
	partyName = new char[strlen(toCopy.partyName)];
	strcpy(partyName, toCopy.partyName);
	partySize = toCopy.partySize;
	if ( toCopy.accommodations != nullptr ) {
		accommodations = new char[strlen(toCopy.accommodations)];
		strcpy(accommodations, toCopy.accommodations);
	} else
		accommodations = nullptr;
	if ( toCopy.promoOptIn != nullptr )
		promoOptIn = new CustomerContact(*(toCopy.promoOptIn));
	else
		promoOptIn = nullptr;

	next = toCopy.next;
}



//destructor
PartyInfo::~PartyInfo() {
	delete partyName;
	delete accommodations;
	delete promoOptIn;
	delete next;
}
