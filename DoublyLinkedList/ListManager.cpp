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

void ListManager::setFirstList(List* list)
{
	firstList= list;
}

void ListManager::setSecondList(List* list)
{
	secondList= list;
}

List * ListManager::getFirstList()
{
	return firstList;
}

List * ListManager::getSecondList()
{
	return secondList;
}

List * ListManager::getCurrentList()
{
	return currentList;
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
		{
			cout << "Invalid list number, cannot concatenate.\n";
			return false;
		}

	if (pos == 1)
	{
		secondList->concatList(firstList);
		totalSize= secondList->getListSize() + firstList->getListSize();
		cout << "List one was successfully attached to the end of list two\n";
	}
	else if (pos == 2)
	{
		firstList->concatList(secondList);
		totalSize= firstList->getListSize() + secondList->getListSize();
		cout << "List two was successfully attached to the end of list one\n";
	}
}

void ListManager::deleteLists() // clear name and list nodes
{
	currentList->deleteAllNodes();

	currentList->listName= "";

	cout << "List has been cleared\n";
}


