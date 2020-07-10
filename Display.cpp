#include "Display.h"
#include <windows.h>
#include <iostream>

using namespace std;

void gotoxy(int x, int y)
{
	COORD coordinates;     // coordinates is declared as COORD
	coordinates.X = x;     // defining x-axis
	coordinates.Y = y;     //defining  y-axis
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void OpeningBorder() { 
	cout << char(218); //top left
	for (int i = 0; i < 20; i++) {//top
		cout << char(196);
	}
	cout << char(191);//top right;
	for (int i = 1; i < 12; i++) {//left
		gotoxy(0, i);
		cout << char(179);
	}

	gotoxy(0, 12);
	cout << char(192);//bottom left
	for (int i = 0; i < 20; i++) {//bottom
		cout << char(196);
	}
	cout << char(217);//bottom right

	for (int i = 1; i < 12; i++) {//right
		gotoxy(21, i);
		cout << char(179);
	}
	gotoxy(1, 2);
	for (int i = 0; i < 20; i++) {//menu split
		cout << char(196);
	}
}

void OpeningText() {
	gotoxy(1, 1);
	cout << "        Menu";
	gotoxy(1, 3);
	cout << "1: Add Number";
	gotoxy(1, 4);
	cout << "2: Delete Number";
	gotoxy(1, 5);
	cout << "3: LNR Tree Data";
	gotoxy(1, 6);
	cout << "4: NLR Tree Data";
	gotoxy(1, 7);
	cout << "5: LRN Tree Data";
	gotoxy(1, 8);
	cout << "6: Exit Program";
	gotoxy(1, 10);
	cout << "Chose Option: ";
	gotoxy(1, 11);
	cout << "Enter Number: ";
}

void ClearNumber(int x, int y) {
	gotoxy(x, y);
	cout << "    ";
	gotoxy(x, y);
}
void ClearChunk(int x, int y) {
	gotoxy(x, y);
	cout << "                                            ";
}

void PrintRoot(Node* root) {
	if (root != nullptr) {
		gotoxy(53, 17);
		cout << "ROOT";
	}
	else {
		gotoxy(53, 17);
		cout << "    ";
	}
}