
#ifndef _LINKEDLIST_IMPLEMENTATION_

#define _LINKEDLIST_IMPLEMENTATION_

#include "SinglyLinkedList.h"
#include<iostream>

template<class T>
SinglyLinkedList<T>::SinglyLinkedList() :itemCount(0), head(nullptr)
{}

template<class T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& linkedList)
{
	if (!linkedList->isEmpty())
	{
		SinglyNode<T>* temp = linkedList->head;

		while (temp->getNextNodePtr() != nullptr)
		{
			addEnd(temp->getItem());

			temp = temp->getNextNodePtr();
		}

		addEnd(temp->getItem());

		temp = nullptr;
	}
}

template<class T>
SinglyLinkedList<T>::SinglyLinkedList(const T itemsArray[])
{
	int counter = 0;
	int arraySize = sizeof(itemsArray);

	while (counter < arraySize)
	{
		addEnd(itemsArray[counter]);

		counter++;
	}
}

template<class T>
bool SinglyLinkedList<T>::addStart(const T& item)
{
	SinglyNode<T>* newNode = new SinglyNode<T>(item, nullptr);

	if (isEmpty())
	{
		head = newNode;
	}
	else
	{
		newNode->setNextNodePtr(head);
		head = newNode;
	}

	itemCount++;
	newNode = nullptr;

	return true;
}

template<class T>
bool SinglyLinkedList<T>::addEnd(const T& item)
{
	SinglyNode<T>* newNode = new SinglyNode<T>(item, nullptr);

	if (isEmpty())
	{
		head = newNode;
	}
	else
	{
		SinglyNode<T>* temp = head;

		while (temp->getNextNodePtr() != nullptr)
			temp = temp->getNextNodePtr();

		temp->setNextNodePtr(newNode);

		temp = nullptr;
	}

	itemCount++;
	newNode = nullptr;
	return true;
}

template<class T>
bool SinglyLinkedList<T>::isEmpty() const
{
	return itemCount == 0 || head == nullptr;
}

template<class T>
int SinglyLinkedList<T>::getCurrentSize() const
{
	return itemCount;
}

template<class T>
int SinglyLinkedList<T>::getItemsCount(bool useRecursive) const
{
	if (useRecursive)
		return getCurrentSizeRecursive(head);
	else
		return getCurrentSizeIterative();
}

template<class T>
int SinglyLinkedList<T>::getCurrentSizeIterative() const
{
	if (isEmpty())
		return 0;

	SinglyNode<T>* temp = head;

	int counter = 0;

	while (temp != nullptr)
	{
		counter++;
		temp = temp->getNextNodePtr();
	}

	return counter;
}

template<class T>
int SinglyLinkedList<T>::getCurrentSizeRecursive(SinglyNode<T>* nodePtr) const
{
	if (nodePtr == nullptr)
		return 0;

	return 1 + getCurrentSizeRecursive(nodePtr->getNextNodePtr());
}


template<class T>
bool SinglyLinkedList<T>::removeStart()
{
	if (isEmpty())
		return false;
	else
	{
		SinglyNode<T>* temp = head;

		head = head->getNextNodePtr();

		deleteNode(temp);

		temp = nullptr;
	}
	return true;
}

template<class T>
bool SinglyLinkedList<T>::removeEnd()
{
	if (isEmpty())
		return false;
	else
	{
		SinglyNode<T>* temp = head;

		SinglyNode<T>* previousNode = temp;
		while (temp->getNextNodePtr() != nullptr)
		{
			previousNode = temp;
			temp = temp->getNextNodePtr();
		}

		previousNode->setNextNodePtr(nullptr);

		if (itemCount == 1)
			head = previousNode;

		deleteNode(temp);

		temp = nullptr;
		previousNode = nullptr;
	}
	return true;
}

template<class T>
bool SinglyLinkedList<T>::removeRandom(const T& item)
{
	if (isEmpty())
		return false;
	else
	{
		SinglyNode<T>* temp = head;
		SinglyNode<T>* previousNode = head;

		bool isFound = false;

		while (temp->getNextNodePtr() != nullptr)
		{
			if (temp->getItem() == item)
			{
				isFound = true;
				break;
			}
			previousNode = head;
			temp = temp->getNextNodePtr();
		}

		bool isNodeFound = isFound || temp->getItem() == item;

		if (isNodeFound)
		{
			deleteNode(temp);
			previousNode->setNextNodePtr(nullptr);

			temp = nullptr;
		}

		return isNodeFound;
	}

	return false;
}

template<class T>
void SinglyLinkedList<T>::clear()
{
	if (isEmpty())
		return;
	else
	{
		SinglyNode<T>* previousTemp = head;
		SinglyNode<T>* nextTemp = previousTemp;

		while (nextTemp != nullptr)
		{
			previousTemp = nextTemp;
			nextTemp = previousTemp->getNextNodePtr();

			delete previousTemp;
			itemCount--;
		}

		delete previousTemp;
		itemCount--;

		previousTemp = nullptr;
		nextTemp = nullptr;
	}
}

template<class T>
bool SinglyLinkedList<T>::deleteNode(SinglyNode<T>* targetNode)
{
	if (isEmpty() || targetNode == nullptr)
		return false;

	delete targetNode;
	itemCount--;

	return true;
}

template<class T>
int SinglyLinkedList<T>::getFrequencyOf(SinglyNode<T>* nodePtr, const T& targetItem) const
{
	if (isEmpty() || nodePtr == nullptr)
		return 0;

	else if (nodePtr->getItem() == targetItem)
		return 1 + getFrequencyOf(nodePtr->getNextNodePtr(), targetItem);

	else
		return getFrequencyOf(nodePtr->getNextNodePtr(), targetItem);
}

template<class T>
int SinglyLinkedList<T>::getCountOf(const T& targetItem) const
{
	return getFrequencyOf(head, targetItem);
}


template<class T>
bool SinglyLinkedList<T>::contains(const T& targetItem) const
{
	return !isEmpty() && getPointerTo(targetItem) != nullptr;
}

template<class T>
SinglyNode<T>* SinglyLinkedList<T>::getPointerTo(SinglyNode<T>* nodePtr, const T& targetItem) const
{
	if (nodePtr == nullptr)
		return nullptr;

	else if (nodePtr->getItem() == targetItem)
		return nodePtr;

	else
		return getPointerTo(nodePtr->getNextNodePtr(), targetItem);
}

template<class T>
std::vector<T>* SinglyLinkedList<T> ::toVector(const bool useRecursion) const
{
	if (useRecursion)
		return toVectorUseRecursion(new std::vector<T>(), head);
	else
		return toVectorUseIteration();
}

template<class T>
std::vector<T>* SinglyLinkedList<T> ::toVectorUseIteration() const
{
	std::vector<T>* vectorContsiner = new std::vector<T>();

	if (isEmpty())
		return vectorContsiner;

	SinglyNode<T>* temp = head;

	while (temp != nullptr)
	{
		vectorContsiner->push_back(temp->getItem());

		temp = temp->getNextNodePtr();
	}

	temp = nullptr;

	return vectorContsiner;
}

template<class T>
std::vector<T>* SinglyLinkedList<T> ::toVectorUseRecursion(std::vector<T>* vectorContainer, SinglyNode<T>* nodePtr) const
{
	if (isEmpty() || nodePtr == nullptr)
		return vectorContainer;

	if (vectorContainer == nullptr)
		vectorContainer = new std::vector<T>();

	vectorContainer->push_back(nodePtr->getItem());

	return toVectorUseRecursion(vectorContainer, nodePtr->getNextNodePtr());
}

template<class T>
void SinglyLinkedList<T>::traverse() const
{
	if (isEmpty())
		return;

	SinglyNode<T>* temp = head;

	while (temp != nullptr)
	{
		std::cout << temp->getItem() << std::endl;
		temp = temp->getNextNodePtr();
	}
}

template<class T>
SinglyNode<T>* SinglyLinkedList<T>::clone(const SinglyNode<T>* targetNode)
{
	return new SinglyNode<T>(targetNode->getItem(), targetNode->getNextNodePtr());
}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
	clear();
	head = nullptr;
}
#endif // !_LINKEDLIST_IMPLEMENTATION_
