/*
	SiteTable.cpp
	Blake Eakin
	CS 260
	Project 3
	5/13/2019

	Implementation of SiteTable class functions.
*/

#include "string.h"
#include "SiteTable.h"
#include <iostream>


SiteTable* SiteTable::tableInstance = nullptr;



//Constructor
SiteTable::SiteTable() {
	topicHashTable = new TopicList*[TABLE_SIZE];	
	for ( int i = 0; i < TABLE_SIZE; ++i ) {
		topicHashTable[i] = nullptr;
	}
}



//Destructor
SiteTable::~SiteTable() {
	for ( int i = 0; i < TABLE_SIZE; ++i ) {
		delete topicHashTable[i];
	}
	delete [] topicHashTable;
	delete tableInstance;
}



//returns the static table instance
SiteTable* SiteTable::table() {
	if ( tableInstance == nullptr )
		tableInstance = new SiteTable();
	return tableInstance;
}


//Implementation of the Jenkins one-at-a-time hash
unsigned int SiteTable::hash(const char* key) {
	int i = 0;
	unsigned int hash = 0;
	while ( i != strlen(key) ) {
		hash += key[i++];
		hash += hash << 10;
		hash ^= hash >> 6;
	}

	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;

	return hash % TABLE_SIZE;
}



//Takes in site information and creates an entry for it in the table
void SiteTable::insertSite(const char* topic, const char* title, const char* url, const char* summary, const char* review, int rating) {
	if ( strlen(topic) == 0 )
		throw "Invalid topic.";

	unsigned int topicHash = hash(topic);

	if ( topicHashTable[topicHash] == nullptr ) {
		topicHashTable[topicHash] = new TopicList(topic);
		topicHashTable[topicHash]->insert(title, url, summary, review, rating);
	} else {
		TopicList* curr = topicHashTable[topicHash];
		while ( curr != nullptr ) {
			if ( curr->topicIs(topic) )
				break;
			else
				curr = curr->getNext();
		}

		if ( curr == nullptr ) {
			TopicList* newTopicList = new TopicList(topic);
			curr = topicHashTable[topicHash]->appendTopic(newTopicList);
			delete newTopicList;
		}

		curr->insert(title, url, summary, review, rating);
	}
}



//retrieves a list of sites based on a topic
TopicList* SiteTable::retrieve(const char* topic) {
	if ( strlen(topic) == 0 )
		throw "Invalid topic.";

	unsigned int topicHash = hash(topic);
	TopicList* holder = topicHashTable[topicHash];

	while ( holder != nullptr ) {
		if ( holder->topicIs(topic) )
			break;
		else
			holder = holder->getNext();
	}
	
	return holder;
}



//finds the site by topic and title, changes that entry's review and rating based on input
void SiteTable::editReview(const char* topic, const char* title, const char* review, int rating) {
	if ( strlen(topic) == 0 )
		throw "Invalid topic.";
	
	TopicList* selectedTopic = retrieve(topic);
	Site* curr = nullptr;

	if ( selectedTopic == nullptr )
		throw "Topic does not exist.";
	
	curr = selectedTopic->getHead();

	while ( curr != nullptr ) {
		if ( !strcmp(curr->title, title) ) {
			break;
		}
		curr = curr->next;
	}

	if ( curr == nullptr )
		throw "Site does not exist.";

	delete [] curr->review;
	curr->review = new char[strlen(review)+1];
	strcpy(curr->review, review);
	curr->rating = rating;

}



//traverses the table and removes any entries with a rating of one
int SiteTable::removeLowRatings() {
	int count = 0;
	for ( int i = 0; i < TABLE_SIZE; ++i ) {
		if ( topicHashTable[i] == nullptr )
			continue;
		else {
			TopicList* curr = topicHashTable[i];
			
			while ( curr != nullptr ) {
				count += curr->removeUnder(1);
				curr = curr->getNext();
			}
		}
	}

	return count;
}



//Takes in a topic as a string, displays all sites of matching topic
void SiteTable::displaySitesByTopic(const char* topic) {
	if ( strlen(topic) == 0 )
		throw "Invalid topic.";

	TopicList* list = retrieve(topic);

	if ( list == nullptr )
		throw "No sites available.";
	else if ( list->isEmpty() )
		throw "No sites available.";
	else{
		Site* currSite = list->getHead();
		
		std::cout << std::endl << "Topic: " << topic << std::endl << std::endl;

		while ( currSite != nullptr ) {
			std::cout << "\tTitle: " << currSite->title << std::endl;
			std::cout << "\tURL: " << currSite->address << std::endl;
			std::cout << "\tSummary: " << currSite->summary << std::endl;
			std::cout << "\tReview: " << currSite->review << std::endl;
			std::cout << "\tRating: " << currSite->rating << std::endl << std::endl;

			currSite = currSite->next;
		}
	}
}



//traverses the entire table displaying every entry.
void SiteTable::displayAllSites() {
	int topicsListed = 0;
	for ( int i = 0; i < TABLE_SIZE; ++i ) {
		if ( topicHashTable[i] == nullptr )
			continue;
		else {
			TopicList* currTopic = topicHashTable[i];
			
			while ( currTopic != nullptr ) {
				Site* currSite = currTopic->getHead();
				if ( currTopic->isEmpty() )
					std::cout << "No sites available for " << currTopic->getTopic() << "." << std::endl << std::endl;
				else {
					std::cout << "Topic: " << currTopic->getTopic() << std::endl << std::endl;
					while ( currSite != nullptr ) {
						std::cout << "\tTitle: " << currSite->title << std::endl;
						std::cout << "\tURL: " << currSite->address << std::endl;
						std::cout << "\tSummary: " << currSite->summary << std::endl;
						std::cout << "\tReview: " << currSite->review << std::endl;
						std::cout << "\tRating: " << currSite->rating << std::endl << std::endl;
	
						currSite = currSite->next;
					}
				}
				currTopic = currTopic->getNext();
				topicsListed++;
			}
		}
	}

	if ( topicsListed == 0 )
		throw "Table is empty.";
}



//Traverses the table and displays all available topics
void SiteTable::displayTopics() {
	int topicsListed = 0;
	for ( int i = 0; i < TABLE_SIZE; ++i ) {
		if ( topicHashTable[i] == nullptr )
			continue;
		else {
			TopicList* currTopic = topicHashTable[i];

			while ( currTopic != nullptr ) {
				std::cout << currTopic->getTopic() << std::endl;
				currTopic = currTopic->getNext();
				++topicsListed;
			}
		}
	}

	if ( topicsListed == 0 )
		throw "No topics available.";
}
