#include "Display.h"
#include "TreeTraverse.h"
#include "TreeSetup.h"
#include "ChangeNode.h"
#include <windows.h>
#include <iostream>

using namespace std;

void DisplayBoxNode(int x, int y) { //DIsplays the box around every tree node
	gotoxy(x - 2, y - 1);//top left
	cout << char(218);
	for (int i = 0; i < 5; i++) {//top
		cout << char(196);
	}
	gotoxy(x + 4, y - 1);//top right
	cout << char(191);
	gotoxy(x - 2, y + 1);//bottom left
	cout << char(192);
	for (int i = 0; i < 5; i++) {//bottom
		cout << char(196);
	}
	gotoxy(x + 4, y + 1);//bottom right
	cout << char(217);
	gotoxy(x - 2, y);//left
	cout << char(179);
	gotoxy(x + 4, y);//right
	cout << char(179);

	gotoxy(x, y);
}

void DisplayTreeLinks(Node* root, int x_coord, int y_coord, int width) { //Displays the connections between nodes

	if (root->left != nullptr) { //displays links for left nodes to root
		gotoxy(x_coord - 1, y_coord + 2);
		cout << char(179);
		gotoxy(x_coord - 1, y_coord + 3);
		cout << char(179);
		gotoxy(x_coord - 1, y_coord + 4);
		cout << char(217);

		gotoxy(x_coord - (width - 5), y_coord + 4);
		for (int i = 0; i < width - 6; i++) {
			cout << char(196);
		}

		gotoxy(x_coord, y_coord);

	}

	if (root->right != nullptr) { //displays links for right nodes to root
		gotoxy(x_coord + 3, y_coord + 2);
		cout << char(179);
		gotoxy(x_coord + 3, y_coord + 3);
		cout << char(179);
		gotoxy(x_coord + 3, y_coord + 4);
		cout << char(192);


		for (int i = 0; i < width - 5; i++) {
			cout << char(196);
		}

		gotoxy(x_coord, y_coord);
	}
}

void DisplayTree(Node* root, int x_coord, int y_coord, int width) { //Uses recurssion to display each tree node

	if (root == nullptr) {
		return;
	}
	else {
		gotoxy(x_coord, y_coord);
		DisplayBoxNode(x_coord, y_coord);//borders the number
		cout << root->value;
		width = width / 2;

		DisplayTreeLinks(root, x_coord, y_coord, width);

		DisplayTree(root->right, x_coord + width, y_coord + 4, width);
		DisplayTree(root->left, x_coord - width, y_coord + 4, width);

	}
}