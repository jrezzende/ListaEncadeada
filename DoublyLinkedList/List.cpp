#include "stdafx.h"
#include "List.h"
#include "Node.h"
#include <iostream>

List::List()
{
	head= nullptr;
	tail= nullptr; 
	listSize = 0;
}

List::List(int value)
{
	head= new Node(value);
	tail= head;
	listSize= 1;
}

List::~List()
{
}

Node * List::getHead()
{
	return head;
}

Node * List::getTail()
{
	return tail;
}

void List::prependNode(int value)
{
	Node *new_node= new Node(value);

	new_node->setPrev(nullptr);
	new_node->setNext(head);
	head->setPrev(new_node);
	head= new_node;
	listSize++;
}

void List::appendNode(int value)
{
	Node *new_node= new Node(value);

	if (head == nullptr)
	{
		head= new_node;
		head->setNext(tail);
		head->setPrev(nullptr);
		tail= new_node;
		tail->setNext(nullptr);
		tail->setPrev(head);
		listSize++;
	}
	else
	{
		new_node->setNext(nullptr);
		new_node->setPrev(tail);
		tail->setNext(new_node);
		tail= new_node;
		listSize++;
	}

}

Node * List::getPosition(int pos)
{
	if ((pos < 0) || (pos > listSize))
		return NULL;

	Node *node= head;
	for (int i= 1; i < pos; i++)
		node= node->getNext();

	return node;
}

void List::addInPosition(int value, int position)
{
	Node *new_node= new Node(value);
	Node* prev;
	Node* next;

	if (position <= 0) {
		prependNode(value);
		return;
	}

	else if (position >= listSize) {
		appendNode(value);
		return;
	}
	else 
		prev= getPosition(position-1);

	next= prev->getNext();

	
	prev->setNext(new_node);
	new_node->setPrev(prev);
	next->setPrev(new_node);
	new_node->setNext(next);

	listSize++;
}

void List::removeFirst()
{
	if (head)
	{
		Node *temp= head->getNext();
		delete head;
		head = temp;
		--listSize;
	}
	else
		std::cout << "The list is empty.\n";
}

void List::removeLast()
{
	if (tail)
	{
		Node *temp= tail->getPrev();
		delete tail;
		tail = temp;
		--listSize;
	}
	else
		std::cout << "The list is empty.\n";
}

void List::removeInPos(int pos)
{
	Node *temp = getPosition(pos);
	Node *prev;
	Node *next;

	prev= temp->getPrev();
	next= temp->getNext();
	delete temp;
	prev->setNext(next);
	next->setPrev(prev);

	listSize--;
}

void List::displayAsc()
{
	Node *node= head;

	if (listSize == 0)
		std::cout << "The list is empty";

	for (int i= 1; i < listSize; i++) 
	{
		std::cout << "In position: " << i << " the value is: " << node->getData() << std::endl;
		node= node->getNext();
	}

	std::cout << "In position: " << listSize << " the value is: " << node->getData() << std::endl;
}

void List::displayDesc()
{
	Node *node= tail;
	int listSize = getListSize();
	int i = listSize;


	if (listSize == 0)
		std::cout << "The list is empty";

	while (i > 0)
	{
		std::cout << "In position: " << node << " " << i-- << " the value is: " << node->getData() << "\n";
		node= node->getPrev();
	}
}

void List::sortList()
{
	Node *current= head;
	Node *next;

	while (current != nullptr)
	{
		for (next= current->getNext(); next != nullptr; next= next->getNext())
		{
			if (current->getData() > next->getData())
			{
				int tempData= current->getData();
				current->setData(next->getData());
				next->setData(tempData);
			}
		}
		current= current->getNext();
	}
}

void List::concatList(List *toConcat)
{
	tail->setNext(toConcat->getHead());
	toConcat->head->setPrev(tail);
	listSize+= toConcat->getListSize();
}

void List::deleteAllNodes()
{
	Node *temp= head;

	while (temp)
	{
		Node *tempNext= temp->getNext();
		delete temp;
		temp= tempNext;
	}
	listSize= 0;
	head= tail= nullptr;
}

int List::getListSize()
{
	return listSize;
}



