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
	void uPrependNode(ListManager&);
	void uAppendNode(ListManager&);
	void uAddInPosition(ListManager&);
	void uDisplayAsc(ListManager&);
	void uDisplayDesc(ListManager&);
	void uSortList(ListManager&);
	void uRemoveInPos(ListManager&);
	void uDeleteAllNodes(ListManager&);

	void uCreateBothLists(ListManager&);
	void uDisplayLists(ListManager&);
	void uDeleteLists(ListManager&);
	bool uConcatenateLists(ListManager&); 
	void uSetCurrentList(ListManager&); 
};

#endif // !USER_H

