/*
	PromotionManager.h
	Blake Eakin
	CS 260
	Project 2
	4/29/2019

	Class prototype for managing promotional contacts.
*/
#pragma once

#include "ContactList.h"
#include "CustomerContact.h"

class PromotionManager {
	public:
		~PromotionManager();
		static PromotionManager* manager();
		void storeContact(const CustomerContact*);
		void getMostRecentContact();
		void displayPreviousContacts();
	private:
		static PromotionManager* managerInstance;
		PromotionManager();
		ContactList promotionContacts;
};
