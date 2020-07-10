#include "Display.h"
#include "ChangeNode.h"
#include <windows.h>
#include <iostream>

using namespace std;

Node* addNode(Node* root, int value) { //Uses recursion to add node to tree
	if (root == nullptr) {
		root = new Node();
		root->value = value;
		root->left = root->right = nullptr;
	}
	else if (value <= root->value) { // traverses to left
		root->left = addNode(root->left, value);
	}
	else {// traverses to right
		root->right = addNode(root->right, value);
	}

	return root;
}

Node* deleteNode(Node* root, int value) {//deletes node from tree with recursion

	if (value < root->value) {//if input is less than the tree root value
		root->left = deleteNode(root->left, value);
	}
	else if (value > root->value) {//if input is greater than the tree root value
		root->right = deleteNode(root->right, value);
	}
	else if (value == root->value) {//Value found in tree
		if (root->right == nullptr && root->left == nullptr)//node has no extendable leafs
		{
			delete root;
			root = nullptr;
		}
		else if (root->right != nullptr && root->left == nullptr) {//node has one extendable leaf (to the right)
			Node* pointer = root;
			root = root->right;
			delete pointer;
		}
		else if (root->left != nullptr && root->right == nullptr) {//node has one extendable leaf (to the left)
			Node* pointer = root;
			root = root->left;
			delete pointer;
		}
		else {//node has two leafs

			Node* pointer = root->right;

			while (pointer->left != nullptr) {
				pointer = pointer->left;
			}
			root->value = pointer->value;
			root->right = deleteNode(root->right, pointer->value);

		}

	}
	//Root will never != the value in this function 
	//inTree(); function will not allow nonexisting value to pass to this function
	return root;
}