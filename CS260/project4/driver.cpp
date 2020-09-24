/*
	driver.cpp
	Blake Eakin
	CS 260
	Project 4
	5/21/2019

	Main initialization and user interface.
*/

#include "SiteTree.h"
#include "utilities.h"
#include <iostream>
#include <fstream>
#include "string.h"

void menuLoop();
void displaySites();
void addSite();
void removeTopic();
void removeSite();
void loadData();

//main
int main () {
	
	loadData();
	menuLoop();

	return 0;
}



//Main UI menu loop
void menuLoop() {
	char menuChoice[50];
	bool exitCase = false;

	std::cout << std::endl << "Site Bookmarking App" << std::endl << std::endl;

	while ( !exitCase ) {
		std::cout << "\t1. Display all sites." << std::endl;
		std::cout << "\t2. Add a new site." << std::endl;
		std::cout << "\t3. Remove a topic." << std::endl;
		std::cout << "\t4. Remove a site." << std::endl;
		std::cout << "\tX. Exit program." << std::endl << std::endl;
		std::cout << "Your choice: ";

		std::cin.getline(menuChoice, 50);
		flushCin();
		
		if ( !strcmp(menuChoice, "1") ) {
			displaySites();
		} else if ( !strcmp(menuChoice, "2") ) {
			addSite(); 
		} else if ( !strcmp(menuChoice, "3") ) {
			removeTopic();
		} else if ( !strcmp(menuChoice, "4") ) {
			removeSite();
		} else if ( !strcmp(menuChoice, "X") ) {
			exitCase = true;
		} else {
			std::cerr << "Invalid input, please use option numbers found on the left side of the menu." << std::endl;
		}
		
	}

}



//calls the site tree display function
void displaySites() {
	std::cout << std::endl << "All stored sites: " << std::endl;

	try {
		SiteTree::tree()->display();
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
	}
}



//Queries user for new site data and passes that data to tree insert function
void addSite() {
	char topic[50];
	char keyword[50];
	char url[500];
	char summary[500];
	char review[500];
	char rating[10];

	std::cout << std::endl << "Enter the new site's information" << std::endl;

	std::cout << std::endl << "\tTopic: ";
	std::cin.getline(topic, 50);
	flushCin();

	std::cout << "\tKeyword: ";
	std::cin.getline(keyword, 50);
	flushCin();

	std::cout << "\tURL: ";
	std::cin.getline(url, 500);
	flushCin();

	std::cout << "\tSummary: ";
	std::cin.getline(summary, 500);
	flushCin();

	std::cout << "\tReview: ";
	std::cin.getline(review, 500);
	flushCin();

	std::cout << "\tRating (1-5): ";
	std::cin.getline(rating, 10);
	flushCin();

	try {
		SiteTree::tree()->insert(topic, keyword, url, summary, review, cstoi(rating));
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
		return;
	}

	std::cout << std::endl << "New site added successfully." << std::endl;
}



//Queries user for topic to remove, passes to tree remove topic function
void removeTopic() {
	char topic[50];

	std::cout << "What is the topic you would like removed: ";
	std::cin.getline(topic,50);
	flushCin();

	try {
		SiteTree::tree()->removeTopic(topic);
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
		return;
	}

	std::cout << topic << " successfully removed." << std::endl << std::endl;

}



//Queries user for site keyword to remove, passes to tree remove site function
void removeSite() {
	char keyword[50];

	std::cout << "What is the keyword for the site you would like removed: ";
	std::cin.getline(keyword,50);
	flushCin();

	try {
		SiteTree::tree()->removeSite(keyword);
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
		return;
	}

	std::cout << keyword << " successfully removed." << std::endl;
}



//inserts all data from the external file to the tree
void loadData() {
	std::ifstream dataIn("data.txt");

	while ( dataIn.peek() != -1 ) {
		char topic[50];
		char keyword[50];
		char url[500];
		char summary[500];
		char review[500];
		char rating[10];
		
		dataIn.getline(topic,50,',');
		dataIn.getline(keyword,50,',');
		dataIn.getline(url,500,',');
		dataIn.getline(summary,500,',');
		dataIn.getline(review,500,',');
		dataIn.getline(rating,10);

		try {
			SiteTree::tree()->insert(topic, keyword, url, summary, review, cstoi(rating));
		} catch ( const char* error ) {
			std::cerr << error << std::endl;
		}

	}

}
