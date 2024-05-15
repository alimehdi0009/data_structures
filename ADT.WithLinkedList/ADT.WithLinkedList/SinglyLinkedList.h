#pragma once
#pragma once

#ifndef _SINGLY_LINKED_LIST_ABSTRACTION_

#define _SINGLY_LINKED_LIST_ABSTRACTION_

#include "SinglyNode.h"
#include <vector>

template<class T>
class SinglyLinkedList
{

private:
	SinglyNode<T>* head;
	int itemCount;

	SinglyNode<T>* getPointerTo(SinglyNode<T>* nodePtr, const T& targetItem) const;
	bool deleteNode(SinglyNode<T>* targetItem);
	int getFrequencyOf(SinglyNode<T>* nodePtr, const T& targetNode) const;
	SinglyNode<T>* clone(const SinglyNode<T>* targetNode);
public:
	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList<T>& linkedList);
	SinglyLinkedList(const T itemsArray[]);
	virtual ~SinglyLinkedList();

	int getCurrentSize() const;
	int getItemsCount(bool useRecursive = false) const;
	int getCurrentSizeIterative() const;
	int getCurrentSizeRecursive(SinglyNode<T>* nodePtr) const;
	bool isEmpty() const;
	bool addStart(const T& itemValue);
	bool addEnd(const T& itemValue);
	bool removeStart();
	bool removeEnd();
	bool removeRandom(const T& itemValue);
	void clear();
	int getCountOf(const T& targetNode) const;
	bool contains(const T& aNode) const;
	void traverse() const;
	std::vector<T>* toVector(const bool useRecursion = false) const;
	std::vector<T>* toVectorUseIteration() const;
	std::vector<T>* toVectorUseRecursion(std::vector<T>* vectorContainer, SinglyNode<T>* nodePtr) const;

};

#include "SinglyLinkedList.cpp"
#endif // !_SINGLY_LINKED_LIST_ABSTRACTION_

