#pragma once
#ifndef INCLUDE_LIST_H
#define INCLUDE_LIST_H

#include "Node.h";



class List
{
	private:
		Node *head;
		Node *tail;
		int listSize;
		std::string listName;

	public:
		List(); // default constructor
		List(int value); // constructor assigning a data
		List(std::string name);
		~List(); // destructor

		Node *getHead(); // return first node
		Node *getTail(); // return last node
		void prependNode(int value); // insert node at the beggining of a list
		void appendNode(int value); // insert node at the end of a list
		Node* getPosition(int pos); // return node in a specific position
		void addInPosition(int pos, int value); // insert node at specific position
		void removeFirst(); // remove first node
		void removeLast(); // remove last node
		void removeInPos(int pos); // remove node in a specific position
		void sortList(); // bubble sort a list
		void displayAsc(); // display nodes
		void displayDesc(); // display nodes in reverse order
		void concatList(List *toConcat); // concatenate a list to another
		void deleteAllNodes(); // clear list
		int getListSize(); // return list size
		void setListName(std::string newName); // set a name to a list
};
#endif