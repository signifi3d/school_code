/*
	driver.cpp
	Blake Eakin
	CS 260
	Project 3
	5/9/2019

	Structures the main user interface and entry point of the bookmarking program.
*/

#include <iostream>
#include <fstream>
#include "string.h"
#include "utilities.h"
#include "SiteTable.h" 

void importSiteData();
void menuLoop();
void addSite();
void viewTopicSites();
void editSite();
void removeLowRatings();
void viewAllSites();

//main
int main() {
	
	importSiteData();
	menuLoop();

	return 0;
}



//Imports site data from database file.
void importSiteData() {
	std::ifstream database("data.txt");

	while ( database.peek() != -1 ) {
		char topic[50];
		char title[50];
		char url[500];
		char summary[500];
		char review[500];
		char rating[10];

		database.getline(topic, 50, ',');
		database.getline(title, 50, ',');
		database.getline(url, 500, ',');
		database.getline(summary, 500, ',');
		database.getline(review, 500, ',');
		database.getline(rating, 10);

		try {
			SiteTable::table()->insertSite(topic, title, url, summary, review, cstoi(rating));
		} catch ( const char* error ) {
			std::cerr << error << std::endl;
		}
	}
}


//Loops through the menu options until user exit
void menuLoop() {
	char input[50];
	bool exit = false;

	while ( !exit ) {
		std::cout << "1. Add new web site." << std::endl;
		std::cout << "2. View all web sites for a topic." << std::endl;
		std::cout << "3. Edit a web site's review and rating." << std::endl;
		std::cout << "4. Remove all 1 star web sites." << std::endl;
		std::cout << "5. View all web sites." << std::endl;
		std::cout << "X. Exit." << std::endl;
		std::cout << "Your choice: ";

		std::cin.getline(input,50);
		flushCin();

		if ( !strcmp(input, "1") ) {
			addSite();
		} else if ( !strcmp(input, "2") ) {
			viewTopicSites();
		} else if ( !strcmp(input, "3") ) {
			editSite();
		} else if ( !strcmp(input, "4") ) {
			removeLowRatings();
		} else if ( !strcmp(input, "5") ) {
			viewAllSites();
		} else if ( !strcmp(input, "X") || !strcmp(input, "x") ) {
			std::cout << "Thanks for using the web site bookmarking app." << std::endl;
			exit = true;
		} else {
			std::cout << "Invalid input." << std::endl;
		}
	}
}



//executes interface for inputing new site information
void addSite() {
	char topic[50];
	char title[50];
	char url[100];
	char summary[500];
	char review[500];
	char ratingIn[10];
	int rating = 0;

	std::cout << "Topic: ";
	std::cin.getline(topic, 50);
	flushCin();

	std::cout << "Site Title: ";
	std::cin.getline(title, 50);
	flushCin();

	std::cout << "URL: ";
	std::cin.getline(url, 100);
	flushCin();

	std::cout << "Summary: ";
	std::cin.getline(summary, 500);
	flushCin();

	std::cout << "Review: ";
	std::cin.getline(review, 500);
	flushCin();

	std::cout << "Rating: ";
	std::cin.getline(ratingIn, 10);
	flushCin();

	try {
		rating = cstoi(ratingIn);
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
	}

	while ( rating < 1 || rating > 5 ) {
		std::cout << "Invalid rating input." << std::endl;
		std::cout << "Rating: ";
		std::cin.getline(ratingIn, 10);
		flushCin();

		try {
			rating = cstoi(ratingIn);
		} catch ( const char* error ) {
			std::cerr << error << std::endl;
		}
	}

	try {
		SiteTable::table()->insertSite(topic, title, url, summary, review, rating);
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
	}

}



//provides ui for querying for a topic and displaying related sites
void viewTopicSites() {
	char topic[50];

	std::cout << std::endl << "Available Topics: " << std::endl << std::endl;

	try {
		SiteTable::table()->displayTopics();
	} catch ( const char * error ) {
		std::cerr << error << std::endl;
		return;
	}

	std::cout << std::endl << std::endl;

	std::cout << "What topic would you like to see sites for? ";
	std::cin.getline(topic, 50);
	flushCin();

	try {
		SiteTable::table()->displaySitesByTopic(topic);
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
	}
}



//Queries user for input with which to edit a site's review and rating
void editSite() {
	char topic[50];
	char title[50];
	char newReview[500];
	char newRating[10];
	int rating = 0;

	std::cout << std::endl << "Available Topics: " << std::endl << std::endl;

	try {
		SiteTable::table()->displayTopics();
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
		return;
	}

	std::cout << std::endl << std::endl;

	std::cout << "What topic does the site you want to change belong to? ";
	std::cin.getline(topic, 50);
	flushCin();

	try {
		SiteTable::table()->displaySitesByTopic(topic);
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
		return;
	}

	std::cout << "What is the title of the site you'd like to edit? ";
	std::cin.getline(title, 50);
	flushCin();

	std::cout << "New Review: ";
	std::cin.getline(newReview, 500);
	flushCin();

	std::cout << "New Rating: ";
	std::cin.getline(newRating, 10);
	flushCin();

	try {
		rating = cstoi(newRating);
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
		return;
	}

	while ( rating < 1 || rating > 5 ) {
		std::cout << "Invalid rating input." << std::endl;
		std::cout << "New Rating: ";
		std::cin.getline(newRating, 10);
		flushCin();

		try {
			rating = cstoi(newRating);
		} catch ( const char* error ) {
			std::cerr << error << std::endl;
		}
	}

	try {
		SiteTable::table()->editReview(topic, title, newReview, rating);
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
		return;
	}

	std::cout << title << " edited successfully." << std::endl;
}



//executes removal of all web sites in the database with a rating of 1
void removeLowRatings() {
	try {
		std::cout << SiteTable::table()->removeLowRatings() << " sites removed." << std::endl;
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
	}
}



//calls function to display all sites in the database.
void viewAllSites() {
	try {
		SiteTable::table()->displayAllSites();
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
	}
}
