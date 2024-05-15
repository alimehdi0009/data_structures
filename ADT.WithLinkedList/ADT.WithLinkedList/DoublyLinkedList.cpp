#ifndef _DOUBLY_LINKED_LIST_IMPLEMENTATION_

#define _DOUBLY_LINKED_LIST_IMPLEMENTATION_

#include <vector>
#include <iostream>

#include "DoublyNode.h"
#include "DoublyLinkedList.h"

template<class T>
DoublyLinkedList<T>::DoublyLinkedList():head(nullptr),tail(nullptr),itemsCount(0)
{}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& doublyLinkedList)
{
	if (!doublyLinkedList.isEmpty())
	{
		DoublyNode<T>* temp = doublyLinkedList.head;

		while (temp != nullptr)
		{
			addEnd(temp->getData());
			temp = temp->getNextPtr();
		}

		temp = nullptr;
	}
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const T dataArray[])
{

	int counter = 0;
	int arraySize = sizeof(dataArray);

	while (counter < arraySize)
	{
		addEnd(dataArray[counter]);
		counter++;
	}
}

template<class T>
bool DoublyLinkedList<T>::isEmpty() const
{
	return itemsCount == 0 || (head == nullptr && tail == nullptr);
}

template<class T>
bool DoublyLinkedList<T>::addStart(const T& nodeData)
{
	DoublyNode<T>* newNode = new DoublyNode<T>(nodeData,nullptr,nullptr);

	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		head->setPreviousPtr(newNode);

		newNode->setNextPtr(head);
		head = newNode;
	}

	itemsCount++;
	newNode = nullptr;

	return true;
}

template<class T>
bool DoublyLinkedList<T>::addEnd(const T& nodeValue)
{
	DoublyNode<T>* newNode = new DoublyNode<T>(nodeValue,nullptr,nullptr);

	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->setNextPtr(newNode);
		newNode->setPreviousPtr(tail);

		tail = newNode;
	}

	itemsCount++;

	newNode = nullptr;
	return true;
}

template<class T>
bool DoublyLinkedList<T>::removeStart()
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		DoublyNode<T>* temp = head;
		head = head->getNextPtr();

		deleteNode(temp);

		temp = nullptr;
	}

	return true;
}

template<class T>
bool DoublyLinkedList<T>::removeEnd() 
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		DoublyNode<T>* temp = tail;

		tail = tail->getPreviousPtr();

		tail->setNextPtr(nullptr);

		deleteNode(temp);

		temp = nullptr;

		return true;
	}
}

template<class T>
bool DoublyLinkedList<T>::deleteMiddleNode(DoublyNode<T>* targetNode)
{
	if (targetNode == head)
		return removeStart();
	else if (targetNode == tail)
		return removeEnd();
	else
	{
		DoublyNode<T>* prevNode = targetNode->getPreviousPtr();
		DoublyNode<T>* nextNode = targetNode->getNextPtr();

		prevNode->setNextPtr(nextNode);
		nextNode->setPreviousPtr(prevNode);

		deleteNode(targetNode);
		return true;
	}

	return false;
}

template<class T>
bool DoublyLinkedList<T>::removeRandom(const T& targetValue,bool recursively)
{
	if (recursively)
		return removeRandomRecursive(head, targetValue);
	else
		return removeRandomIterative(targetValue);
}

template<class T>
bool DoublyLinkedList<T>::removeRandomIterative(const T& targetValue) 
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		DoublyNode<T>* temp = head;

		bool isFound = false;

		while (temp->getNextPtr() != nullptr)
		{
			if (temp->getData() == targetValue)
			{
				isFound = true;
				break;
			}
			else
			{
				temp = temp->getNextPtr();
			}
		}

		isFound = isFound && temp->getData() == targetValue;

		if (isFound)
		{
			deleteMiddleNode(temp);
			temp = nullptr;
		}

		return isFound;
	}
}

template<class T>
bool DoublyLinkedList<T>::removeRandomRecursive(DoublyNode<T>* nodePtr, const T& targerValue)
{
	if (nodePtr == nullptr)
	{
		return false;
	}
	else
	{
		if (nodePtr->getData() == targerValue)
		{
			deleteMiddleNode(nodePtr);
			nodePtr = nullptr;
			return true;
		}

		return removeRandomRecursive(nodePtr->getNextPtr(), targerValue);
	}
}

template<class T>
bool DoublyLinkedList<T>::deleteNode(DoublyNode<T>* targetNode)
{
	if (isEmpty())
		return false;

	delete targetNode;
	itemsCount--;

	return true;
}

template<class T>
int DoublyLinkedList<T>::getCurrentSizeIterative() const 
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		DoublyNode<T>* temp = head;
		int counter = 0;

		while (temp != nullptr)
		{
			temp = temp->getNextPtr();
			counter++;
		}

		temp = nullptr;

		return counter;
	}
}

template<class T>
int DoublyLinkedList<T>::getCurrentSizeRecursive(DoublyNode<T>* nodePtr) const
{
	if (nodePtr == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + getCurrentSizeRecursive(nodePtr->getNextPtr());
	}
}

template<class T>
int DoublyLinkedList<T>::getFrequencyOf(const T& targetValue,bool recursively) const
{
	if (recursively)
		return getFrequencyOfRecursive(targetValue);
	else
		return getFrequencyOfIterative(targetValue);
}

template<class T>
int DoublyLinkedList<T>::getFrequencyOfIterative(const T& targetValue) const
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		int counter = 0;
		DoublyNode<T>* temp = head;

		while (temp != nullptr)
		{
			if (temp->getData() == targetValue)
				counter++;

			temp = temp->getNextPtr();
		}

		temp = nullptr;

		return counter;
	}
}

template<class T>
int DoublyLinkedList<T>::getFrequencyOfRecursive(DoublyNode<T>* nodePtr, const T& targetValue) const
{
	if (nodePtr == nullptr)
		return 0;
	else if (nodePtr->getData() == targetValue)
		return 1 + getFrequencyOfRecursive(nodePtr->getNextPtr(), targetValue);
	else
		return getFrequencyOfRecursive(nodePtr->getNextPtr(), targetValue);
}

template<class T>
void DoublyLinkedList<T>::clear()
{
	if (isEmpty())
		return;
	else
	{
		DoublyNode<T>* temp = head;
		DoublyNode<T>* prevNode = temp;

		while (temp != nullptr)
		{
			prevNode = temp;
			temp = temp->getNextPtr();

			deleteNode(prevNode);
		}

		temp = nullptr;
		prevNode = nullptr;
	}
}

template<class T>
int DoublyLinkedList<T>::getCurrentSize() const
{
	return itemsCount;
}

template<class T>
int DoublyLinkedList<T>::getItemsCount(const bool recursively) const
{
	if (recursively)
		return getCurrentSizeRecursive(head);
	else
		return getCurrentSizeIterative();
}

template<class T>
std::vector<T>* DoublyLinkedList<T>::toVector(const bool recursively) const
{
	if (recursively)
		return toVectorUseRecursion(new std::vector<T>(), head);
	else
		return toVectorUseIteration();
}

template<class T>
std::vector<T>* DoublyLinkedList<T>::toVectorUseIteration() const
{
	std::vector<T>* vectorContainer = new std::vector<T>();

	if (isEmpty())
	{
		return vectorContainer;
	}
	else
	{
		DoublyNode<T>* temp = head;

		while (temp != nullptr)
		{
			vectorContainer->push_back(temp->getData());

			temp = temp->getNextPtr();
		}

		temp = nullptr;

		return vectorContainer;
	}
}

template<class T>
std::vector<T>* DoublyLinkedList<T>::toVectorUseRecursion(std::vector<T>* vectorContainer, DoublyNode<T>* nodePtr) const
{
	if (isEmpty() || nodePtr == nullptr)
		return vectorContainer;
	
	if (vectorContainer == nullptr)
		vectorContainer = new std::vector<T>();

	vectorContainer->push_back(nodePtr->getData());

	return toVectorUseRecursion(vectorContainer,nodePtr);
}

template<class T>
void DoublyLinkedList<T>::traverse(bool backward , const bool recursively) const
{
	if (isEmpty())
		return;
	else if (recursively)
	{
		if (backward)
			return traverseBackwardRecursive(tail);
		else
			return traverseForwardRecursive(head);
	}
	else
	{
		if (backward)
			return traverseBackwardIterative();
		else
			return traverseForwardIterative();
	}
}

template<class T>
void DoublyLinkedList<T>::traverseForwardIterative() const
{
	DoublyNode<T>* temp = head;

	while (temp != nullptr)
	{
		std::cout << temp->getData() << std::endl;

		temp = temp->getNextPtr();
	}

	temp = nullptr;

}

template<class T>
void DoublyLinkedList<T>::traverseForwardRecursive(DoublyNode<T>* nodePtr) const
{
	if (nodePtr == nullptr)
		return;
	else
	{
		std::cout << nodePtr->getData() << std::endl;

		traverseForwardRecursive(nodePtr->getNextPtr());
	}
}

template<class T>
void DoublyLinkedList<T>::traverseBackwardIterative() const
{
	DoublyNode<T>* temp = tail;

	while (temp != nullptr)
	{
		std::cout << temp->getData() << std::endl;

		temp = temp->getPreviousPtr();
	}

	temp = nullptr;
}

template<class T>
void DoublyLinkedList<T>::traverseBackwardRecursive(DoublyNode<T>* nodePtr) const
{
	if (nodePtr == nullptr)
		return;
	else
	{
		std::cout << nodePtr->getData() << std::endl;

		traverseBackwardRecursive(nodePtr->getPreviousPtr());
	}
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() 
{
	clear();
	head = nullptr;
	tail = nullptr;
}
#endif // !_DOUBLY_LINKED_LIST_IMPLEMENTATION_
