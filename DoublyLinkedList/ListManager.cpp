#include "ListManager.h"
#include "List.h"
#include <iostream>
void ListManager::setCurrentList(int n)
{
	if (n == 1)
		currentList= firstList;
	else if (n == 2)
		currentList= secondList;
	else
		std::cout << "Invalid option, choose either '1' or '2'.\n";
	
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

List* ListManager::getFirstList()
{
	return firstList;
}

List* ListManager::getSecondList()
{
	return secondList;
}

List* ListManager::getCurrentList()
{
	return currentList;
}

void ListManager::createBothLists(std::string& nameList1, std::string& nameList2)
{
	firstList= new List(nameList1);
	secondList= new List(nameList2);
}

void ListManager::displayLists()
{
	int position = 1;

	std::cout << "In position: " << position++ << " the list name is: " << firstList->listName << std::endl;

	std::cout << "In position: " << position << " the list name is: " << secondList->listName << std::endl;

	return;
}

bool ListManager::concatenateLists(int pos)
{
	int totalSize;

	if ((pos != 1) && (pos != 2)) {
			std::cout << "Invalid list number, cannot concatenate.\n";
			return false;
	}

	if (pos == 1) {
		secondList->concatList(firstList);
		totalSize= secondList->getListSize() + firstList->getListSize();

		std::cout << "List one was successfully attached to the end of list two\n";
	}
	else if (pos == 2) {
		firstList->concatList(secondList);
		totalSize= firstList->getListSize() + secondList->getListSize();

		std::cout << "List two was successfully attached to the end of list one\n";
	}
}

void ListManager::deleteLists()
{
	currentList->deleteAllNodes();
	currentList->listName= "";

	std::cout << "List has been cleared\n";
}


