//============================================================================
// Name        : OrderedLinkedList.h
// Author      : Jordan Betcher
// Date	       : 10/23/2017
// Description : OrderedLinkedList a LinkedList that inserts based on comparative operators
//============================================================================

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_

#include "LinkedList.h"

template<class T>
class OrderedLinkedList: public LinkedList<T>
{
	public:
		OrderedLinkedList();
		void insertNode(T& itemToInsert);
		void deleteNode(T& itemToDelete);
		bool hasNode(T& itemToFind);
		T& searchForNode(T& itemToFind);
		~OrderedLinkedList();

};

//Creates an OrderedLinkedList
template<class T>
OrderedLinkedList<T>::OrderedLinkedList()
{
	this->pFirstNode = NULL;
	this->pLastNode = NULL;
	this->count = 0;
}

//Deletes a Node in OrderedLinkedList
template<class T>
void OrderedLinkedList<T>::deleteNode(T& itemToDelete)
{
	this->deleteNode(itemToDelete);
}

//Inserts a Node into OrderedLinkedList in the proper order by comparison
template<class T>
void OrderedLinkedList<T>::insertNode(T& itemToInsert)
{
	node<T> *newNode = new node<T>;

	newNode->data = itemToInsert;
	newNode->pNextNode = NULL;

	if (this->pFirstNode == NULL)
	{
		this->pFirstNode = newNode;
		this->pLastNode = newNode;
	}
	else
	{

		if (this->pFirstNode->data > itemToInsert)
		{
			node<T>* nextNode = this->pFirstNode;
			this->pFirstNode = newNode;
			this->pFirstNode->pNextNode = nextNode;
		}
		else
		{
			node<T>* pointerBefore = this->pFirstNode;
			node<T>* pointerToFind = pointerBefore->pNextNode;

			while (pointerToFind != NULL
					&& pointerToFind->data < itemToInsert)
			{
				pointerBefore = pointerToFind;
				pointerToFind = pointerToFind->pNextNode;
			}

			if (pointerToFind != NULL)
			{
				pointerBefore->pNextNode = newNode;
				newNode->pNextNode = pointerToFind;
				delete pointerToFind;

			}
			else
			{
				this->pLastNode->pNextNode = newNode;
				this->pLastNode = newNode;
			}
		}
	}

	this->count++;
}

//Searches if OrderedLinkedList contains a node with the itemToFind
template<class T>
bool OrderedLinkedList<T>::hasNode(T& itemToFind)
{
	if (this->pFirstNode == NULL)
	{

	}
	else
	{
		if (this->pFirstNode->data == itemToFind)
		{
			return true;
		}
		else
		{
			node<T>* pointerBefore = this->pFirstNode;
			node<T>* pointerToFind = pointerBefore->pNextNode;

			while (pointerToFind != NULL && pointerToFind->data != itemToFind)
			{
				pointerBefore = pointerToFind;
				pointerToFind = pointerToFind->pNextNode;
			}

			if (pointerToFind != NULL)
			{
				T found = pointerToFind->data;
				delete pointerToFind;
				return true;

			}
		}
	}

	return false;
}

//Searches for the itemToFind
template<class T>
inline T& OrderedLinkedList<T>::searchForNode(T& itemToFind)
{
	if (this->pFirstNode == NULL)
	{

	}
	else
	{
		if (this->pFirstNode->data == itemToFind)
		{
			return this->pFirstNode->data;
		}
		else
		{
			node<T>* pointerBefore = this->pFirstNode;
			node<T>* pointerToFind = pointerBefore->pNextNode;

			while (pointerToFind != NULL && pointerToFind->data != itemToFind)
			{
				pointerBefore = pointerToFind;
				pointerToFind = pointerToFind->pNextNode;
			}

			if (pointerToFind != NULL)
			{
				T& found = pointerToFind->data;
				delete pointerToFind;
				return found;

			}
		}
	}

	throw exception();
}

template<class T>
OrderedLinkedList<T>::~OrderedLinkedList()
{
	this->destroyList();
}

#endif /* ORDEREDLINKEDLIST_H_ */
