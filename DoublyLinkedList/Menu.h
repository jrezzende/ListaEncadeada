#pragma once
#ifndef MENU_H
#define MENU_H
#include "List.h"
#include "ListManager.h"

class Menu
{

	public:

		List firstList;
		List secondList;

		Menu();
		
		void displayFirstMenu(ListManager&);
		void displaySecondMenu(ListManager&, List&);
		int getFirstOp();
		int getSecondOp();

};

#endif // !MENU_H */
