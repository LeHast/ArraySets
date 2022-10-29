#include <iostream>
#include <string>
#include "arrayset.h"


using std::cout;
using std::endl;
using std::string;

void displayBag(ArraySet<std::string>& bag)
{
	cout << "The bag contains " << bag.getCurrentSize()
		<< " items:" << endl;
	std::vector<string> bagItems = bag.toVector();

	int numberOfEntries = (int)bagItems.size();
	for (int i = 0; i < numberOfEntries; i++)
	{
		cout << bagItems[i] << " ";
	}  
	cout << endl << endl;
}

int main() {

	ArraySet<std::string> ary, ary2, ary3;
	bool check;

	std::cout << ary.getCurrentSize() << std::endl;

	std::string items[] = { "2", "3","4"};
	std::string items2[] = { "8", "6","1"};

	cout << "Add 6 items to the bag: " << endl;

	for (int i = 0; i < 3; i++)
	{
		ary.add(items[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		ary2.add(items2[i]);
	}

	displayBag(ary);
	displayBag(ary2);
	/*
	ary3 = ary.Union(ary2, check);
	
	if (check) {
		displayBag(ary3);
	}
	*/
	ary3 = ary2.setIntersection(ary);
	std::cout << "setIntersection" << endl;
	displayBag(ary3);

	/*std::cout << "set difference" << endl;
	ary3 = ary.setDifference(ary2);
	displayBag(ary3);*/

	system("pause");
	return 0;
}

