
/** Header file for an array-based implementation of the ADT array. Listing 3-1.
 @file arrayset.h */


/** setUnion() function 
It is a new array combination of two existing arrays. 
This funtion pass the values from array1 and array2 to make array3
also it used bool @result to check if the union went right.
@return a pointer ArraySet 
*/

/** setIntersection() function
The intersection of two arrays is a new array with all the  values from the other 
2 arrays.
@return a pointer ArraySet
*/

/** setDifference() function
The difference is a new array with the values of the left array after removing
those that also are in the right array.
@return a pointer ArraySet
*/

#ifndef ARRAY_SET_
#define ARRAY_SET_

#include "setinterface.h"

template<class ItemType>
class ArraySet : public SetInteface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 6; // Small size to test for a full array
	ItemType items[DEFAULT_CAPACITY];      // Array of items
	int itemCount;                         // Current count of array items 
	int maxItems;                          // Max capacity of the array

	// Returns either the index of the element in the array items that
	// contains the given target or -1, if the array does not contain 
	// the target.
	int getIndexOf(const ItemType& target) const;

public:
	ArraySet();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	std::vector<ItemType> toVector() const;
	ArraySet& setUnion(const ArraySet&, bool&);
	ArraySet& setIntersection(const ArraySet&);
	ArraySet& setDifference(const ArraySet&);

	//setDifference();
}; // end ArraySet 

#include "arrayset.cpp"
#endif