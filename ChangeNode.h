#pragma once

class Node {
public:
	int value;
	Node* right;
	Node* left;
	Node() { right = left = nullptr; }
};

Node* addNode(Node* root, int value);
Node* deleteNode(Node* root, int value);

