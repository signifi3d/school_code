/*
	WaitManager.h
	Blake Eakin
	CS 260
	Project 2
	4/25/2019

	Prototypes and definitions for class that acts as the interface between client and the waitlist queue.
*/

#include "PartyQueue.h"

class WaitManager {
	public:
		~WaitManager();
		static WaitManager* manager();
		void addParty(const char* partyName, int partySize, const char* accom=nullptr, const char* contactName=nullptr, const char* contactEmail=nullptr);
		void displayWaitlist();
		void nextPartyInLine();
		void seatNextParty();
	private:
		WaitManager();
		static WaitManager* managerInstance; 
		PartyQueue waitlist;

};
