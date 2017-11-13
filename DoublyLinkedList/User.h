#pragma once
#ifndef USER_H
#define USER_H

#include "List.h"
#include "ListManager.h"
#include "Menu.h"

class ListManager;

class User 
{
public:
	void uPrependNode(List&); // user interaction to prepend a node
	void uAppendNode(List&); // user interaction to append a node
	void uAddInPosition(List&); // user interaction to add a node in a specific position
	void uDisplayAsc(List&); // user interaction to display list nodes
	void uDisplayDesc(List&); // user interaction to display lists in descending order
	void uSortList(List&); // user interaction to sort a list
	bool uRemoveInPos(List &); // user interaction to delete a node from a specific position

	void uCreateBothLists(ListManager&); // user interaction to creathe both attribute lists
	void uDisplayLists(ListManager&); // user interaction to display both lists
	void uDeleteLists(ListManager&); // user interaction to clear a list
	bool uConcatenateLists(ListManager&); // user interaction to concatenate lists
	List *uSetCurrentList(ListManager&); // user interaction to set current list workspace
};

#endif // !USER_H

