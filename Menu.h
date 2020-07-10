#pragma once

class Menu {
public:
	int option = 0;
	int input = 0;
	int flagSearch = 0;//if input is in tree or not
	int flagBracnhes = 0;
	Node* root = nullptr;

public:
	Menu();
};