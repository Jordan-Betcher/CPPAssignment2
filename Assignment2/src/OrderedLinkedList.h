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
class OrderedLinkedList : public LinkedList<T>
{
	public:
		OrderedLinkedList();

		void insert(T&);
		void deleteNode(T&);
		T& search(T&);
		~OrderedLinkedList();
};

template<class T>
inline OrderedLinkedList<T>::OrderedLinkedList()
{
}

template<class T>
inline void OrderedLinkedList<T>::insert(T&)
{
}

template<class T>
inline void OrderedLinkedList<T>::deleteNode(T&)
{
}

template<class T>
inline T& OrderedLinkedList<T>::search(T&)
{
}

template<class T>
inline OrderedLinkedList<T>::~OrderedLinkedList()
{
}

#endif /* ORDEREDLINKEDLIST_H_ */
