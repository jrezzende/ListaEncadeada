#pragma once
#ifndef LIST_MANAGER_H
#define LIST_MANAGER_H
#include "List.h"
#include "Menu.h"

class ListManager 
{
public:
	List *firstList;
	List *secondList;
	List *currentList; // set current list

	~ListManager() { firstList= secondList= nullptr; };

	void createBothLists();
	void setListName(std::string name);
	void displayLists();
	bool concatenateLists(List *toConcat);
	void deleteLists();
	void setCurrentList(int n);

};

#endif // !LIST_MANAGER_H
