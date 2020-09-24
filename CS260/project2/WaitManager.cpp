/*
	WaitManager.cpp
	Blake Eakin
	CS 260
	Project 2
	4/25/2019

	Implements all WaitManager class functions.
*/

#include "WaitManager.h"
#include "PromotionManager.h"
#include "PartyQueue.h"
#include "PartyInfo.h"
#include <iostream>
#include "string.h"

WaitManager* WaitManager::managerInstance = nullptr;



//Constructor
WaitManager::WaitManager() {}



//Destructor
WaitManager::~WaitManager() {
	delete managerInstance;
}



//returns the static instance of the class
WaitManager* WaitManager::manager() {
	if ( managerInstance == nullptr )
		managerInstance = new WaitManager();
	return managerInstance;
}



//creates a new party with the passed info and adds it to the back of the queue
void WaitManager::addParty(const char* partyName, int partySize, const char* accom, const char* contactName, const char* contactEmail) {
	PartyInfo* newParty = new PartyInfo();

	newParty->partyName = new char[strlen(partyName)];
	strcpy(newParty->partyName, partyName);
	newParty->partySize = partySize;
	if ( accom != nullptr ) {
		newParty->accommodations = new char[strlen(accom)];
		strcpy(newParty->accommodations, accom);
	}
	if ( contactName != nullptr ) {
		newParty->promoOptIn = new CustomerContact();
		newParty->promoOptIn->name = new char[strlen(contactName)];
		strcpy(newParty->promoOptIn->name, contactName);
		newParty->promoOptIn->email = new char[strlen(contactEmail)];
		strcpy(newParty->promoOptIn->email, contactEmail);

		PromotionManager::manager()->storeContact(newParty->promoOptIn);
	}

	waitlist.enqueue(newParty);
	delete newParty;
}



//wrapper for the PartyQueue display function
void WaitManager::displayWaitlist() {
	try {
		waitlist.display();
	} catch (const char* error) {
		throw error;
	}
}



//displays the information for the next party in line
void WaitManager::nextPartyInLine() {
	const PartyInfo* nextInLine;
	try {
		nextInLine = waitlist.peek();
	} catch (const char* error) {
		throw error;
	}

	std::cout << "Next Party In Line: " << std::endl;
	std::cout << "Party Name: " << nextInLine->partyName << std::endl;
	std::cout << "Party Size: " << nextInLine->partySize << std::endl;
	std::cout << "Accommodations: ";
	
	if ( nextInLine->accommodations != nullptr )
		std::cout << nextInLine->accommodations << std::endl;
	else
		std::cout << "None." << std::endl;
}



//Removes the next party from the queue, displays their information
void WaitManager::seatNextParty() {
	PartyInfo* seatedParty;
	try {
		seatedParty = waitlist.dequeue();
	} catch (const char* error) {
		throw error;
	}

	std::cout << seatedParty->partyName << " is ready to be seated." << std::endl;

	delete seatedParty;
}
