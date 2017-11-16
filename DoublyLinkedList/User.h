#pragma once
#ifndef INCLUDED_USER_H
#define INCLUDED_USER_H

class ListManager;

class User 
{
public:
   // Methods over both lists
	void uCreateBothLists(ListManager&);
	void uDisplayLists(ListManager&);
	void uDeleteLists(ListManager&);
	bool uConcatenateLists(ListManager&); 
	void uSetCurrentList(ListManager&); 

   // Methods while managing a list
   void uPrependNode(ListManager&);
   void uAppendNode(ListManager&);
   void uAddInPosition(ListManager&);

   void uDisplayAsc(ListManager&);
   void uDisplayDesc(ListManager&);
   void uSortList(ListManager&);

   void uRemoveInPos(ListManager&);
   void uDeleteAllNodes(ListManager&);
};

#endif // INCLUDED_USER_H

