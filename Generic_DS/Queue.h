#ifndef __QUEUE_H_
#define __QUEUE_H_
#pragma once
/*This code is an updated version from "Data Abstraction & Problem Solving with C++,WALLS AND MIRRORS ,SIXTH EDITION"*/

/*
This is a program that implements the queue abstract data type using a linked list.
The queue is implemented as a chain of linked nodes that has two pointers, 
a frontPtr pointer for the front of the queue and a backPtr pointer for the back of the queue.
*/

/*

				The Node: item of type T and a "next" pointer
					------------- 
					| item| next | --->
					-------------
General Queue case:

                 frontPtr																backPtr
					\											   						/		
					 \											  					   /		
					------------- 	  ------------- 	  ------------- 	  ------------- 	  	  
					| item| next |--->| item| next |--->  | item| next |--->  | item| next |---> NULL
					------------- 	  ------------- 	  ------------- 	  -------------	  
		
Empty Case:

                 frontptr	 backptr
						\	 /				
						 \	/				
					---- NULL ------


Single Node Case:
                 frontPtr	 backPtr
					\		/	
					 \	   /			
					-------- 	
					|	|nxt -->NULL
					--------	

*/

#include "Node.h"

template <typename T>
class Queue
{
private :
	
	Node<T>* backPtr;
	Node<T>* frontPtr;
	int count;
public :
	Queue();	
	bool isEmpty() const ;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);  
	int size();
	bool peekFront(T& frntEntry)  const;	
	bool peekBack(T& backEntry)   const;
	T* toArray() const;
	Queue(const Queue & src);
	Queue<T> & operator=(Queue<T> src);
	~Queue();
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
Queue<T>::Queue()
{
	count=0;
	backPtr=nullptr;
	frontPtr=nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool Queue<T>::isEmpty() const
{
	if(frontPtr==nullptr)
		return true;
	else
		return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool Queue<T>::enqueue( const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty
	backPtr = newNodePtr; // New node is at back
	count++;
	return true ;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool Queue<T>:: dequeue(T& frntEntry)  
{
	if(isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: one node in queue
		backPtr = nullptr ;	
		
	// Free memory reserved by the dequeued node
	delete nodeToDeletePtr;
	count--;

	return true;

}

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peekFront
gets the front of this queue. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
return: flase if Queue is empty
*/
template <typename T>
bool Queue<T>:: peekFront(T& frntEntry) const 
{
	if(isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
template <typename T>
bool Queue<T>::peekBack(T& backEntry) const
{
	if (isEmpty())
		return false;

	backEntry = backPtr->getItem();
	return true;

}
template < class T>
T * Queue<T>::toArray() const
{
	T * QContents = new T[count];
	Node<T>* curPtr = frontPtr;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < count))
	{
		QContents[counter] = curPtr->getItem();
		curPtr = curPtr->getNext();
		counter++;
	}
	return QContents;
}
///////////////////////////////////////////////////////////////////////////////////
template <typename T>
int Queue<T>::size() {
	return count;
}
template <typename T>
Queue<T>::~Queue()
{
	T del;
	while (count >= 0) {
		dequeue(del);
		count--;
	}
}
template < class T>
Queue<T>::Queue(const Queue & src)
{
	Node<T>* node = src.frontPtr;
	while (node != nullptr)
	{
		enqueue(node->getItem());
		node = node->getNext();
	}
}
template < class T>
Queue<T> & Queue<T>::operator=(Queue<T> src)
{
	Node<T>* node = src.frontPtr;
	while (node != nullptr)
	{
		enqueue(node->getItem());
		node = node->getNext();
	}
	return *this;
}
#endif