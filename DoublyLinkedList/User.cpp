#include "stdafx.h"
#include "User.h"
#include "List.h"

void User::uPrependNode(ListManager& lmanager)
{
	system("cls");
	std::cout << "Set an initial node data value: \n";
	int value;
	cin >> value;
	lmanager.getCurrentList()->prependNode(value);
	system("cls");
	std::cout << "Node successfully added.\n";
}

void User::uAppendNode(ListManager& lmanager)
{
	system("cls");
	std::cout << "Set an initial node data value: \n";
	int value;
	cin >> value;
	lmanager.getCurrentList()->appendNode(value);
	system("cls");
	std::cout << "Node successfully added.\n";
}

void User::uAddInPosition(ListManager& lmanager)
{
	system("cls");
	lmanager.getCurrentList()->displayAsc();

	std::cout << "///////////////////////////" << endl;
	std::cout << "Set an initial node data value: \n";
	int value;
	cin >> value;

	std::cout << "Set the position you want to add a node.\n";
	int pos;
	cin >> pos;

	lmanager.getCurrentList()->addInPosition(value, pos);

		std::cout << "Node successfully added.\n";
}

void User::uDisplayAsc(ListManager& lmanager)
{
	system("cls");
	lmanager.getCurrentList()->displayAsc();

	std::cout << endl;
}

void User::uDisplayDesc(ListManager& lmanager)
{
	system("cls");
	lmanager.getCurrentList()->displayDesc();
}

void User::uSortList(ListManager& lmanager)
{
	system("cls");

	if (!lmanager.getCurrentList()->getHead())
	{
		std::cout << "The list is empty\n";
		return;
	}

	lmanager.getCurrentList()->sortList();
	std::cout << "List was successfully sorted.\n";
}

void User::uRemoveInPos(ListManager& lmanager)
{
	system("cls");

	if (lmanager.getCurrentList()->getHead() == nullptr)
	{
		cout << "There is no node available for deletion.\n";
		return;
	}

	lmanager.getCurrentList()->displayAsc();
	std::cout << "Choose a position to remove a node from the list.\n";
	int pos;
	cin >> pos;

	if (pos >= lmanager.getCurrentList()->getListSize())
	{
		lmanager.getCurrentList()->removeLast();
	}
	else if (pos <= 1)
	{
		lmanager.getCurrentList()->removeFirst();
	}
	else
		lmanager.getCurrentList()->removeInPos(pos);
}

void User::uDeleteAllNodes(ListManager& lmanager)
{
	system("cls");

	if (lmanager.getCurrentList()->getHead() == nullptr)
	{
		cout << "List is already empty.\n";
		return;
	}

	lmanager.getCurrentList()->deleteAllNodes();
	cout << "List successfully cleared.\n";
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


	if(!lmanager.getFirstList() && !lmanager.getSecondList())
	{
		cout << "No list available.\n";
		return;
	}

	lmanager.displayLists();
}

void User::uDeleteLists(ListManager& lmanager)
{
	system("cls");

	if (lmanager.getFirstList() == nullptr && lmanager.getSecondList() == nullptr)
	{
		cout << "No list available to delete.\n";
		return;
	}

	lmanager.getFirstList()->deleteAllNodes();
	lmanager.setFirstList(nullptr);
	lmanager.getSecondList()->deleteAllNodes();
	lmanager.setSecondList(nullptr);

	cout << "Both lists deleted successfully.\n";
}

bool User::uConcatenateLists(ListManager& lmanager)
{
	system("cls");

	if (!lmanager.getFirstList() || !lmanager.getSecondList()) {
		std::cout << "You need at least two lists available to concatenate.\n";
		return false;
	}

	if (lmanager.getFirstList()->getHead() == nullptr || lmanager.getSecondList()->getHead() == nullptr)
	{
		std::cout << "List is empty, cannot concatenate.\n";
		return false;
	}

	cout << "Choose the list you want to attach and the end.\n";
	int pos;
	cin >> pos;
	
	lmanager.concatenateLists(pos);

}

void User::uSetCurrentList(ListManager& lmanager)
{

	if (lmanager.getFirstList() == nullptr || lmanager.getSecondList() == nullptr)
	{
		std::cout << "No list available.\n";
		return;
	}

	lmanager.displayLists();
	std::cout << "///////////////////////////\n";
	std::cout << "Choose a list position to work on\n";
	int num;
	cin >> num;
	system("cls");
	if (num != 1 && num != 2)
	{
		std::cout << "Invalid position, choose either the first or the second list.\n";
		return;
	}
	lmanager.setCurrentList(num);
}



