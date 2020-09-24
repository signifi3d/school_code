/*
	Site.h
	Blake Eakin
	CS 260
	Project 4
	5/21/2019

	prototyping of site struct that is the building block of the BST
*/

#pragma once


struct Site {
	char* topic;
	char* keyword;
	char* url;
	char* summary;
	char* review;
	int rating;

	Site* left;
	Site* right;
	int height;

	Site();
	Site(const char*, const char*, const char*, const char*, const char*, int);
	Site(const Site&);
	~Site();

	void detach();
};
