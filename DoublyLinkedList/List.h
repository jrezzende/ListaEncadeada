#pragma once
#ifndef INCLUDE_LIST_H
#define INCLUDE_LIST_H
#include <string>
#include <iostream>
using namespace std;

class List
{
	private:

		struct Node 
		{
			int data;
			Node *nextNode;
			Node *prevNode;

			Node() : data(0), nextNode(nullptr), prevNode(nullptr) {} // default constructor
			Node(int value) : data(value), nextNode(nullptr), prevNode(nullptr) {} // param constructor

			int getData() { return data; } // get data value
			void setData(int value) { data= value; } // set data value


		};

		Node *head;
		Node *tail;
		int listSize;
		

	public:
		std::string listName;
		List(); // default constructor
		List(int value); // constructor assigning a data
		List(string);
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
};
#endif