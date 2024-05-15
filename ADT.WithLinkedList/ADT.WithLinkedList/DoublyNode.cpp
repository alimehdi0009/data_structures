#ifndef _DOUBLY_NODE_IMPLEMENTATION_

#define _DOUBLY_NODE_IMPLEMENTATION_

#include "DoublyNode.h"

template<class T>
DoublyNode<T>::DoublyNode():next(nullptr),previous(nullptr)
{}

template<class T>
DoublyNode<T>::DoublyNode(const T& nodeData):data(nodeData),previous(nullptr),next(nullptr)
{}

template<class T>
DoublyNode<T>::DoublyNode(const T& nodeData,DoublyNode<T>* previousPtr,DoublyNode<T>* nextPtr):data(nodeData),previous(previousPtr),next(nextPtr)
{}

template<class T>
T DoublyNode<T>::getData() const
{
	return data;
}

template<class T>
void DoublyNode<T>::setData(const T& nodeData) 
{
	data = nodeData;
}

template<class T>
DoublyNode<T>* DoublyNode<T>::getPreviousPtr() const
{
	return previous;
}

template<class T>
void DoublyNode<T>::setPreviousPtr(DoublyNode<T>* previoudPtr) 
{
	previous = previoudPtr;
}

template<class T>
DoublyNode<T>* DoublyNode<T>::getNextPtr() const
{
	return next;
}

template<class T>
void DoublyNode<T>::setNextPtr(DoublyNode<T>* nextPtr)
{
	next = nextPtr;
}

template<class T>
DoublyNode<T>::~DoublyNode(){}


#endif // !_DOUBLY_NODE_IMPLEMENTATION_
