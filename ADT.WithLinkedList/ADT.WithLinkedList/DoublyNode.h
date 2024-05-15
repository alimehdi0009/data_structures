#pragma once

#ifndef _DOUBLY_NODE_ABSTRACTION_

#define _DOUBLY_NODE_ABSTRACTION_

#include<vector>

template<class T>
class DoublyNode
{

private:
	DoublyNode<T>* previous;
	DoublyNode<T>* next;
	T data;
	int itemCount;

public:
	DoublyNode();
	DoublyNode(const T& data);
	DoublyNode(const T& data, DoublyNode<T>* previous, DoublyNode<T>* next);
	~DoublyNode();

	void setData(const T& data);
	void setPreviousPtr(DoublyNode<T>* previousNode);
	void setNextPtr(DoublyNode<T>* nextNode);

	T getData() const;
	DoublyNode<T>* getPreviousPtr() const;
	DoublyNode<T>* getNextPtr() const;
};


#include "DoublyNode.cpp"
#endif // !_DOUBLY_NODE_ABSTRACTION_

