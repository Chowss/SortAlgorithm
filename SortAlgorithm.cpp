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
	cout << "Result:" << endl;
	Tool::show(numSet);

	cout << "\nQuick sort" << endl;
	Tool::generateRandNum(10, Range(0, 20), numSet);
	Tool::show(numSet);
	Tool::quickSort(numSet.begin(), numSet.end() - 1);
	cout << "Result:" << endl;
	Tool::show(numSet);

	return 0;
}