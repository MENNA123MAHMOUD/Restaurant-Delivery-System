#pragma once
#include"Generic_DS/Node.h"
template <typename T>
class priorityqueue
{
private:
	Node<T>* frontPtr;
	int size;
public:
	priorityqueue();
	bool isEmpty() const;
	bool add(const T& newEntry);
	bool pop(T& frntEntry);
	bool peek(T& frntEntry)  const;
	int getsize()const;
	bool compare(T a, T b);
	T* toArray() const;
	priorityqueue(const priorityqueue & src);
	priorityqueue<T> & operator=(priorityqueue<T> src);
	~priorityqueue();
};
template <typename T>
priorityqueue<T>::priorityqueue()
{
	size = 0;
	frontPtr = nullptr;
}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool priorityqueue<T>::isEmpty() const
{
	if (frontPtr == nullptr)
		return true;
	else
		return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:add
Adds newEntry to this queue with respect to its priority.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool priorityqueue<T>::add(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	Node<T>* cur = frontPtr;
	Node<T>* prev = frontPtr;

	if (isEmpty()) {
		frontPtr = newNodePtr; // The queue is empty
		size++;
		return true;
	}
	else
	{
		while (cur) {
			if (compare(frontPtr->getItem() , newEntry) ){
				newNodePtr->setNext(frontPtr);
				frontPtr = newNodePtr;
				size++;
				return true;
			}
		    else if (compare(cur->getItem(), newEntry)) {
				prev->setNext(newNodePtr);
				newNodePtr->setNext(cur);
				size++;
				return true;

			}
			else {
				 prev = cur;
				cur = cur->getNext();
			}
		}
	}
	prev->setNext(newNodePtr);
	newNodePtr->setNext(nullptr);
	size++;
	return true;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: remove
Removes the element with highest priority in the queue.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool priorityqueue<T>::pop(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	delete nodeToDeletePtr;
	size--;

	return true;

}

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peek
gets the front of this queue.that is the element with the highest priority
Input: None.
Output: The front of the queue.
return: flase if Queue is empty
*/
template <typename T>
bool priorityqueue<T>::peek(T& frntEntry) const
{
	if (isEmpty()) {
		frntEntry = NULL;
		return false;
	}
	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
priorityqueue<T>::~priorityqueue()
{
	T del;
	while (pop(del));
}
template <typename T>
int priorityqueue<T>::getsize()const {
	return size;
}
template<typename T>
inline bool priorityqueue<T>::compare(T a, T b)
{
	return (*a <= *b);
}
template < class T>
T * priorityqueue<T>::toArray() const
{
	T * pQContents = new T[size];
	Node<T>* curPtr = frontPtr;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < size))
	{
		pQContents[counter] = curPtr->getItem();
		curPtr = curPtr->getNext();
		counter++;
	}
	return pQContents;
}
template < class T>
priorityqueue<T>::priorityqueue(const priorityqueue & src)
{
	Node<T>* node = src.front;
	while (node != nullptr)
	{
		enqueue(node->getItem());
		node = node->getNext();
	}
}
template < class T>
priorityqueue<T> & priorityqueue<T>::operator=(priorityqueue<T> src)
{
	Node<T>* node = src.front;
	while (node != nullptr)
	{
		enqueue(node->getItem());
		node = node->getNext();
	}
	return *this;
}