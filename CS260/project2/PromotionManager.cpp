/*
	PromotionManager.cpp
	Blake Eakin
	CS 260
	Project 2
	4/29/2019

	Class function implementations for PromotionManager
*/

#include "PromotionManager.h"
#include "ContactList.h"
#include "CustomerContact.h"
#include "ContactDatabase.h"
#include <iostream>


PromotionManager* PromotionManager::managerInstance = nullptr;



//Constructor
PromotionManager::PromotionManager() {}



//Destructor
PromotionManager::~PromotionManager() {}



//Returns manager instance
PromotionManager* PromotionManager::manager() {
	if ( managerInstance == nullptr ) 
		managerInstance = new PromotionManager();
	return managerInstance;
}



//Takes in CustomerContact, stores contact information in promotionContacts
void PromotionManager::storeContact(const CustomerContact* newCustomer) {
	promotionContacts.push(newCustomer);
}



//Displays most recent contact information and stores it in the contact database
void PromotionManager::getMostRecentContact() {
	ContactDatabase dbStream;
	const CustomerContact* mostRecent;
	CustomerContact* toStore;
	
	try {
		mostRecent = promotionContacts.peek();

		std::cout << "Name: " << mostRecent->name << std::endl;
		std::cout << "Email: " << mostRecent->email << std::endl;

		toStore = promotionContacts.pop();

		dbStream.store(toStore);

		delete toStore;
	} catch (const char* error) {
		throw error;
	}
}



//Displays all contact information stored from the contact database
void PromotionManager::displayPreviousContacts() {
	ContactDatabase dbStream;
	
	dbStream.display();
}
