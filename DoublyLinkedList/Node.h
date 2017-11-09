#pragma once
#ifndef INCLUDE_NODE_H
#define INCLUDE_NODE_H


class Node
{
	private:
		int data;
		Node *nextNode;
		Node *prevNode;
	
	public:
		Node(); // default node constructor (nullptrs)
		Node(int value); // constructor assigning a value to data
		~Node(); // destructor

 		int getData(); // returns data from node
		void setData(int value); // assigns new data to a node
		Node *getNext(); // returns next node
		Node *getPrev(); // returns previous node
		void setNext(Node *node); // sets next node
		void setPrev(Node *node); // sets previous node
};

#endif