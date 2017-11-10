#include "stdafx.h"
#include "List.h"
#include <iostream>

List::List()
{
	head= nullptr;
	tail= nullptr; 
	listSize= 0;
	listName= "";
}

List::List(int value)
{
	head= new Node(value);
	tail= head;
	listSize= 1;
	listName= "";
}

List::~List()
{
}

List::Node * List::getHead()
{
	return head;
}

List::Node * List::getTail()
{
	return tail;
}

void List::prependNode(int value)
{
	Node *new_node= new Node(value);

	new_node->prevNode= nullptr;
	new_node->nextNode= nullptr;
	head->prevNode= new_node;
	head= new_node;
	listSize++;
}

void List::appendNode(int value)
{
	Node *new_node= new Node(value);

	if (head == nullptr)
	{
		head= new_node;
		head->nextNode= tail;
		head->prevNode= nullptr;
		tail= new_node;
		tail->nextNode= nullptr;
		tail->prevNode= head;
		listSize++;
	}
	else
	{
		new_node->nextNode= nullptr;
		new_node->prevNode= tail;
		tail->nextNode= new_node;
		tail= new_node;
		listSize++;
	}

}

List::Node * List::getPosition(int pos)
{
	if ((pos < 0) || (pos > listSize))
		return nullptr;

	Node *node= head;
	for (int i= 1; i < pos; i++)
		node= node->nextNode;

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

	next= prev->nextNode;

	
	prev->nextNode= new_node;
	new_node->prevNode= prev;
	next->prevNode= new_node;
	new_node->nextNode= next;

	listSize++;
}

void List::removeFirst()
{
	if (head)
	{
		Node *temp= head->nextNode;
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
		Node *temp= tail->prevNode;
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

	prev= temp->prevNode;
	next= temp->nextNode;
	delete temp;
	prev->nextNode= next;
	next->prevNode= prev;

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
		node= node->nextNode;
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
		std::cout << "In position: " << i-- << " the value is: " << node->getData() << "\n";
		node= node->prevNode;
	}
}

void List::sortList()
{
	Node *current= head;
	Node *next;

	while (current != nullptr)
	{
		for (next= current->nextNode; next != nullptr; next= next->nextNode)
		{
			if (current->getData() > next->getData())
			{
				int tempData= current->getData();
				current->setData(next->getData());
				next->setData(tempData);
			}
		}
		current= current->nextNode;
	}
}

void List::concatList(List *toConcat)
{
	tail->nextNode= toConcat->getHead();
	toConcat->head->prevNode= tail;
	listSize+= toConcat->getListSize();
}

void List::deleteAllNodes()
{
	Node *temp= head;

	while (temp)
	{
		Node *tempNext= temp->nextNode;
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

void List::setListName(std::string newName)
{
	listName= newName;
}



