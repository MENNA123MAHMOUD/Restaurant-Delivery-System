#pragma once

#include "Generic_DS/Node.h"
template < class T>
class LinkedBag {
private:
	Node<T>* headPtr; // Pointer to first node
	int itemCount; // Current count of bag items
	// Returns either a pointer to the node containing a given entry
	// or the null pointer if the entry is not in the bag.
	Node<T>* getPointerTo(const T& target) const;
public:
	LinkedBag();
	LinkedBag(const LinkedBag<T>& aBag); // Copy constructor
	virtual ~LinkedBag(); // Destructor should be virtual
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const T& newEntry);
	bool remove(const T& anEntry);
	void clear();
	bool contains(const T& anEntry) const;
	int getFrequencyOf(const T& anEntry) const;
	T* toArray()const;
	int size();

};
template < class T>
LinkedBag<T>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
} // end default constructor
template < class T>
bool LinkedBag<T>::add(const T& newEntry)
{
	// Add to beginning of chain: new node references rest of chain;
	// (headPtr is nullptr if chain is empty)
	Node<T>* newNodePtr = new Node<T>();
	newNodePtr->setItem(newEntry);
	newNodePtr->setNext(headPtr); // New node points to chain
	headPtr = newNodePtr; // New node is now first node
	itemCount++;
	return true;
} // end add
template < class T>
bool LinkedBag<T>::isEmpty() const
{
	return itemCount == 0;
} // end isEmpty
template < class T>
int LinkedBag<T>::getCurrentSize() const
{
	return itemCount;
} // end getCurrentSize
template < class T>
int LinkedBag<T>::getFrequencyOf(const T& anEntry) const
{
	int frequency = 0;
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		if (anEntry == curPtr->getItem())
		{
			frequency++;
		} // end if
		counter++;
		curPtr = curPtr->getNext();
	} // end while
	return frequency;
} // end getFrequencyOf
template < class T>
Node<T>* LinkedBag<T>::getPointerTo(const T& target) const
{
	bool found = false;
	Node<T>* curPtr = headPtr;
	while (!found && (curPtr != nullptr))
	{
		if (target == curPtr->getItem())
			found = true;
		else
			curPtr = curPtr->getNext();
	} // end while
	return curPtr;
} // end getPointerTo The definition of the method contains is straightforward :
template < class T>
bool LinkedBag<T>::contains(const T& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
} // end contains
template < class T>
bool LinkedBag<T>::remove(const T& anEntry)
{
	Node<T>* entryNodePtr = getPointerTo(anEntry);
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
	if (canRemoveItem)
	{
		// Copy data from first node to located node
		entryNodePtr->setItem(headPtr->getItem());
		// Delete first node
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();
		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		itemCount--;
	} // end if
	return canRemoveItem;
} // end remove
template < class T>
void LinkedBag<T>::clear() {
	Node<T>* nodeToDeletePtr;
	while (headPtr != nullptr)
	{
		 nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();
		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
	} // end while
	// headPtr is nullptr
	nodeToDeletePtr = nullptr;
	itemCount = 0;
} // end clear
template < class T>
LinkedBag<T>::LinkedBag(const LinkedBag<T>& aBag)
{
	itemCount = aBag->itemCount;
	Node<T>* origChainPtr = aBag->headPtr
		if (origChainPtr == nullptr)
			headPtr = nullptr; // Original bag is empty; so is copy
		else
		{
			// Copy first node
			headPtr = new Node;
			headPtr->setItem(origChainPtr->getItem());
			// Copy remaining nodes
			Node<T>* newChainPtr = headPtr; // Last-node pointer
			while (origPtr != nullptr)
			{
				origChainPtr = origChainPtr->getNext(); // Advance pointer
				// Get next item from original chain
				ItemType nextItem = origChainPtr->getItem();
				// Create a new node containing the next item
				Node<T>* newNodePtr = new Node<ItemType>(nextItem);
				// Link new node to end of new chain
				newChainPtr->setNext(newNodePtr);
				// Advance pointer to new last node
				newChainPtr = newChainPtr->getNext();
			} // end while
			newChainPtr->setNext(nullptr); // Flag end of new chain
		} // end if
} // end copy constructor
template < class T>
int LinkedBag<T>::size() {
	return itemCount;
}
template < class T>
LinkedBag<T>::~LinkedBag()
{
	clear();
} // end destructor
template < class T>
T * LinkedBag<T>::toArray() const
{
	T ** LBContents = new T[itemCount];
	Node<T>* curPtr = headptr;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		LBContents[counter] = &curPtr->getItem();
		curPtr = curPtr->getNext();
		counter++;
	}
	return LBContents;
}