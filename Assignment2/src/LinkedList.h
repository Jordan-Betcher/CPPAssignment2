/*
 * LinkedList.h
 *
 *  Created on: Oct 18, 2017
 *      Author: Betcher
 */

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
		LinkedList<T>& operator=(LinkedList<T>&);

		template<class U>
		friend ostream& operator<<(ostream&, LinkedList<U>&);

		~LinkedList();
};

#endif /* LINKEDLIST_H_ */
