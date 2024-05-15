#pragma once

#ifndef _SINGLY_NODE_ABSTRACTION_

#define _SINGLY_NODE_ABSTRACTION_

template<class T>
class SinglyNode
{

private:
	T itemValue;
	SinglyNode<T>* nextNode;

public:
	SinglyNode();
	SinglyNode(const T& itemValue);
	SinglyNode(const T& itemValue, SinglyNode<T>* nextNodePtr);
	void setValue(const T& itemValue);
	void setNextNodePtr(SinglyNode<T>* nextNodePtr);
	T getItem() const;
	SinglyNode<T>* getNextNodePtr() const;
};

#include "SinglyNode.cpp"
#endif // !_SINGLY_NODE_ABSTRACTION_
