#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>

using namespace std;

template<class T>
struct node
{
		T data;
		node* pNext;
};

template<class T>
class LinkedList
{
	private:
		LinkedList(const LinkedList&) = delete; //copy constructor

	protected:
		int count;
		node<T> *pHead;
		node<T> *pLast;
	public:
		LinkedList();
		bool isEmpty();
		int getLength();
		T getFront();
		T getBack();
		void insertNode(T& itemToInsert);
		void deleteNode(T& itemToDelete);
		void destroyList();

		template<class U>
		friend ostream& operator<<(ostream& output, LinkedList<U>& list);

		~LinkedList();
};

template<class T>
LinkedList<T>::LinkedList()
{
	pHead = NULL;
	pLast = NULL;
	count = 0;
}

template<class T>
bool LinkedList<T>::isEmpty()
{
	return pHead == NULL;
}

template<class T>
int LinkedList<T>::getLength()
{
	return count;
}

template<class T>
T LinkedList<T>::getFront()
{
	return pHead->data;
}

template<class T>
T LinkedList<T>::getBack()
{
	return pLast->data;
}

template<class T>
void LinkedList<T>::insertNode(T& itemToInsert)
{
	node<T> *newNode = new node<T>;

	newNode->data = itemToInsert;
	newNode->pNext = NULL;

	if (pHead == NULL)
	{
		pHead = newNode;
		pLast = newNode;
	}
	else
	{
		pLast->pNext = newNode;
		pLast = newNode;
	}

	count++;
}

template<class T>
void LinkedList<T>::deleteNode(T& itemToDelete)
{
	if (pHead == NULL)
	{
		cerr << "empty list";
	}
	else
	{
		if (pHead->data == itemToDelete)
		{
			node<T>* headPointer = pHead;

			pHead = pHead->pNext;
			delete headPointer;

			count--;

			if (pHead == NULL)
			{
				pLast = NULL;
			}
		}
		else
		{
			node<T>* pointerBefore = pHead;
			node<T>* pointerToDelete = pointerBefore->pNext;

			while (pointerToDelete != NULL && pointerToDelete->data != itemToDelete)
			{
				pointerBefore = pointerToDelete;
				pointerToDelete = pointerToDelete->pNext;
			}

			if (pointerToDelete != NULL)
			{
				pointerBefore->pNext = pointerToDelete->pNext;

				count--;

				if (pLast == pointerToDelete)
				{
					pLast = pointerBefore;
				}

				delete pointerToDelete;
			}
		}
	}
}

template<class T>
void LinkedList<T>::destroyList()
{
	node<T> *headPointer;

	while (pHead != NULL)
	{
		headPointer = pHead;
		pHead = pHead->pNext;
		delete headPointer;
	}

	pLast = NULL;
	count = 0;
}

template<class T>
ostream& operator<<(ostream& output, LinkedList<T>& list)
{
	node<T> *headPointer = list.pHead;

	while (headPointer != NULL)
	{
		output << headPointer->data << " " << endl;
		headPointer = headPointer->pNext;
	}
	headPointer = NULL;
	return output;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	destroyList();
}

#endif /* LINKEDLIST_H_ */
