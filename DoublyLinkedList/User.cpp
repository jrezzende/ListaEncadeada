#include "User.h"
#include "List.h"
#include "ListManager.h"
#include <iostream>

void User::uPrependNode(ListManager& lm)
{
   int value;
   
   system("cls");
	std::cout << "Set an initial node data value: \n";
	std::cin >> value;

	lm.getCurrentList().prependNode(value);

   system("cls");
	std::cout << "Node successfully added.\n";
}

void User::uAppendNode(ListManager& lm)
{
   int value;
   
   system("cls");
	std::cout << "Set an initial node data value: \n";
   std::cin >> value;

	lm.getCurrentList().appendNode(value);

   system("cls");

	std::cout << "Node successfully added.\n";
}

void User::uAddInPosition(ListManager& lm)
{
	system("cls");
	lm.getCurrentList().displayAsc();

   int value;
   int pos;

	std::cout << "///////////////////////////" << std::endl;

	std::cout << "Set an initial node data value: \n";
   std::cin >> value;

	std::cout << "Set the position you want to add a node.\n";
   std::cin >> pos;

	lm.getCurrentList().addInPosition(value, pos);

	std::cout << "Node successfully added.\n";
}

void User::uDisplayAsc(ListManager& lm)
{
	system("cls");

	lm.getCurrentList().displayAsc();

	std::cout << std::endl;
}

void User::uDisplayDesc(ListManager& lm)
{
	system("cls");
	lm.getCurrentList().displayDesc();
}

void User::uSortList(ListManager& lm)
{
	system("cls");

	if (!lm.getCurrentList().getListSize()) {
		std::cout << "The list is empty\n";
		return;
	}

	lm.getCurrentList().sortList();

	std::cout << "List was successfully sorted.\n";
}

void User::uRemoveInPos(ListManager& lm)
{
	system("cls");

	if (!lm.getCurrentList().getListSize()) {
      std::cout << "There is no node available for deletion.\n";
		return;
	}

   int pos;

   lm.getCurrentList().displayAsc();
	std::cout << "Choose a position to remove a node from the list.\n";
   std::cin >> pos;

	if (pos >= lm.getCurrentList().getListSize())
		lm.getCurrentList().removeLast();
	else if (pos <= 1) 
		lm.getCurrentList().removeFirst();
	else
		lm.getCurrentList().removeInPos(pos);
}

void User::uDeleteAllNodes(ListManager& lm)
{
	system("cls");

	if (!lm.getCurrentList().getListSize()) {
      std::cout << "List is already empty.\n";
		return;
	}

	lm.getCurrentList().deleteAllNodes();

   std::cout << "List successfully cleared.\n";
}

void User::uCreateBothLists(ListManager& lm)
{
	system("cls");

   std::string firstName;
   std::string secondName;

	std::cout << "Enter a string for the first list name\n";
   std::cin >> firstName;

	std::cout << "Enter a string for the second list name (must be different from the first)\n";
   std::cin >> secondName;

	if (firstName == secondName) 
		uCreateBothLists(lm);

	lm.createBothLists(firstName, secondName);

	system("cls");
   std::cout << "Both lists created successfully.\n";
}

void User::uDisplayLists(ListManager& lm)
{
	system("cls");

	if (!lm.areCreatedLists()) {
      std::cout << "No list available.\n";
		return;
	}

	lm.displayLists();
}

void User::uDeleteLists(ListManager& lm)
{
	system("cls");

	if (!lm.areCreatedLists()) {
      std::cout << "No list available to delete.\n";
		return;
	}

	lm.getFirstList().deleteAllNodes();
	lm.getSecondList().deleteAllNodes();

   std::cout << "Both lists deleted successfully.\n";
}

bool User::uConcatenateLists(ListManager& lm)
{
	system("cls");

   if (!lm.areCreatedLists()) {
		std::cout << "You need at least two lists available to concatenate.\n";
		return false;
	}

   int pos;

   std::cout << "Choose the list you want to attach at the end.\n";
   std::cin >> pos;
	
	return lm.concatenateLists(pos);
}

void User::uSetCurrentList(ListManager& lm)
{
	lm.displayLists();

   int num;

	std::cout << "///////////////////////////\n";
	std::cout << "Choose a list position to work on\n";
   std::cin >> num;
   system("cls");

	if (num != 1 && num != 2) {
		std::cout << "Invalid position, choose either the first or the second list.\n";
		return;
	}

	lm.setCurrentList((num == 1) ? ListManager::List1 : ListManager::List2);
}
