template<class T>
bool ArraySet<T>::add(const T& newEntry){
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;

		for (int y = 0; y < getCurrentSize(); ++y) {
			for(int x = y + 1; x < getCurrentSize(); x++)
			if (items[x] == items[y]) {
				std::cout << "No Duplicates Allow" << std::endl;
				std::cout << "Try other value: " << std::endl;
				std::cin >> items[itemCount - 1];
				y = 0;
				x = y + 1;
				//exit(EXIT_FAILURE);
			}
		}
	}

	return hasRoomToAdd;
}  // end add





template<class T>
ArraySet<T>::ArraySet() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor





template<class T>
int ArraySet<T>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize





template<class T>
bool ArraySet<T>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty





template<class T>
std::vector<T> ArraySet<T>::toVector() const
{
	std::vector<T> arrayContents;
	for (int i = 0; i < itemCount; i++)
		arrayContents.push_back(items[i]);

	return arrayContents;
}  // end toVector





template <class T>
bool ArraySet<T>::contains(const T& anEntry) const
{
	bool isFound = false;
	int curIndex = 0; // Current array index
	while (!isFound && (curIndex < itemCount))
	{
		isFound = (anEntry == items[curIndex]);
		if (!isFound)
			curIndex++; // Increment to next entry
	} // end while

	return isFound;
} // end contains




template<class T>
void ArraySet<T>::clear()
{
	itemCount = 0;
}  // end clear





template<class T>
int ArraySet<T>::getIndexOf(const T& target) const
{
	bool isFound = false;
	int result = -1;
	int searchIndex = 0;

	// If the array is empty, itemCount is zero, so loop is skipped
	while (!isFound && (searchIndex < itemCount))
	{
		isFound = (items[searchIndex] == target);
		if (isFound)
		{
			result = searchIndex;
		}
		else
		{
			searchIndex++;
		}  // end if
	}  // end while

	return result;
}  // end getIndexOf






template<class T>
bool ArraySet<T>::remove(const T& anEntry)
{
	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if

	return canRemoveItem;
}  // end remove





template<class T>
ArraySet<T>& ArraySet<T>::setUnion(const ArraySet<T> &ary, bool &result){
	ArraySet *resultPtr = new ArraySet;
	result = true;

	for (int i = 0; i < getCurrentSize(); i++) {
		resultPtr->add(items[i]);
	}
	for (int i = 0; i < ary.getCurrentSize(); i++) {
		resultPtr->add(ary.items[i]);
	}		
	return *resultPtr;
}





template<class T>
ArraySet<T>& ArraySet<T>::setIntersection(const ArraySet& ary) {
	ArraySet *resultPtr = new ArraySet;
	
	for (int i = 0; i < itemCount; i++) {
		resultPtr->add(items[i]);
	}
	for (int i = 0; i < ary.itemCount; i++) {
		resultPtr->add(ary.items[i]);
	}

	return *resultPtr;
}





template<class T>
ArraySet<T>& ArraySet<T>::setDifference(const ArraySet& ary) {
	ArraySet *resultPtr = new ArraySet;
	bool bPass = true;
	
	for (int x = 0; x < getCurrentSize(); x++) {
		for (int i = 0; i < ary.getCurrentSize(); i++) {
			if (items[x] == ary.items[i]) {
				x++;
				bPass = false;
				break;
			}
		}
		if(bPass){
			resultPtr->add(items[x]);
		}
		bPass = true;
	}

	return *resultPtr;
}
