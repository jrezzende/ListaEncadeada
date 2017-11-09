#include "stdafx.h"
#include <iostream>
#include "Node.h"
#include "List.h"

using namespace std;

void main() 
{
	List l;
	l.appendNode(9);
	l.appendNode(2);
	l.appendNode(1);
	l.appendNode(5);
	l.appendNode(3);
	l.appendNode(7);
	l.appendNode(4);
	l.displayAsc();
	std::cout << "----------------\n";
	l.sortList();
	l.displayAsc();
	// l.deleteAllNodes();
	// l.displayAsc();


	std::cout << "\n";
	// l.displayDesc();
	
}