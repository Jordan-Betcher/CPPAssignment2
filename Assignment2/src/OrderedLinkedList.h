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
		void insert(T&);
		void deleteNode(T&);
		bool has(T&);
		T& search(T&);
		~OrderedLinkedList();

};

template<class T>
OrderedLinkedList<T>::OrderedLinkedList()
{
	this->head = NULL;
	this->last = NULL;
	this->count = 0;
}

template<class T>
void OrderedLinkedList<T>::deleteNode(T& itemToDelete)
{
	this->deleteNode(itemToDelete);
}

template<class T>
void OrderedLinkedList<T>::insert(T& itemToInsert)
{
	node<T> *newNode = new node<T>;

	newNode->data = itemToInsert;
	newNode->next = NULL;

	if (this->head == NULL)
	{
		this->head = newNode;
		this->last = newNode;
	}
	else
	{

		if (this->head->data > itemToInsert)
		{
			node<T>* nextNode = this->head;
			this->head = newNode;
			this->head->next = nextNode;
		}
		else
		{
			node<T>* pointerBefore = this->head;
			node<T>* pointerToFind = pointerBefore->next;

			while (pointerToFind != NULL
					&& pointerToFind->data < itemToInsert)
			{
				pointerBefore = pointerToFind;
				pointerToFind = pointerToFind->next;
			}

			if (pointerToFind != NULL)
			{
				pointerBefore->next = newNode;
				newNode->next = pointerToFind;
				delete pointerToFind;

			}
			else
			{
				this->last->next = newNode;
				this->last = newNode;
			}
		}
	}

	this->count++;
}
template<class T>
bool OrderedLinkedList<T>::has(T& itemToFind)
{
	if (this->head == NULL)
	{

	}
	else
	{
		if (this->head->data == itemToFind)
		{
			return true;
		}
		else
		{
			node<T>* pointerBefore = this->head;
			node<T>* pointerToFind = pointerBefore->next;

			while (pointerToFind != NULL && pointerToFind->data != itemToFind)
			{
				pointerBefore = pointerToFind;
				pointerToFind = pointerToFind->next;
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
inline T& OrderedLinkedList<T>::search(T& itemToFind)
{
	if (this->head == NULL)
	{

	}
	else
	{
		if (this->head->data == itemToFind)
		{
			return this->head->data;
		}
		else
		{
			node<T>* pointerBefore = this->head;
			node<T>* pointerToFind = pointerBefore->next;

			while (pointerToFind != NULL && pointerToFind->data != itemToFind)
			{
				pointerBefore = pointerToFind;
				pointerToFind = pointerToFind->next;
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
