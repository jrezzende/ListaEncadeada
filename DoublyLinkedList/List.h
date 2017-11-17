#pragma once
#ifndef INCLUDED_LIST_H
#define INCLUDED_LIST_H

#include <string>

class List
{
private:
	struct Node 
	{
		int data;

		Node *nextNode;
		Node *prevNode;

		Node() : data(0), nextNode(nullptr), prevNode(nullptr) {}
		Node(int value) : data(value), nextNode(nullptr), prevNode(nullptr) {}

		int getData() { return data; }
      void setData(int value) { data= value; }
	};

	Node *head;
	Node *tail;
	int listSize;

private:
   Node *getHead();
   Node *getTail();
   Node* getPosition(int pos);

public:
	std::string listName;

public:
   ~List() { deleteAllNodes(); }
   List();
	List(int value);
	List(std::string);

   int getListSize();

	void prependNode(int value);
	void appendNode(int value);
	void addInPosition(int pos, int value);

	void removeFirst();
	void removeLast();
	void removeInPos(int pos);
   void deleteAllNodes();

	void sortList();
	void displayAsc();
	void displayDesc();

	void concatList(List& toConcat);
};

#endif // INCLUDED_LIST_H