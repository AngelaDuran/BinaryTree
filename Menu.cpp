#include <iostream>
#include <string>
#include <Windows.h>
#include "Display.h"
#include "TreeSetup.h"
#include "TreeTraverse.h"
#include "ChangeNode.h"
#include "Menu.h"

using namespace std;

Menu::Menu(){

	OpeningBorder(); // Displays border around menu
	OpeningText(); //Text for the menu

	while (option != 6) { //Loops until the user presses 6 on keyboard
		gotoxy(15, 10);
		cin >> option; //User input for menu
		ClearChunk(0, 14);
		ClearChunk(30, 5);

		switch (option) {
		case 1://Add node
			gotoxy(15, 11);
			cin >> input;
			root = addNode(root, input);
			DisplayTree(root, 60, 17, 40); //display new tree
			PrintRoot(root);
			break;
		case 2://Deletee node
			gotoxy(15, 11);
			cin >> input;
			flagSearch = inTree(root, input); //Determines input is in current tree
			if (flagSearch == 0) {
				gotoxy(0, 14);
				cout << "Value not found in tree!";
			}
			else {

				root = deleteNode(root, input); //remove node from tree
				system("cls");
				OpeningBorder();
				OpeningText();
				DisplayTree(root, 60, 17, 40); //reprints tree after deletion
				PrintRoot(root);
				gotoxy(0, 14);
				cout << "Value found and deleted!";
			}
			break;
		case 3:
			ClearChunk(30, 5); //Clears area and prints LNR data
			DisplayLNR(root);
			break;
		case 4:
			ClearChunk(30, 5); //Clears area and prints NLR data
			DisplayNLR(root);

			break;
		case 5:
			ClearChunk(30, 5); //Clears area and prints LRN data
			DisplayLRN(root);
			break;
		case 6:
			//will escape while loop
			break;
		}


		ClearNumber(15, 10); //clears display of older data.
		ClearNumber(15, 11);

	}//while loop end
}

