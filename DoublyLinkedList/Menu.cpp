#include "stdafx.h"
#include "Menu.h"
#include <iostream>
#include <iomanip>

using namespace std;

Menu::Menu()
{
}

void Menu::displayFirstMenu(ListManager& lmanager)
{
	system("cls");
	
	int op;

	do {
		op= getFirstOp();
		switch (op)
		{
		case 1: lmanager.createBothLists(); break;
		case 2: lmanager.displayLists(); break;
		case 3: lmanager.concatenateLists();

		default:
			break;
		}
	}
}

void Menu::displaySecondMenu(ListManager &, List &)
{
}

Menu::~Menu()
{
}



int Menu::getFirstOp()
{
	int option;
	cout << "//////////////////////////////////////////////////////\n";
	cout << setw(27) << "Menu" << endl;
	cout << "//////////////////////////////////////////////////////\n";
	cout << "            " << "Option 1: Create both lists" << endl;
	cout << "            " << "Option 2: Display all lists" << endl;
	cout << "            " << "Option 3: Concatenate two lists" << endl;
	cout << "            " << "Option 4: Delete a list" << endl;
	cout << "            " << "Option 5: Manage a list" << endl;
	cout << "            " << "Option 0: Exit" << endl;
	cout << "//////////////////////////////////////////////////////\n" << endl;
	cin >> option;

	return option;
}


int Menu::getSecondOp()
{
	int option;

	cout << "/////////////////////////////////////////////////////////////////\n";
	cout << setw(43) << "Menu->List Manager" << endl;
	cout << "/////////////////////////////////////////////////////////////////\n";
	cout << "            " << "Option 1: Prepend a node (attach to first position)" << endl;
	cout << "            " << "Option 2: Append a node (attach to last position)" << endl;
	cout << "            " << "Option 3: Add in a specific position" << endl;
	cout << "            " << "Option 4: Change specific node data value" << endl;
	cout << "            " << "Option 5: List all nodes" << endl;
	cout << "            " << "Option 6: List all nodes in reverse" << endl;
	cout << "            " << "Option 7: Sort list" << endl;
	cout << "            " << "Option 8: Clear list" << endl;
	cout << "            " << "Option 9: Back to previous menu" << endl;
	cout << "            " << "Option 0: Exit" << endl;
	cout << "/////////////////////////////////////////////////////////////////\n" << endl;
	cin >> option;
	
	return option;
}


