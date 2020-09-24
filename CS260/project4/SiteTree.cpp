/*
	SiteTree.cpp
	Blake Eakin
	CS 260
	Project 4
	5/21/2019

	Implements class methods of SiteTree to function as an AVL Tree.
*/

#include "SiteTree.h"
#include "Site.h"
#include "string.h"
#include <iostream>


SiteTree* SiteTree::treeInstance = nullptr;



//default constructor
SiteTree::SiteTree():root(nullptr) {}



//destructor
SiteTree::~SiteTree() {
	delete root;
	delete treeInstance;
}



//retrieves static object instance
SiteTree* SiteTree::tree() {
	if ( treeInstance == nullptr ) 
		treeInstance = new SiteTree();
	return treeInstance;
}



//uses passed arguments to build a new Site object, inserts it into the tree and 
//balances as necessary
void SiteTree::insert(const char* topic, const char* keyword, const char* url, const char* summary, const char* review, int rating) {
	Site* insertSite = nullptr;

	try {
		insertSite = new Site(topic, keyword, url, summary, review, rating);
	} catch ( const char* error ) {
		throw error;
	}

	if ( root == nullptr ) {
		root = new Site(*insertSite);
	} else {
		try {
			_insert(insertSite, root);
		} catch ( const char* error ) {
			delete insertSite;
			throw error;
		}
	}
	delete insertSite;
}



//recursive insert implementation
void SiteTree::_insert(const Site* toInsert, Site*& curr) {
	if ( strcmp(toInsert->keyword, curr->keyword) < 0 ) {
		if ( curr->left == nullptr ) {
			curr->left = new Site(*toInsert);
		} else
			_insert(toInsert, curr->left);
	} else if ( strcmp(toInsert->keyword, curr->keyword) > 0 ) {
		if ( curr->right == nullptr ) {
			curr->right = new Site(*toInsert);
		} else {
			_insert(toInsert, curr->right);
		}
	} else {
		throw "Site already exists.";
	}

	curr->height = max(height(curr->left), height(curr->right)) + 1;

	int balance = height(curr->left) - height(curr->right);

	if ( balance >= -1 && balance <= 1 )
		return;
	else if ( balance < -1 && strcmp(toInsert->keyword, curr->right->keyword) > 0 ) {
		rotateLeft(curr);
	} else if ( balance < -1 && strcmp(toInsert->keyword, curr->right->keyword) < 0 ) {
		rotateRight(curr->right);
		rotateLeft(curr);
	} else if ( balance > 1 && strcmp(toInsert->keyword, curr->left->keyword) < 0 ) {
		rotateRight(curr);
	} else if ( balance > 1 && strcmp(toInsert->keyword, curr->left->keyword) > 0 ) {
		rotateLeft(curr->left);
		rotateRight(curr);
	}

}



//searches for all sites with a topic matching the passed parameter and removes them from the tree, rebalances the tree
void SiteTree::removeTopic(const char* topic) {
	if ( !strcmp(topic, " ") ) 
		throw "Invalid Topic.";
	
	try {
		_removeTopic(topic, root);
	} catch ( const char* error ) {
		throw error;
	}
}



//recursive implementation of topic removal.
void SiteTree::_removeTopic(const char* topic, Site*& curr) {
	if ( curr == nullptr )
		return;
	else if ( !strcmp(topic, curr->topic) ) {
		removeNode(curr);
		if ( curr == nullptr )
			return;
		else {
			_removeTopic(topic, curr);
			if ( curr == nullptr )
				return;
		}

	} else {
		_removeTopic(topic, curr->left);
		_removeTopic(topic, curr->right);
	}

	curr->height = max(height(curr->left), height(curr->right)) + 1;

	int balance = height(curr->left) - height (curr->right);

	if ( balance >= -1 && balance <= 1 ) {
		return;
	} else if ( balance < -1 && (height(curr->right->left) - height(curr->right->right)) <= 0 ) {
		rotateLeft(curr);
	} else if ( balance < -1 && (height(curr->right->left) - height(curr->right->right)) > 0 ) {
		rotateRight(curr->right);
		rotateLeft(curr);
	} else if ( balance > 1 && (height(curr->left->left) - height(curr->left->right)) >= 0 ) {
		rotateRight(curr);
	} else if ( balance > 1 && (height(curr->left->left) - height(curr->left->right)) < 0 ) {
		rotateLeft(curr->left);
		rotateRight(curr);
	}

}



//searches for a site with the passed argument as a keyword and removes it from the tree, rebalances the tree
void SiteTree::removeSite(const char* keyword) {
	if ( !strcmp(keyword, " " ) )
		throw "Invalid keyword.";

	try { 
		_removeSite(keyword, root);
	} catch ( const char* error ) {
		throw error;
	}
}



//recursive removal by site keyword
void SiteTree::_removeSite(const char* keyword, Site*& curr) {
	if ( curr == nullptr ) {
		throw "Site not found.";
	} else if ( !strcmp(keyword, curr->keyword) ) {
		try {
			removeNode(curr);
		} catch ( const char* error ) {
			throw error;
		}
	} else if ( strcmp(keyword, curr->keyword) < 0 ) {
		_removeSite(keyword, curr->left);
	} else if ( strcmp(keyword, curr->keyword) > 0 ) {
		_removeSite(keyword, curr->right);
	}

	if ( curr == nullptr )
		return;

	curr->height = max(height(curr->left), height(curr->right)) + 1;

	int balance = height(curr->left) - height(curr->right);

	if ( balance >= -1 && balance <= 1 ) {
		return;
	} else if ( balance < -1 && (height(curr->right->left) - height(curr->right->right)) <= 0 ) {
		rotateLeft(curr);
	} else if ( balance < -1 && (height(curr->right->left) - height(curr->right->right)) > 0 ) {
		rotateRight(curr->right);
		rotateLeft(curr);
	} else if ( balance > 1 && (height(curr->left->left) - height(curr->left->right)) >= 0 ) {
		rotateRight(curr);
	} else if ( balance > 1 && (height(curr->left->left) - height(curr->left->right)) < 0 ) {
		rotateLeft(curr->left);
		rotateRight(curr);
	}

}



//removes provided node from tree
void SiteTree::removeNode(Site*& node) {
	if ( node == nullptr )
		throw "Node doesn't exist.";

	if ( node->left == nullptr && node->right == nullptr ) {
		Site* temp = node;
		node = nullptr;
		delete temp;
	} else if ( node->left == nullptr ) {
		Site* temp = node;
		node = node->right;
		temp->detach();
		delete temp;
		node->height = height(node->right) + 1;
	} else if ( node->right == nullptr ) {
		Site* temp = node;
		node = node->left;
		temp->detach();
		delete temp;
		node->height = height(node->left) + 1;
	} else {
		Site** temp = minKey(node->right);
		Site* temp2 = node;
		node = new Site(**temp);
		removeNode(*temp);
		node->left = temp2->left;
		node->right = temp2->right;
		temp2->detach();
		delete temp2;
		node->height = max(height(node->left), height(node->right)) + 1;
	}
}



//retrieves the site with the passed keyword
Site* SiteTree::retrieve(const char* keyword, Site* curr) {
	if ( curr == nullptr || !strcmp(keyword, " ") ) {
		return nullptr;
	} else if ( !strcmp(keyword, curr->keyword) ) {
		return curr;
	} else if ( strcmp(keyword, curr->keyword) < 0 ) {
		return retrieve(keyword, curr->left);
	} else if ( strcmp(keyword, curr->keyword) > 0 ) {
		return retrieve(keyword, curr->right);
	} else
		return nullptr;
}



//in-order traverses the tree and displays each node's data
void SiteTree::display() {
	if ( root == nullptr )
		throw "Site collection is empty.";

	
	_display(root);
}



//recursive display implementation
void SiteTree::_display(const Site* curr) {
	if ( curr == nullptr ) {
		return;
	} else {
		_display(curr->left);

		std::cout << std::endl << "Topic: " << curr->topic << std::endl;
		std::cout << "Keyword: " << curr->keyword << std::endl;
		std::cout << "URL: " << curr->url << std::endl;
		std::cout << "Summary: " << curr->summary << std::endl;
		std::cout << "Review: " << curr->review << std::endl;
		std::cout << "Rating: " << curr->rating << std::endl;

		_display(curr->right);
	}
}



//returns height of passed node
int SiteTree::height(const Site* node) {
	if ( node == nullptr ) 
		return 0;
	return node->height;
}



//rotates to the right around the passed node.
void SiteTree::rotateRight(Site*& node) {
	Site* temp = node;
	node = node->left;
	temp->left = node->right;
	node->right = temp;
	temp = nullptr;

	node->right->height = max(height(node->right->right), height(node->right->left)) + 1;
	node->height = max(height(node->right), height(node->left)) + 1;

}



//rotates to the left around the passed node.
void SiteTree::rotateLeft(Site*& node) {
	Site* temp = node;
	node = node->right;
	temp->right = node->left;
	node->left = temp;
	temp = nullptr;

	node->left->height = max(height(node->left->left), height(node->left->right)) + 1;
	node->height = max(height(node->left), height(node->right)) + 1;



}



//calculates the max between two values
int SiteTree::max(int a, int b) {
	return ( a > b ) ? a : b;
}



//Finds the smallest key off a given node
Site** SiteTree::minKey(Site*& curr) {
	if ( curr->left == nullptr )
		return &curr;
	else
		return minKey(curr->left);
}
