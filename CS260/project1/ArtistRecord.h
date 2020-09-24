/*
ArtistRecord.h
Blake Eakin
CS 260
Project 1
4/11/2019

Definition of ArtistRecord data type
*/
#pragma once

#include "SongRecord.h"

struct ArtistRecord {
	ArtistRecord* next;
	char* artistName;
	char* topStory;
	char* artistDescription;
	SongRecord* songHead;
	void operator=(const ArtistRecord&);
	ArtistRecord();
	~ArtistRecord();
	ArtistRecord(const ArtistRecord&);
};
