/*
	SiteTable.h
	Blake Eakin
	CS 260
	Project 3
	5/11/2019

	Class prototype for the hash table for storing web site data.
*/

#pragma once

#include "TopicList.h"

const int TABLE_SIZE = 103;

class SiteTable {
	public:
		~SiteTable();
		static SiteTable* table();
		void insertSite(const char*, const char*, const char*, const char*, const char*, int);
		void editReview(const char*, const char*, const char*, int);
		int removeLowRatings();
		void displaySitesByTopic(const char*);
		void displayAllSites();
		void displayTopics();
	private:
		SiteTable();
		static SiteTable* tableInstance;
		TopicList ** topicHashTable;

		unsigned int hash(const char*);
		TopicList* retrieve(const char*);
};
