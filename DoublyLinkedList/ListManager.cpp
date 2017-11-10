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

void ListManager::createBothLists()
{
	firstList= new List();
	secondList= new List();
}

void ListManager::setListName(std::string name) // set name to an attrib list(first or second)
{
	if (currentList)
		currentList->setListName(name);
	else
		cout << "There is no list available\n";
	return;
}

void ListManager::displayLists() // display attrib name 
{
	if (firstList)
		if (firstList->listName == "")
			cout << "Empty list name.";
		cout << "List name: " << firstList->listName << endl;
		firstList->displayAsc();
	
	if (secondList)
		if (secondList->listName == "")
			cout << "Empty list name.";
		cout << "List name: " << secondList->listName << endl;
		secondList->displayAsc();

		return;
}

bool ListManager::concatenateLists(List * toConcat) //if list total size = list1+list2(size) ret true
{
	if (toConcat == secondList)
		currentList->concatList(secondList);

	else if (toConcat == firstList)
		currentList->concatList(firstList);

	int totalSize= toConcat->getListSize + currentList->getListSize();

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
