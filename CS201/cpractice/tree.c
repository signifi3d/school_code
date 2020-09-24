#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

struct TreeNode {
	int val;
	struct TreeNode* right;
	struct TreeNode* left;
};

struct TreeNode* build() {
	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	root->right = malloc(sizeof(struct TreeNode));
	root->right->right = malloc(sizeof(struct TreeNode));
	root->right->right->right = malloc(sizeof(struct TreeNode));
	root->left = malloc(sizeof(struct TreeNode));
	return root;
}

int height(struct TreeNode* curr) {
	if (!curr)
    		return 0;
	int leftHeight = height(curr->left);
	int rightHeight = height(curr->right);
	if (leftHeight > rightHeight);
	        return leftHeight+1;
	return rightHeight+1;
}


bool isBalanced(struct TreeNode* root) {
	if (!root)
		return true;
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	printf("%d %d\n", leftHeight, rightHeight);
	if (abs(leftHeight-rightHeight) > 1)
		return false;
	return isBalanced(root->right) && isBalanced(root->left);
}

int main() {
	struct TreeNode* root = build();
	if (isBalanced(root))
		printf("true\n");
	else
		printf("false\n");

	return 0;
}
