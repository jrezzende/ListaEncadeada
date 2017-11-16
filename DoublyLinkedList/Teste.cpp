#include <crtdbg.h>
#include "Menu.h"

void main() 
{
	_CrtMemState s1;

	Menu::menu();

	_CrtMemCheckpoint(&s1);
	_CrtMemDumpStatistics(&s1);
	_CrtDumpMemoryLeaks();
}
	