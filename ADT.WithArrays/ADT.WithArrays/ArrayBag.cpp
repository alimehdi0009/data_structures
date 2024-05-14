
#ifndef _ARRAY_BAG_IMP_

#define _ARRAY_BAG_IMP_


#include "ArrayBag.h"
#include <vector>
template<class ItemType>
ArrayBag<ItemType>::ArrayBag():itemCount(0),maxItems(DEFAULT_CAPACITY)
{}

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& anEntry) 
{
	bool hasRoomForEntry = maxItems > itemCount;

	if (!hasRoomForEntry) return false;

	items[itemCount++] = anEntry;

	return true;
}

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	vector<ItemType> bagContainer;

	for (int index = 0; index < itemCount; index++)
	{
		bagContainer.push_back(items[index]);
	}

	return bagContainer;
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return binarySearch(0, itemCount, anEntry);
}

template<class ItemType>
bool ArrayBag<ItemType>::binarySearch(int firstIndex, int lastIndex, const ItemType& targetEntry) const
{

	if (firstIndex == lastIndex && items[firstIndex] == targetEntry)
		return true;
	else
	{
		int midIndex = firstIndex + (lastIndex - firstIndex) / 2;

		if (items[midIndex] == targetEntry)
			return true;

		else if (items[midIndex] < targetEntry)
			return binarySearch(midIndex + 1, lastIndex, targetEntry);

		else
			return binarySearch(firstIndex, midIndex - 1, targetEntry);
	}

	return false;
}

template<class ItemType>
int ArrayBag<ItemType>::binarySearchGetIndex(int firstIndex, int lastIndex, const ItemType& targetEntry) const
{

	if (firstIndex == lastIndex && items[firstIndex] == targetEntry)
		return firstIndex;
	else
	{
		int midIndex = firstIndex + (lastIndex - firstIndex) / 2;

		if (items[midIndex] == targetEntry)
			return midIndex;

		else if (items[midIndex] < targetEntry)
			return binarySearch(midIndex + 1, lastIndex, targetEntry);

		else
			return binarySearch(firstIndex, midIndex - 1, targetEntry);
	}
	return -1;
}


template<class ItemType>
void ArrayBag<ItemType>::clear() {
	//items = [];
}

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry) {
	
	int indexLocated = indexLocated(anEntry);

	bool itemExists = indexLocated != -1 && !isEmpty();

	if (!itemExists) return false;

	items[indexLocated] = items[--itemCount];

	return itemExists;
}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
	 
	int count = 0;

	for (int index = 0; index < itemCount; index++)
	{
		if (items[index] == anEntry)
			count++;
	}
	
	return count;
}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOfRecursive(const ItemType& anEntry,int searchIndex) const 
{
	if (searchIndex >= itemCount)
		return 0;

	if (items[searchIndex] == anEntry)
		return 1 + getFrequencyOfRecursive(anEntry, ++searchIndex);
	else
		return getIndexOfRecursive(anEntry,++searchIndex);
}

template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& anEntry) const 
{
	int counter = 0;
	int index = -1;
	bool found = false;

	while (!found && counter < itemCount) 
	{
		if (items[counter] == anEntry)
		{
			index = counter;
			found = true;
			break;
		}
		counter++;
	}

	return index;
}


template<class ItemType>
int ArrayBag<ItemType>::getIndexOfRecursive(const ItemType& anEntry,int searchIndex) const
{
	if (searchIndex >= itemCount)
		return -1;
	else if (items[searchIndex] == anEntry)
		return searchIndex;
	else
		return getIndexOfRecursive(anEntry,++searchIndex);
}

#endif // !_ARRAY_BAG_IMP_