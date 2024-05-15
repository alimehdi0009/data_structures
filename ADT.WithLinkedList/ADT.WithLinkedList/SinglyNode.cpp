
#ifndef _NODE_IMPLEMENTATION_

#define _NODE_IMPLEMENTATION_

#include "SinglyNode.h"

template<class T>
SinglyNode<T>::SinglyNode() :nextNode(nullptr)
{}

template<class T>
SinglyNode<T>::SinglyNode(const T& value) : itemValue(value), nextNode(nullptr)
{}

template<class T>
SinglyNode<T>::SinglyNode(const T& value, SinglyNode<T>* nextPtr) : itemValue(value), nextNode(nextPtr)
{}


template<class T>
T SinglyNode<T>::getItem() const
{
	return itemValue;
}

template<class T>
void SinglyNode<T>::setValue(const T& value)
{
	itemValue = value;
}

template<class T>
SinglyNode<T>* SinglyNode<T>::getNextNodePtr() const {
	return nextNode;
}

template<class T>
void SinglyNode<T> ::setNextNodePtr(SinglyNode<T>* nextPtr) {
	nextNode = nextPtr;
}
#endif // !_NODE_IMPLEMENTATION_
