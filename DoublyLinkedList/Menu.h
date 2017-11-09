#pragma once
#ifndef MENU_H
#define MENU_H
#include "List.h"

class Menu
{

	public:

		List firstList;
		List secondList;

		Menu();
		~Menu();
		
		void mainMenu();
		static int getFirstMenuOption();
		static int getSecondMenuOption();

};

#endif // !MENU_H
