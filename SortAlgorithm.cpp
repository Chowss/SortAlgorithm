#include <iostream>
#include <string>
#include "Tool.h"
using namespace std;

int main()
{
	cout << "Sort Algorithm" << endl;

	//Initialize variables.
	vector<int> numSet;
	int count = 15;
	Range range(-10, 40);

	typedef void (*SortFunc)(vector<int>&);
	auto callSort = [&](SortFunc sortFunc) {
		//Generate random numbers.
		Tool::generateRandNum(count, range, numSet);
		Tool::show(numSet, count);

		//Sort numbers.
		(sortFunc)(numSet);
		Tool::show(numSet, count);

		//Check whether is sorted.
		if (!Tool::check(numSet))
			cout << "Error !!!" << endl;
	};

	//Call different sort algorithms.
	cout << "\nBubble sort" << endl;
	callSort(Tool::bubbleSort);

	cout << "\nQuick sort" << endl;
	callSort(Tool::quickSort);

	cout << "\nInsert sort" << endl;
	callSort(Tool::insertSort);

	cout << "\nBinary insert sort" << endl;
	callSort(Tool::binaryInsertSort);

	cout << "\nCocktail sort" << endl;
	callSort(Tool::cocktailSort);

	cout << "\nSelect sort" << endl;
	callSort(Tool::selectSort);

	cout << "\nHeap sort" << endl;
	callSort(Tool::heapSort);

	cout << "\nPeagonhole sort" << endl;
	callSort(Tool::peagonholeSort);

	return 0;
}