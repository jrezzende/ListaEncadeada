#pragma once
#ifndef LIST_MANAGER_H
#define LIST_MANAGER_H
#include "List.h"
#include "Menu.h"

class ListManager 
{
private:
	List *firstList;
	List *secondList;
	List *currentList; // set current list

public:
	ListManager() { firstList= nullptr; secondList= nullptr; currentList= firstList; };
	~ListManager() { firstList= secondList= nullptr; };

	void createBothLists(string, string);
	void displayLists();
	bool concatenateLists(int pos);
	void deleteLists();
	void setCurrentList(int n);
	void setFirstList(List*);
	void setSecondList(List*);

	List* getFirstList();
	List* getSecondList();
	List* getCurrentList();

};

#endif // !LIST_MANAGER_H
