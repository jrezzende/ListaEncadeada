#include <iostream>
#include "List.h"
#include "ListManager.h"

////////////////////////////////////////////////////////////////////////////////

ListManager::~ListManager()
{
   if (firstList) delete firstList;
   if (secondList) delete secondList;

   firstList= secondList= nullptr;
}

void ListManager::setCurrentList(ListOption lo)
{
   if (lo == List1) {
      currentList= firstList;
      return;
   }
	// (lo == List2)
	currentList= secondList;
}

List& ListManager::getFirstList() { return *firstList; }

List& ListManager::getSecondList() { return *secondList; }

List& ListManager::getCurrentList()
{
	return *currentList;
}

////////////////////////////////////////////////////////////////////////////////

void ListManager::createBothLists(std::string& nameList1, std::string& nameList2) 
{
   if (firstList)
      firstList->deleteAllNodes();
   else
      firstList= new List;

   if (secondList)
      secondList->deleteAllNodes();
   else
      secondList= new List;

   firstList->listName= nameList1;
	secondList->listName= nameList2;

   isInitLists= true;
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
	if ((pos != 1) && (pos != 2))
      return false;

   if (pos == 1)
      secondList->concatList(*firstList);
   else if (pos == 2)
      firstList->concatList(*secondList);

   return true;
}

void ListManager::deleteLists()
{
	currentList->deleteAllNodes();
	currentList->listName= "";
   
   return;
}


