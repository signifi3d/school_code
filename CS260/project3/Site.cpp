/*
	Site.cpp
	Blake Eakin
	CS 260
	Project 3
	5/13/2019

	implements constructors of Site struct
*/

#include "Site.h"
#include "string.h"



//constructor
Site::Site():title(nullptr),address(nullptr),summary(nullptr),review(nullptr),rating(0),next(nullptr) {}



//constructor overload
Site::Site(const char* inTitle, const char* inAddress, const char* inSummary, const char* inReview, int inRating) {
	title = new char[strlen(inTitle)+1];
	strcpy(title, inTitle);
	address = new char[strlen(inAddress)+1];
	strcpy(address, inAddress);
	summary = new char[strlen(inSummary)+1];
	strcpy(summary, inSummary);
	review = new char[strlen(inReview)+1];
	strcpy(review, inReview);
	rating = inRating;
	next = nullptr;
}



//copy constructor
Site::Site(const Site& copySite) {
	title = new char[strlen(copySite.title)+1];
	strcpy(title, copySite.title);
	address = new char[strlen(copySite.address)+1];
	strcpy(address, copySite.address);
	summary = new char[strlen(copySite.summary)+1];
	strcpy(summary, copySite.summary);
	review = new char[strlen(copySite.review)+1];
	strcpy(review, copySite.review);
	rating = copySite.rating;
	if ( copySite.next != nullptr ) {
		next = new Site(*(copySite.next));
	} else 
		next = nullptr;
}



//Destructor
Site::~Site() {
	delete [] title;
	delete [] address;
	delete [] summary;
	delete [] review;
	delete next;
}
