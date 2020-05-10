#pragma once
#include "Generic_DS\Node.h"
template<class T>
class LinkedList
{
private:
		//Pointer to the head of the list
		
	int count;	//Number of nodes in the list
public:
	Node<T> *Head;
	LinkedList();
	~LinkedList();
	void PrintList();	//prints all items in the list
	void InsertBeg(T data);	//inserts a new node at list head
	void DeleteAll();	//Deletes all nodes in the list
	bool isempty();
	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(T data);	

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	T Find(int Key) const;

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(T value);

	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst(T&f);
	
	
	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast();

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(T value);	

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(T value);	

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	void Merge(LinkedList& L);
	int size();

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	void Reverse();
	T* toArray() const;
	LinkedList(const LinkedList & src);
	LinkedList<T> & operator=(LinkedList<T> src);
};


template<class T>
LinkedList<T>::LinkedList()
{
	count = 0;
	Head = nullptr;
}

//List is being desturcted ==> delete all items in the list
template<class T>
LinkedList<T>::~LinkedList()
{
	DeleteAll();
}
////////////////////////////////////////////////////////////////////////
/*
* Function: PrintList.
* prints the values of all nodes in a linked list.
*/
template<class T>
void LinkedList<T>::PrintList()
{
	Node<T> *p = Head;
	
	while(p != NULL)
	{
		cout << "[ " << p->getItem() << " ]";
		cout << "--->";
		p = p->getNext();
	}
	cout << "*\n";
}
template<class T>
bool LinkedList<T>::isempty()
{
	return(count == 0);
}
template<class T>
void LinkedList<T>::DeleteFirst(T& f) {
	if (Head == NULL)return;
	f = Head->getItem();
	Node<T>*tmp = Head;
	Head = Head->getNext();
	delete tmp;
	count--;
}
////////////////////////////////////////////////////////////////////////
/*
* Function: InsertBeg.
* Creates a new node and adds it to the beginning of a linked list.
* 
* Parameters:
*	- data : The value to be stored in the new node.
*/
template<class T>
void LinkedList<T>::InsertBeg(T data)
{
	Node<T> *R = new Node<T>(data);
	R->setNext(Head);
	Head = R;
	count++;

}
////////////////////////////////////////////////////////////////////////
/*
* Function: DeleteAll.
* Deletes all nodes of the list.
*/
template<class T>
void LinkedList<T>::DeleteAll()
{
	Node<T> *P = Head;
	while (Head != nullptr)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
	count = 0;
}
template<class T>
void LinkedList<T>::InsertEnd(T data){
	Node<T>*tmp=Head;
	Node<T>* node=new Node<T>();
	node->setItem(data);
	while(tmp&&tmp->getNext()!=nullptr){
		tmp=tmp->getNext();
	}
	if (tmp == nullptr) { Head = node; node->setNext(nullptr); }
	else {
		tmp->setNext(node);
		node->setNext(nullptr);
	}
	count++;
}
template<class T>
bool LinkedList<T>::DeleteNode(T value){

	Node<T>*tmp=Head;
	Node<T>*tmp2=Head->getNext();
	bool found=true;
	if(!tmp)return false;
	if(tmp->getItem()==value){Head=tmp->getNext(); delete tmp; tmp=nullptr; count--; return true; }
	while(tmp&&tmp2&&found){
		if(tmp2->getItem()==value) found=false;
		else{tmp=tmp->getNext(); tmp2=tmp2->getNext();}
	}
	if(!found){
	tmp->setNext(tmp2->getNext());
	delete tmp2;
	tmp2 = nullptr;
	count--;
	return true;
	}
	else{return false;}
}
template<class T>
void LinkedList<T>::Merge(LinkedList<T> &L){
	if(Head==NULL)return;
	if(L.Head==NULL)return;
	Node<T>*tmp=Head;

	while(tmp->getNext()){
		tmp=tmp->getNext();
	}
	tmp->setNext(L.Head);
	
	count+=L.count;
}
template < class T>
int LinkedList<T>::size() {
	return count;
}
template<class T>
T LinkedList<T>::Find(int id) const{
	
	Node<T>*tmp = Head;
	int count = 0;
	if (!tmp)
		return nullptr;
	while (tmp)
	{
		if (count == id)
			return tmp->getItem();
		else {
			tmp = tmp->getNext();
			count++;
		}

	}
	return nullptr;
}

template < class T>
 T * LinkedList<T>::toArray() const
{
	T * bagContents = new T[count];
	Node<T>* curPtr = Head;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < count))
	{
		bagContents[counter] = curPtr->getItem();
		curPtr = curPtr->getNext();
		counter++;
	} 
	return bagContents;
}
 template < class T>
 LinkedList<T>::LinkedList(const LinkedList & src)
 {
	 Node<T>* node = src.Head;
	 while (node != nullptr)
	 {
		 InsertEnd(node->getItem());
		 node = node->getNext();
	 }
 }
 template < class T>
 LinkedList<T> & LinkedList<T>::operator=(LinkedList<T> src)
 {
	 Node<T>* node = src.Head;
	 while (node != nullptr)
	 {
		 InsertEnd(node->getItem());
		 node = node->getNext();
	 }
	 return *this;
 }