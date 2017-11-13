#include "stdafx.h"
#include "ListManager.h"

void ListManager::setCurrentList(int n)
{
	if (n == 1)
		currentList= firstList;
	else if (n == 2)
		currentList= secondList;
	else
		cout << "Invalid option, choose either '1' or '2'.\n";
		return;
}

void ListManager::createBothLists(string firstName, string secondName)
{

	firstList= new List(firstName);
	secondList= new List(secondName);
}

void ListManager::displayLists() // display attrib name 
{
	int position = 1;
		cout << "In position: " << position++ << " the list name is: " << firstList->listName << endl;

		cout << "In position: " << position << " the list name is: " << secondList->listName << endl;

		return;
}

bool ListManager::concatenateLists(int pos) //if list total size = list1+list2(size) ret true
{

	int totalSize;

	if (pos != 1 && pos != 2)
		return false;

	if (pos == 1)
	{
		secondList->concatList(firstList);
		totalSize= secondList->getListSize() + firstList->getListSize();
	}
	else if (pos == 2)
	{
		firstList->concatList(secondList);
		totalSize= firstList->getListSize() + secondList->getListSize();
	}

	if (currentList->getListSize() == totalSize)
	{
		cout << "Lists have been concatenated\n";
		return true;
	}
	else
	{
		cout << "Couldn't concatenate lists.\n";
		return false;
	}
}

void ListManager::deleteLists() // clear name and list nodes
{
	currentList->deleteAllNodes();

	currentList->listName= "";

	cout << "List has been cleared\n";
}
