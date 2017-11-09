#include "stdafx.h"
#include "Menu.h"
#include <iostream>
#include <iomanip>

using namespace std;

static int getFirstMenuOption();
static int getSecondMenuOption();

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::mainMenu()
{

	int option= Menu::getFirstMenuOption();

	switch (option)
	{
	
	case 1:

	}

}

int Menu::getFirstMenuOption()
{
	int option;
	cout << "//////////////////////////////////////////////////////\n";
	cout << setw(27) << "Menu" << endl;
	cout << "//////////////////////////////////////////////////////\n";
	cout << "            " << "Option 1: Give a name to a list" << endl;
	cout << "            " << "Option 2: Display all lists" << endl;
	cout << "            " << "Option 3: Concatenate two lists" << endl;
	cout << "            " << "Option 4: Manage a list" << endl;
	cout << "            " << "Option 0: Exit" << endl;
	cout << "//////////////////////////////////////////////////////\n" << endl;
	cin >> option;
	return option;
}

int Menu::getSecondMenuOption()
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
