#pragma once

#ifndef _DOUBLY_LINKED_LIST_ABSTRACTION_

#define _DOUBLY_LINKED_LIST_ABSTRACTION_

#include "DoublyNode.h"

template<class T>
class DoublyLinkedList
{
private:
	DoublyNode<T>* head;
	DoublyNode<T>* tail;
	int itemsCount;

	bool isEmpty() const;

	bool deleteNode(DoublyNode<T>* targetNode);

	bool deleteMiddleNode(DoublyNode<T>* targetNode);

	bool removeRandomIterative(const T& targetNode);
	bool removeRandomRecursive(DoublyNode<T>* nodePtr, const T& targetNode);

	int getFrequencyOfIterative(const T& targetValue) const;
	int getFrequencyOfRecursive(DoublyNode<T>* nodePtr, const T& targetValue) const;

	int getCurrentSizeIterative() const;
	int getCurrentSizeRecursive(DoublyNode<T>* nodePtr) const;

	std::vector<T>* toVectorUseIteration() const;
	std::vector<T>* toVectorUseRecursion(std::vector<T>* vectorContainer, DoublyNode<T>* nodePtr) const;

	void traverseForwardIterative() const;
	void traverseForwardRecursive(DoublyNode<T>* nodePtr) const;

	void traverseBackwardIterative() const;
	void traverseBackwardRecursive(DoublyNode<T>* nodePtr) const;

	void clearIteratively();
	void clearRecursively(DoublyNode<T>* nodePtr);

public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList<T>& doublyLinkedList);
	DoublyLinkedList(const T dataArray[]);
	~DoublyLinkedList();

	bool addStart(const T& data);
	bool addEnd(const T& data);

	bool removeStart();

	bool removeEnd();

	bool removeRandom(const T& targetValue, bool recursively=false);

	int getFrequencyOf(const T& targetValue, bool recursively = false) const;

	int getCurrentSize() const;

	int getItemsCount(bool useRecursive = false) const;

	std::vector<T>* toVector(const bool useRecursion = false) const;

	void traverse(bool backward=false,bool recursively = false) const;

	void clear(const bool recursively = false);

};

#include "DoublyLinkedList.cpp"
#endif // !_DOUBLY_LINKED_LIST_ABSTRACTION_

