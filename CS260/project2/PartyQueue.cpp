/*
	PartyQueue.cpp
	Blake Eakin
	CS 260
	Project 2
	4/23/2019

	Implementation of class functions of PartyQueue
*/

#include "PartyQueue.h"
#include "PartyInfo.h"
#include "CustomerContact.h"
#include <iostream>


//Default Constructor
PartyQueue::PartyQueue():head(nullptr),tail(nullptr) {}



//Destructor
PartyQueue::~PartyQueue() {

}



//enqueue takes a pointer to party info to add at the end of the list
void PartyQueue::enqueue(const PartyInfo* toAdd) {
	if ( head == nullptr ) {
		head = new PartyInfo(*toAdd);
		tail = head;
		tail->next = head;
		head->next = tail;
	} else {
		tail->next = new PartyInfo(*toAdd);
		tail = tail->next;
		tail->next = head;
	}
}



//dequeue removes the party at the head of the queue from the queue, returns a pointer to it
PartyInfo* PartyQueue::dequeue() {
	PartyInfo* returnInfo = head;
	if ( head == nullptr )
		throw "List is empty.";
	if ( head == tail ) {
		head = nullptr;
		tail = nullptr;
	} else {
		head = head->next;
		tail->next = head;
	}
	returnInfo->next = nullptr;
	return returnInfo;
}



//Returns the info of the party at the head of the queue without removing from queue
const PartyInfo* PartyQueue::peek() {
	if ( head == nullptr )
		throw "List is empty.";
	return head;
}



//outputs all of the parties in the queue, calls private recursive function
void PartyQueue::display() {
	if ( head == nullptr )
		throw "List is empty.";
	_display(head);
}



//Recursively outputs the info of every party in the queue
void PartyQueue::_display(const PartyInfo* curr) {
	std::cout << "Party Name: " << curr->partyName << std::endl;
	std::cout << "Party Size: " << curr->partySize << std::endl;
	std::cout << "Accommodations: ";
	
	if ( curr->accommodations == nullptr ) 
		std::cout << "None." << std::endl;
	else
		std::cout << curr->accommodations << std::endl;
	
	std::cout << "Opted-In For Promotions: ";

	if ( curr->promoOptIn == nullptr )
		std::cout << "No." << std::endl;
	else {
		std::cout << "Yes." << std::endl;
	}

	if ( curr->next == head )
		return;
	else
		_display(curr->next);
}
