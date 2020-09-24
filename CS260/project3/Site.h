/*
	Site.h
	Blake Eakin
	CS 260
	Project 3
	5/11/2019

	Definition of data type for encapsulating web site data.
*/

#pragma once


struct Site {
	Site();
	Site(const char*, const char*, const char*, const char*, int);
	Site(const Site&);
	~Site();
	char* title;
	char* address;
	char* summary;
	char* review;
	int rating;
	Site* next;
};
