#pragma once
#ifndef MENU_H
#define MENU_H
#include "List.h"
#include "ListManager.h"
#include "User.h"
class User;
class ListManager;

namespace Menu
{
		void Menu();
		void displayFirstMenu(ListManager&, User&);
		void displaySecondMenu(ListManager&, User&, List&);
		int getFirstOp();
		int getSecondOp(List&);

};

#endif // !MENU_H */
