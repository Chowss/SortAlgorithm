#include <iostream>
#include <string>
#include "Tool.h"
using namespace std;

int main()
{
	cout << "Sort Algorithm" << endl;

	vector<int> numSet;
	cout << "\nBubble sort" << endl;
	Tool::generateRandNum(10, Range(0, 20), numSet);
	Tool::show(numSet);
	Tool::bubbleSort(numSet);
	Tool::show(numSet);

	cout << "\nQuick sort" << endl;
	Tool::generateRandNum(10, Range(0, 20), numSet);
	Tool::show(numSet);
	Tool::quickSort(numSet.begin(), numSet.end() - 1);
	Tool::show(numSet);

	cout << "\nInsert sort" << endl;
	Tool::generateRandNum(10, Range(0, 20), numSet);
	Tool::show(numSet);
	Tool::insertSort(numSet);
	Tool::show(numSet);

	cout << "\nBinary insert sort" << endl;
	Tool::generateRandNum(10, Range(0, 20), numSet);
	Tool::show(numSet);
	Tool::binaryInsertSort(numSet);
	Tool::show(numSet);

	return 0;
}