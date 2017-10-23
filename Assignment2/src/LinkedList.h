//============================================================================
// Name        : LinkedList.h
// Author      : Jordan Betcher
// Date	       : 10/23/2017
// Description : LinkedList, modified version of Fatma Serce LinkedList
//============================================================================

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>

using namespace std;

template<class T>
struct node
{
		T data;
		node* pNextNode;
};

template<class T>
class LinkedList
{
	private:
		LinkedList(const LinkedList&) = delete; //copy constructor

	protected:
		int count;
		node<T> *pFirstNode;
		node<T> *pLastNode;
	public:
		LinkedList();
		bool isEmpty();
		int getLength();
		T getFirstNode();
		T getLastNode();
		void insertNode(T& itemToInsert);
		void deleteNode(T& itemToDelete);
		void destroyList();

		template<class U>
		friend ostream& operator<<(ostream& output, LinkedList<U>& list);

		~LinkedList();
};

//Creates a LinkedList
template<class T>
LinkedList<T>::LinkedList()
{
	pFirstNode = NULL;
	pLastNode = NULL;
	count = 0;
}

//Tells you if the LinkedList is Empty
template<class T>
bool LinkedList<T>::isEmpty()
{
	return pFirstNode == NULL;
}

//Gets the Length of LinkedList
template<class T>
int LinkedList<T>::getLength()
{
	return count;
}

//Gets the first Node in LinkedList
template<class T>
T LinkedList<T>::getFirstNode()
{
	return pFirstNode->data;
}

//Gets the last Node in LinkedList
template<class T>
T LinkedList<T>::getLastNode()
{
	return pLastNode->data;
}

//Inserts a Node into LinkedList
template<class T>
void LinkedList<T>::insertNode(T& itemToInsert)
{
	node<T> *newNode = new node<T>;

	newNode->data = itemToInsert;
	newNode->pNextNode = NULL;

	if (pFirstNode == NULL)
	{
		pFirstNode = newNode;
		pLastNode = newNode;
	}
	else
	{
		pLastNode->pNextNode = newNode;
		pLastNode = newNode;
	}

	count++;
}

//Deletes a Node in LinkedList
template<class T>
void LinkedList<T>::deleteNode(T& itemToDelete)
{
	if (pFirstNode == NULL)
	{
		cerr << "empty list";
	}
	else
	{
		if (pFirstNode->data == itemToDelete)
		{
			node<T>* headPointer = pFirstNode;

			pFirstNode = pFirstNode->pNextNode;
			delete headPointer;

			count--;

			if (pFirstNode == NULL)
			{
				pLastNode = NULL;
			}
		}
		else
		{
			node<T>* pointerBefore = pFirstNode;
			node<T>* pointerToDelete = pointerBefore->pNextNode;

			while (pointerToDelete != NULL && pointerToDelete->data != itemToDelete)
			{
				pointerBefore = pointerToDelete;
				pointerToDelete = pointerToDelete->pNextNode;
			}

			if (pointerToDelete != NULL)
			{
				pointerBefore->pNextNode = pointerToDelete->pNextNode;

				count--;

				if (pLastNode == pointerToDelete)
				{
					pLastNode = pointerBefore;
				}

				delete pointerToDelete;
			}
		}
	}
}

//Destroys the LinkedList
template<class T>
void LinkedList<T>::destroyList()
{
	node<T> *headPointer;

	while (pFirstNode != NULL)
	{
		headPointer = pFirstNode;
		pFirstNode = pFirstNode->pNextNode;
		delete headPointer;
	}

	pLastNode = NULL;
	count = 0;
}

//Prints out LinkedList
template<class T>
ostream& operator<<(ostream& output, LinkedList<T>& list)
{
	node<T> *headPointer = list.pFirstNode;

	while (headPointer != NULL)
	{
		output << headPointer->data << " " << endl;
		headPointer = headPointer->pNextNode;
	}
	headPointer = NULL;
	return output;
}
//Deletes Linked List
template<class T>
LinkedList<T>::~LinkedList()
{
	destroyList();
}

#endif /* LINKEDLIST_H_ */
