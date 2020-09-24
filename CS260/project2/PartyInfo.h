/*
	PartyInfo.h
	Blake Eakin
	CS 260
	Project 2
	4/23/2019

	Defines the structure that holds information about a party and a reference to the next party in line.
*/

#pragma once

#include "CustomerContact.h"

struct PartyInfo {
	char* partyName;
	int partySize;
	char* accommodations;
	CustomerContact* promoOptIn;

	PartyInfo* next;

	PartyInfo():partyName(nullptr),partySize(0),accommodations(nullptr),promoOptIn(nullptr),next(nullptr) {}
	PartyInfo(const PartyInfo&);
	~PartyInfo();
};
