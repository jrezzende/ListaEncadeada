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

public:
	ListManager() { firstList= nullptr; secondList= nullptr; currentList= firstList; };
	~ListManager() { firstList= secondList= nullptr; };

	void createBothLists(std::string& nameList1, std::string& nameList2);
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

#endif // INCLUDED_LISTMANAGER_H
