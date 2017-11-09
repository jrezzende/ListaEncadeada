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
		Node();
		Node(int value);
		~Node();

		int getData();
		void setData(int value);
		Node *getNext();
		Node *getPrev();
		void setNext(Node *node);
		void setPrev(Node *node);
};

#endif