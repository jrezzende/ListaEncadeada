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

	public:
		List();
		List(int value);
		~List();

		Node *getHead();
		Node *getTail();
		void prependNode(int value);
		void appendNode(int value);
		Node* getPosition(int pos);
		void addInPosition(int pos, int value);
		void removeFirst();
		void removeLast();
		void removeInPos(int pos);
		void displayAsc();
		void displayDesc();
		void sortList();
		void concatList(List *toConcat);
		void deleteAllNodes();
		int getListSize();
};
#endif