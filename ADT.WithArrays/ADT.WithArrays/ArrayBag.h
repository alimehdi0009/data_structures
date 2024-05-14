#pragma once

#ifndef _ARRAY_BAG_DEF

#define _ARRAY_BAG_DEF

using namespace std;

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 6;
	ItemType items[DEFAULT_CAPACITY];

	int itemCount;
	int maxItems;

	int getIndexOf(const ItemType& target) const;
	bool binarySearch(int firstIndex, int lastIndex, const ItemType& targetEntry) const;
	int binarySearchGetIndex(int firstIndex, int lastIndex, const ItemType& targetEntry) const;
	int getIndexOfRecursive(const ItemType& anEntry, int searchIndex) const;

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& anEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	int getFrequencyOfRecursive(const ItemType& anEntry,int searchIndex) const;
	vector<ItemType> toVector() const;

};

#include "ArrayBag.cpp";
#endif // !_ARRAY_BAG_DEF

