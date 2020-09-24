/*
	TopicList.h
	Blake Eakin
	CS 260
	Project 3
	5/11/2019

	Class prototype for a linked list that holds a list of
	sites for a particular topic.
*/

#pragma once

#include "Site.h"

class TopicList {
	public:
		TopicList(const char*);
		TopicList(const TopicList&);
		~TopicList();
		Site* getHead();
		TopicList* getNext();
		const char* getTopic();
		bool isEmpty();
		void insert(const char*, const char*, const char*, const char*, int);
		TopicList* appendTopic(const TopicList*);
		int removeUnder(int);
		bool topicIs(const char*) const;
	private:
		Site* head;
		TopicList* next;
		char* topic;

};
