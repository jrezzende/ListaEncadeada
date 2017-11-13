#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "List.h"
#include "Menu.h"
#include "ListManager.h"

using namespace std;

void main() 
{
	_CrtMemState s1;

	Menu::Menu();

	_CrtMemCheckpoint(&s1);
	_CrtMemDumpStatistics(&s1);
	_CrtDumpMemoryLeaks();
}
	