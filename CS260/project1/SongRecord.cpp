/*
SongRecord.cpp
Blake Eakin
CS 260
Project 1
4/11/2019

Implementation details of SongRecord struct
*/
#include "SongRecord.h"
#include <string.h>

//Default constructor
SongRecord::SongRecord():next(nullptr),title(nullptr),length(0.0),views(0),likes(0) {}



//copy constructor
SongRecord::SongRecord(const SongRecord& toCopy) {
	next = toCopy.next;
	delete title;
	title = new char[strlen(toCopy.title)];
	strcpy(title, toCopy.title);
	length = toCopy.length;
	views = toCopy.views;
	likes = toCopy.likes;
}



//destructor
SongRecord::~SongRecord() {
	delete title;
	delete next;
}
