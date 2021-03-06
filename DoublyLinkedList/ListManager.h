#pragma once
#ifndef INCLUDED_LISTMANAGER_H
#define INCLUDED_LISTMANAGER_H

#include <string>

class List;

class ListManager 
{
private:
	List *firstList;
	List *secondList;
	List *currentList;
   bool isInitLists= false;

public:
   enum ListOption { List1, List2 };

   ~ListManager();
   ListManager() { firstList= nullptr; secondList= nullptr; currentList= firstList; }

   bool areCreatedLists() { return isInitLists; }
	void createBothLists(std::string& nameList1, std::string& nameList2);
	void displayLists();
	bool concatenateLists(int pos);
	void deleteLists();

	void setCurrentList(ListOption lo);

	List& getFirstList();
	List& getSecondList();
	List& getCurrentList();
};

#endif // INCLUDED_LISTMANAGER_H
