#include "table.h"
#include <iostream>

//Please put the impelementation of the required functions here

int numberOfNodes(node * root) {
	if ( root == nullptr )
		return 0;
	else
		return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);
}



void removeSmallest(node *& root) {
	if ( root->left == nullptr ) {
		if ( root->right != nullptr ) {
			node* temp = root;
			root = root->right;
			delete temp;
		} else {
			node* temp = root;
			root = nullptr;
			delete temp;
		}
	} else 
		removeSmallest(root->left);
}



int removeEven(node *& root) {
	if ( root == nullptr )
		return 0;
	else if ( root->data % 2 == 0 ) {
		if ( root->left != nullptr ) {
			std::cout << "even found left replace" << std::endl;
			root->data = root->left->data;
			remove(root->left);
			return 1 + removeEven(root);
		} else if ( root->right != nullptr ) {
			std::cout << "even found right replace" << std::endl;
			root->data = root->right->data;
			remove(root->right);
			return 1 + removeEven(root);
		} else {
			std::cout << "even found leaf" << std::endl;
			node* temp = root;
			root = nullptr;
			delete temp;
			return 1;
		}
	} else 
		return removeEven(root->left) + removeEven(root->right);
}


void remove(node *& root) {
	if ( root == nullptr ) {
		//std::cout << "remove null" << std::endl;
		return;
	} else if ( root->left == nullptr && root->right == nullptr ) {
		//std::cout << "remove leaf" << std::endl;
		node* temp = root;
		root = nullptr;
		delete temp;
		return;
	} else if ( root->left == nullptr && root->right != nullptr ) {
		//std::cout << "remove right replace." << std::endl;
		node* temp = root;
		root = root->right;
		delete temp;
	} else if ( root->left != nullptr && root->right == nullptr ) {
		//std::cout << "remove left replace." << std::endl;
		node* temp = root;
		root = root->left;
		delete temp;
	} else {
		node ** succ = successor(root->right);
		node * temp = root;
		root = new node();
		root->data = (*succ)->data;
		remove(*succ);
		root->left = temp->left;
		root->right = temp->right;
		delete temp;
	}
}


node ** successor( node *& root ) {
	if ( root->left == nullptr )
		return &root;
	else
		return successor(root->left);
}
