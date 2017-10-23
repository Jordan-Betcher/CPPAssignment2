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
		this->last->next = newNode;
		this->last = newNode;
	}

	this->count++;
}

template<class T>
inline T& OrderedLinkedList<T>::search(T& itemToFind)
{
	if (head == NULL)
	{

	}
	else
	{
		if (head->data == itemToFind)
		{
			return head->data;
		}
		else
		{
			node<T>* pointerBefore = head;
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
