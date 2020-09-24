/*
ArtistRecord.cpp
Blake Eakin
CS 260
Project 1
4/11/2019

Implementation of ArtistRecord functions
*/
#include "ArtistRecord.h"
#include <string.h>
#include <iostream>

//Default constructor, sets everything to nullptr
ArtistRecord::ArtistRecord():artistName(nullptr),topStory(nullptr),artistDescription(nullptr),songHead(nullptr) {}



//Destructor
ArtistRecord::~ArtistRecord() {
	delete next;
	delete songHead;
}



//operator= overload
void ArtistRecord::operator=(const ArtistRecord& toAssign) {
	delete artistName;
	artistName = new char[strlen(toAssign.artistName)];
	strcpy(artistName, toAssign.artistName);
	delete topStory;
	topStory = new char[strlen(toAssign.topStory)];
	strcpy(topStory, toAssign.topStory);
	delete artistDescription;
	artistDescription = new char[strlen(toAssign.artistDescription)];
	strcpy(artistDescription, toAssign.artistDescription);
	delete songHead;
	songHead = toAssign.songHead;
}



//Copy constructor
ArtistRecord::ArtistRecord(const ArtistRecord& toAssign) {
	artistName = new char[strlen(toAssign.artistName)];
	strcpy(artistName, toAssign.artistName);
	topStory = new char[strlen(toAssign.topStory)];
	strcpy(topStory, toAssign.topStory);
	artistDescription = new char[strlen(toAssign.artistDescription)];
	strcpy(artistDescription, toAssign.artistDescription);
	songHead = toAssign.songHead;
}
