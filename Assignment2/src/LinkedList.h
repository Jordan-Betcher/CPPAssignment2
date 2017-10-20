#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>

using namespace std;

template<class T>
struct node
{
		T data;
		node* next;
};

template<class T>
class LinkedList
{
	private:
		LinkedList(const LinkedList&) = delete; //copy constructor

	protected:
		int count;
		node<T> *head, *last;
	public:
		LinkedList();
		bool isEmpty();
		int length();
		T front();
		T back();
		void insertFirst(T&);
		void insertLast(T&);
		void deleteNode(T&);
		void destroyList();

		template<class U>
		friend ostream& operator<<(ostream&, LinkedList<U>&);

		~LinkedList();
};

template<class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	last = NULL;
	count = 0;
}

template<class T>
bool LinkedList<T>::isEmpty()
{
	return head == NULL;
}

template<class T>
int LinkedList<T>::length()
{
	return count;
}

template<class T>
T LinkedList<T>::front()
{
	return head->data;
}

template<class T>
T LinkedList<T>::back()
{
	return last->data;
}

template<class T>
void LinkedList<T>::insertFirst(T& item)
{
	node<T> *temp = new node<T>;

	temp->data = item;
	temp->next = head;
	head = temp;
	count++;

	if (last == NULL)
	{
		last = temp;
	}

}

template<class T>
void LinkedList<T>::insertLast(T& item)
{
	node<T> *newNode = new node<T>;

	newNode->data = item;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
		last = newNode;
	}
	else
	{
		last->next = newNode;
		last = newNode;
	}

	count++;
}

template<class T>
void LinkedList<T>::deleteNode(T& item)
{
	if (head == NULL)
	{
		cerr << "empty list";
	}
	else
	{
		if (head->data == item)
		{
			node<T>* headPointer = head;

			head = head->next;
			delete headPointer;

			count--;

			if (head == NULL)
			{
				last = NULL;
			}
		}
		else
		{
			node<T>* pointerBefore = head;
			node<T>* pointerToDelete = pointerBefore->next;

			while (pointerToDelete != NULL && pointerToDelete->data != item)
			{
				pointerBefore = pointerToDelete;
				pointerToDelete = pointerToDelete->next;
			}

			if (pointerToDelete != NULL)
			{
				pointerBefore->next = pointerToDelete->next;

				count--;

				if (last == pointerToDelete)
				{
					last = pointerBefore;
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

	while (head != NULL)
	{
		headPointer = head;
		head = head->next;
		delete headPointer;
	}

	last = NULL;
	count = 0;
}

template<class T>
ostream& operator<<(ostream& output, LinkedList<T>& list)
{
	node<T> *headPointer = list.head;

	while (headPointer != NULL)
	{
		output << headPointer->data << " " << endl;
		headPointer = headPointer->next;
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
