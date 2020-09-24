/*
	driver.cpp
	Blake Eakin
	CS 260
	Project 2
	4/23/2019

	contains the main entry point for the program, user interfaces, and tests.
*/

#include "PromotionManager.h"
#include "WaitManager.h"
#include "utilities.h"
#include <iostream>
#include <fstream>
#include "string.h"

void menuLoop();
void addParty();
void seatNextParty();
void viewWaitList();
void viewNextPromotionContact();
void displayContacts();
void importWaitList();

int main() {
	
	importWaitList();
	menuLoop();

	return 0;
}



//Controls the flow of the UI through a looping menu until user exits
void menuLoop() {
	char * userInput = new char[50];
	bool exitSet = false;

	do {
		std::cout << "1. View wait list." << std::endl;
		std::cout << "2. Add new party to wait list." << std::endl;
		std::cout << "3. Seat the next party." << std::endl;
		std::cout << "4. View most recent promotion contact." << std::endl;
		std::cout << "5. Display all previous promotion contacts." << std::endl;
		std::cout << "X. Exit." << std::endl;
		std::cout << "Choice: ";
		std::cin.getline(userInput, 50);
		flushCin();
		std::cout << std::endl;

		if ( !strcmp(userInput, "1") )
			viewWaitList();
		else if ( !strcmp(userInput, "2") )
			addParty();
		else if ( !strcmp(userInput, "3") )
			seatNextParty(); 
		else if ( !strcmp(userInput, "4") )
			viewNextPromotionContact();
		else if ( !strcmp(userInput, "5") )
			displayContacts();
		else if ( !strcmp(userInput, "X") || !strcmp(userInput, "q") || !strcmp(userInput, "quit") || !strcmp(userInput, "Q") || !strcmp(userInput, "Quit")) 
			exitSet = true;
		else
			std::cout << "Invalid input. Please select a menu item by number." << std::endl;
		
		std::cout << std::endl;
	} while ( !exitSet );

	delete userInput;
}



//Controls the dialog and interface for adding a party to the wait list
void addParty() {
	char partyName[50];
	char partySize[10];
	char decision[10];
	char * accommodations = nullptr;
	char * contactName = nullptr;
	char * contactEmail = nullptr;
	
	std::cout << "Party's Name: ";
	std::cin.getline(partyName, 50);
	flushCin();

	std::cout << "Party Size: ";
	std::cin.getline(partySize, 10);
	flushCin();

	std::cout << "Does the party have any special needs? (Y/N): ";
	std::cin.getline(decision, 10);
	flushCin();
	cstrToUpper(decision);

	if ( !strcmp(decision, "Y") || !strcmp(decision, "YES") ) {
		accommodations = new char[50];
		std::cout << "What special needs will the party have? ";
		std::cin.getline(accommodations, 50);
		flushCin();
	}

	std::cout << "Would the party like to opt in for promotional materials? (Y/N): ";
	std::cin.getline(decision, 10);
	flushCin();
	cstrToUpper(decision);

	if ( !strcmp(decision, "Y") || !strcmp(decision, "YES") ) {
		contactName = new char[50];
		contactEmail = new char[50];

		std::cout << "Contact Name: ";
		std::cin.getline(contactName, 50);
		flushCin();

		std::cout << "Contact Email: ";
		std::cin.getline(contactEmail, 50);
		flushCin();
	}
	
	try {
		WaitManager::manager()->addParty(partyName, cstoi(partySize), accommodations, contactName, contactEmail);
	} catch (const char* error) {
		std::cerr << error << std::endl;
		return;
	}

	std::cout << partyName << " successfully added to the wait list." << std::endl;

	delete accommodations;
	delete contactName;
	delete contactEmail;
}



//ui for displaying all of the parties on the wait list ordered by the first to arrive
void viewWaitList() {
	std::cout << "Currently Waiting: " << std::endl;

	try {
		WaitManager::manager()->displayWaitlist();	
	} catch (const char* error) {
		std::cerr << error << std::endl;
	}
	
}



//UI for displaying the information for the next party to be sat and removing them from the wait list
void seatNextParty() {
	try {
		WaitManager::manager()->seatNextParty();
	} catch (const char* error) {
		std::cerr << error << std::endl;
	}
}



//displays the most recent customer interested in promotional material and saves their contact information to the contact database.
void viewNextPromotionContact() {
	try {
		PromotionManager::manager()->getMostRecentContact();
	} catch (const char* error) {
		std::cerr << error << std::endl;
	}
}



//displays all contacts stored in the promotional contact database
void displayContacts() {
	try {
		PromotionManager::manager()->displayPreviousContacts();
	} catch (const char* error) {
		std::cerr << error << std::endl;
	}
}



//loads the already existing waitlist from data.txt
void importWaitList() {
	std::ifstream initWaitlist("data.txt");

	while ( initWaitlist.peek() != -1 ) {
		char partyName[50];
		char partySize[10];
		char *accom = new char[50];
		char *cntctName = new char[50];
		char *email = new char[50];

		initWaitlist.getline(partyName, 50, ',');
		initWaitlist.getline(partySize,10,',');
		initWaitlist.getline(accom,50,',');
		initWaitlist.getline(cntctName,50,',');
		initWaitlist.getline(email,50);

		if ( !strcmp(accom, "") ) {
			delete accom;
			accom = nullptr;
		}
		if ( !strcmp(cntctName, "") ) {
			delete cntctName;
			delete email;
			cntctName = email = nullptr;
		}

		WaitManager::manager()->addParty(partyName, cstoi(partySize), accom, cntctName, email);
		
		delete accom;
		delete cntctName;
		delete email;
	}

	initWaitlist.close();
}
