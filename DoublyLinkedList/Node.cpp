#include "stdafx.h"
#include "Node.h"

Node::Node()
{
	data= 0;
	nextNode= nullptr;
	prevNode= nullptr;
}

Node::Node(int value)
{
	data= value;
	nextNode= nullptr;
	prevNode= nullptr;
}

Node::~Node()
{
}

int Node::getData()
{
	return data;
}

void Node::setData(int value)
{
	data= value;
}

Node * Node::getNext()
{
	return nextNode;
}

Node * Node::getPrev()
{
	return prevNode;
}

void Node::setNext(Node *next)
{
	nextNode= next;
}

void Node::setPrev(Node *prev)
{
	prevNode= prev;
}


