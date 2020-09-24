/*
	TopicList.cpp
	Blake Eakin
	CS 260
	Project 3
	5/11/2019

	Implementation of class functions for the TopicList class.
*/

#include "TopicList.h"
#include "Site.h"
#include "string.h"

#include <iostream>

//Constructor
TopicList::TopicList(const char* newTopic):head(nullptr), next(nullptr) {
	topic = new char[strlen(newTopic)+1];
	strcpy(topic, newTopic);
}



//Copy Constructor
TopicList::TopicList(const TopicList& copyTopic) {
	topic = new char[strlen(copyTopic.topic)+1];
	strcpy(topic, copyTopic.topic);
	if ( copyTopic.head != nullptr ) {
		Site* curr = nullptr;
		head = new Site(*(copyTopic.head));
		curr = head;
		while ( curr->next != nullptr )
			curr = curr->next;
	} else {
		head = nullptr;
	}
	next = nullptr;
}



//Destructor
TopicList::~TopicList() {
	delete [] topic;
	delete head;
	delete next;
}



//returns the site at the head of the list
Site* TopicList::getHead() {
	return head;
}



//returns the next topic chained in this bucket
TopicList* TopicList::getNext() {
	return next;
}



//returns the topic string
const char* TopicList::getTopic() {
	return topic;
}



//returns false if there are Site nodes, true if head is nullptr
bool TopicList::isEmpty() {
	return head == nullptr;
}



//inserts a new site into the list
void TopicList::insert(const char* title, const char* url, const char* summary, const char* review, int rating) {
	Site newSite(title, url, summary, review, rating);
	Site* curr = nullptr;

	if ( head == nullptr ) 
		head = new Site(newSite);
	else {
		curr = head;

		while ( curr->next != nullptr ) {
			if ( !strcmp(newSite.title, curr->title) || !strcmp(newSite.address, curr->address) )
				throw "Site already exists for this topic.";
			else
				curr = curr->next; 
		}

		curr->next = new Site(newSite);

	}
}



//chain another topic to the end of the bucket, implemented recursively
TopicList* TopicList::appendTopic(const TopicList* newTopic) {
	if ( next == nullptr ) {
		next = new TopicList(*newTopic);
		return next;
	} else {
		return next->appendTopic(newTopic);
	}
}



//removes all sites with ratings under a threshold returns the number removed.
int TopicList::removeUnder(int thresh) {
	int count = 0;

	if ( head == nullptr )
		return count;
	
	else {
		Site** curr = &head;

		while ( *curr != nullptr ) {
			if ( (*curr)->rating <= thresh ) {
				Site* temp = *curr;
				*curr = (*curr)->next;
				temp->next = nullptr;
				delete temp;
				++count;
				continue;
			}
			curr = &((*curr)->next);
		}
	}

	return count;
}



//returns true if the passed string matches the topic
bool TopicList::topicIs(const char* topicCompare) const {
	return !strcmp(topic, topicCompare);
}
