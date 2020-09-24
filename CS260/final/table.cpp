#include "table.h"

//Please put the impelementation of the required functions here

int sumOfNodes(node * root) {
	if ( root == nullptr ) 
		return 0;
	else
		return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}



void copyLeaf(node * root, node *& newRoot) {
	if ( root->left == nullptr && root->right == nullptr )
		insert(root->data, newRoot);
	else {
		if ( root->left != nullptr )
			copyLeaf(root->left, newRoot);
		if ( root->right != nullptr )
			copyLeaf(root->right, newRoot);
	}
}



void insert(int data, node *& newRoot) {
	if ( newRoot == nullptr ) {
		newRoot = new node();
		newRoot->data = data;
		return;
	}
	else if ( data <= newRoot->data ) 
		insert(data, newRoot->left);
	else
		insert(data, newRoot->right);
}
