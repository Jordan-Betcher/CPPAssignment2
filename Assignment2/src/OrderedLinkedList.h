/*
 * OrderedLinkedList.h
 *
 *  Created on: Oct 18, 2017
 *      Author: Betcher
 */

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

template<class T>
OrderedLinkedList<T>::OrderedLinkedList()
{
	this->pHead = NULL;
	this->pLast = NULL;
	this->count = 0;
}

template<class T>
void OrderedLinkedList<T>::deleteNode(T& itemToDelete)
{
	this->deleteNode(itemToDelete);
}

template<class T>
void OrderedLinkedList<T>::insertNode(T& itemToInsert)
{
	node<T> *newNode = new node<T>;

	newNode->data = itemToInsert;
	newNode->pNext = NULL;

	if (this->pHead == NULL)
	{
		this->pHead = newNode;
		this->pLast = newNode;
	}
	else
	{

		if (this->pHead->data > itemToInsert)
		{
			node<T>* nextNode = this->pHead;
			this->pHead = newNode;
			this->pHead->pNext = nextNode;
		}
		else
		{
			node<T>* pointerBefore = this->pHead;
			node<T>* pointerToFind = pointerBefore->pNext;

			while (pointerToFind != NULL
					&& pointerToFind->data < itemToInsert)
			{
				pointerBefore = pointerToFind;
				pointerToFind = pointerToFind->pNext;
			}

			if (pointerToFind != NULL)
			{
				pointerBefore->pNext = newNode;
				newNode->pNext = pointerToFind;
				delete pointerToFind;

			}
			else
			{
				this->pLast->pNext = newNode;
				this->pLast = newNode;
			}
		}
	}

	this->count++;
}
template<class T>
bool OrderedLinkedList<T>::hasNode(T& itemToFind)
{
	if (this->pHead == NULL)
	{

	}
	else
	{
		if (this->pHead->data == itemToFind)
		{
			return true;
		}
		else
		{
			node<T>* pointerBefore = this->pHead;
			node<T>* pointerToFind = pointerBefore->pNext;

			while (pointerToFind != NULL && pointerToFind->data != itemToFind)
			{
				pointerBefore = pointerToFind;
				pointerToFind = pointerToFind->pNext;
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

template<class T>
inline T& OrderedLinkedList<T>::searchForNode(T& itemToFind)
{
	if (this->pHead == NULL)
	{

	}
	else
	{
		if (this->pHead->data == itemToFind)
		{
			return this->pHead->data;
		}
		else
		{
			node<T>* pointerBefore = this->pHead;
			node<T>* pointerToFind = pointerBefore->pNext;

			while (pointerToFind != NULL && pointerToFind->data != itemToFind)
			{
				pointerBefore = pointerToFind;
				pointerToFind = pointerToFind->pNext;
			}

			if (pointerToFind != NULL)
			{
				T found = pointerToFind->data;
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
