#include "Display.h"
#include "TreeTraverse.h"
#include "ChangeNode.h"
#include <windows.h>
#include <iostream>

using namespace std;

int inTree(Node* root, int value) {
	if (root == nullptr) {
		return 0;
	}
	else if (root->value == value) {
		return 1;
	}
	else if (value <= root->value) {
		return inTree(root->left, value);
	}
	else {
		return inTree(root->right, value);
	}
}

void LNR(Node* root) { //Prints Inorder tree traversal
	if (root != NULL) {
		LNR(root->left);
		cout << root->value << " ";
		LNR(root->right);
	}
}

void NLR(Node* root) { //Prints Preorder tree traversal
	if (root != NULL) {
		cout << root->value << " ";
		NLR(root->left);
		NLR(root->right);
	}
}

void LRN(Node* root) { //Prints Postorder tree traversal
	if (root != NULL) {
		LRN(root->left);
		LRN(root->right);
		cout << root->value << " ";
	}
}

void DisplayLNR(Node* root) {
	gotoxy(30, 5);
	cout << "LNR Tree Printed: ";
	LNR(root); //will print out tree in LNR order
}

void DisplayNLR(Node* root) {
	gotoxy(30, 5);
	cout << "NLR Tree Printed: ";
	NLR(root); //will print out tree in NLR order
}

void DisplayLRN(Node* root) {
	gotoxy(30, 5);
	cout << "LRN Tree Printed: ";
	LRN(root); //will print out tree in NLR order
}