#include "table.h"

int count(node * root) {
	if ( root == nullptr )
		return 0;
	else
		return 1 + count(root->left) + count(root->right);
}

int sum(node * root) {
	if ( root == nullptr )
		return 0;
	else
		return root->data + sum(root->left) + sum(root->right);
}

int height(node * root) {
	if ( root == nullptr )
		return 0;
	else
		return 1 + max(height(root->left), height(root->right));
}

int max(int a, int b) {
	if ( a > b )
		return a;
	return b;
}
