#include "stdafx.h"
#include "User.h"
#include "List.h"

void User::uPrependNode(List& list)
{
	system("cls");
	std::cout << "Set an initial node data value: \n";
	int value;
	cin >> value;
	list.prependNode(value);
	system("cls");
	std::cout << "Node successfully added.\n";
}

void User::uAppendNode(List& list)
{
	system("cls");
	std::cout << "Set an initial node data value: \n";
	int value;
	cin >> value;
	list.appendNode(value);
	system("cls");
	std::cout << "Node successfully added.\n";
}

void User::uAddInPosition(List& list)
{
	system("cls");
	list.displayAsc();

	std::cout << "///////////////////////////" << endl;
	std::cout << "Set an initial node data value: \n";
	int value;
	cin >> value;

	std::cout << "Set the position you want to add a node.\n";
	int pos;
	cin >> pos;

	list.addInPosition(value, pos);

	bool flag;

	if (list.getPosition(pos)->getData() == value)
		flag= true;

	else
		flag= false;

	if (flag)
		std::cout << "Node successfully added.\n";
	else
		std::cout << "Error while requesting node addition (invalid position value)\n";
}

void User::uDisplayAsc(List& list)
{
	system("cls");
	list.displayAsc();

	std::cout << endl;
}

void User::uDisplayDesc(List& list)
{
	system("cls");
	list.displayDesc();
}

void User::uSortList(List& list)
{
	system("cls");
	list.sortList();
	std::cout << "List was successfully sorted.\n";
}

bool User::uRemoveInPos(List& list)
{
	system("cls");
	list.displayAsc();
	std::cout << "Choose a position to remove a node from the list.\n";
	int pos;
	cin >> pos;

	if (pos == list.getListSize())
	{
		list.removeLast();
	}
	else if (pos == 1)
	{
		list.removeFirst();
	}

	int prevSize;

	prevSize= list.getListSize();

	list.removeInPos(pos);

	if (list.getListSize() == (prevSize - 1))
		return true;

	else
		return false;
}

void User::uCreateBothLists(ListManager& lmanager)
{
	system("cls");
	std::cout << "Enter a string for the first list name\n";
	string firstName;
	cin >> firstName;
	std::cout << "Enter a string for the second list name (must be different from the first)\n";
	string secondName;
	cin >> secondName;

	if (firstName == secondName) {
		uCreateBothLists(lmanager);
	}

	lmanager.createBothLists(firstName, secondName);
	system("cls");
	cout << "Both lists created successfully.\n";
}

void User::uDisplayLists(ListManager& lmanager)
{
	system("cls");


	if(!lmanager.firstList && !lmanager.secondList)
	{
		cout << "No list available.\n";
		return;
	}

	lmanager.displayLists();
}

void User::uDeleteLists(ListManager& lmanager)
{
	system("cls");
	lmanager.firstList->deleteAllNodes();
	lmanager.firstList= nullptr;
	lmanager.secondList->deleteAllNodes();
	lmanager.secondList= nullptr;
	cout << "Both lists deleted successfully.\n";
}

bool User::uConcatenateLists(ListManager& lmanager)
{
	system("cls");

	if (!lmanager.firstList || !lmanager.secondList) {
		std::cout << "You need at least two lists available to concatenate.\n";
		return false;
	}

	cout << "Choose the order of concatenation by entering a list position\n";
	int pos;
	cin >> pos;
	
	lmanager.concatenateLists(pos);

	int totalSize= lmanager.firstList->getListSize() + lmanager.secondList->getListSize();

	if (lmanager.currentList->getListSize() == totalSize) {
		std::cout << "Lists have been successfully concatenated.\n";
		return true;
	}

	else {
		std::cout << "Operation failed.\n";
		return false;
	}
}

List * User::uSetCurrentList(ListManager& lmanager)
{
	lmanager.displayLists();
	std::cout << "///////////////////////////\n";
	std::cout << "Choose a list position to work on\n";
	int num;
	cin >> num;
	system("cls");
	if (num != 1 && num != 2)
	{
		std::cout << "Invalid position, choose either the first or the second list.\n";
		return nullptr;
	}

	lmanager.setCurrentList(num);

	return lmanager.currentList;
}


