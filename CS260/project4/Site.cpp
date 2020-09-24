/*
	Site.cpp
	Blake Eakin
	CS 260
	Project 4
	5/21/2019

	Constructor implementations for Site struct
*/

#include "Site.h"
#include "string.h"


//Default constructor
Site::Site():topic(nullptr),keyword(nullptr),url(nullptr),summary(nullptr),review(nullptr),rating(0),left(nullptr),right(nullptr),height(1) {}



//parametrized constructor
Site::Site(const char* newTopic, const char* newKeyword, const char* newURL, const char* newSummary, const char* newReview, int newRating) {
	if ( !strcmp(newTopic, " ") )
		throw "Invalid topic.";
	if ( !strcmp(newKeyword, " ") )
		throw "Invalid keyword.";

	topic = new char[strlen(newTopic)+1];
	strcpy(topic, newTopic);

	keyword = new char[strlen(newKeyword)+1];
	strcpy(keyword, newKeyword);

	url = new char[strlen(newURL)+1];
	strcpy(url, newURL);

	summary = new char[strlen(newSummary)+1];
	strcpy(summary, newSummary);

	review = new char[strlen(newReview)+1];
	strcpy(review, newReview);

	rating = newRating;

	left = nullptr;
	right = nullptr;
	height = 1;
}


//Copy constructor
Site::Site(const Site& toCopy) {
	topic = new char[strlen(toCopy.topic)+1];
	strcpy(topic, toCopy.topic);

	keyword = new char[strlen(toCopy.keyword)+1];
	strcpy(keyword, toCopy.keyword);

	url = new char[strlen(toCopy.url)+1];
	strcpy(url, toCopy.url);

	summary = new char[strlen(toCopy.summary)+1];
	strcpy(summary, toCopy.summary);

	review = new char[strlen(toCopy.review)+1];
	strcpy(review, toCopy.review);

	rating = toCopy.rating;

	left = nullptr;
	right = nullptr;
	height = 1;
}



//Destructor
Site::~Site() {
	delete [] topic;
	delete [] keyword;
	delete [] url;
	delete [] summary;
	delete [] review;

	delete left;
	delete right;
}



//detaches the node from any other tree nodes by setting all the pointers to nullptr
void Site::detach() {
	left = nullptr;
	right = nullptr;
}
