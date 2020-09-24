/*
	SiteTree.h
	Blake Eakin
	CS 260
	Project 4
	5/21/2019

	class prototype for SiteTree that implements the tree functionality for storing site data.
*/

#pragma once

#include "Site.h"

class SiteTree {
	public:
		~SiteTree();
		static SiteTree* tree();
		void insert(const char*, const char*, const char*, const char*, const char*, int);
		void removeTopic(const char*);
		void removeSite(const char*);
		void display();
	private:
		static SiteTree* treeInstance;
		Site* root;

		SiteTree();
		Site* retrieve(const char*, Site*);
		void removeNode(Site*&);
		int height(const Site*);
		int max(int,int);
		Site** minKey(Site*&);
		void rotateRight(Site*&);
		void rotateLeft(Site*&);
		void _insert(const Site*, Site*&);
		void _display(const Site*);
		void _removeSite(const char*, Site*&);
		void _removeTopic(const char*, Site*&);

		void printLevelOrder(Site*,int,int);
};
