#pragma once
#include <vector>
#include <iostream>

#ifdef _DEBUG
#define DebugErr std::cout << "[Error] " << __FILE__ << "(" << __LINE__ << ")" << std::endl
#else
#define DebugErr
#endif

#define ForEachBeginEnd(itr, begin, end, container) for (auto (itr) = (begin); (itr) != (end); ++(itr))
#define ForEachBegin(itr, begin, container) ForEachBeginEnd(itr, begin, container.end(), container)
#define ForEachEnd(itr, end, container) ForEachBeginEnd(itr, container.begin(), end, container)
#define ForEach(itr, container) ForEachBegin(itr, container.begin(), container)
#define PrintLn(content) std::cout << (content) << std::endl

struct Range
{
	Range(int minimum = 0, int maximum = 0):
		min(minimum),
		max(maximum)
	{
	}

	int min;
	int max;
};

class Tool
{
public:
	~Tool(void);
	
	static void generateRandNum(int count, const Range& range, std::vector<int>& numSet);

	template <typename T>
	static void show(const std::vector<T>& numSet, int itemsPerLine = 10);

	template <typename T>
	static void bubbleSort(std::vector<T>& items);

	template <typename Iterator>
	static void quickSort(Iterator itrL, Iterator itrR);

	template <typename T>
	static void insertSort(std::vector<T>& items);

	template <typename T>
	static void binaryInsertSort(std::vector<T>& items);

private:
	static Tool tool;///< Initialize the program, such as set random seed.
	Tool(void);

};

template <typename T>
void Tool::show(const std::vector<T>& numSet, int itemsPerLine)
{
	if (itemsPerLine <= 0)
	{
		DebugErr;
		return;
	}

	string text;
	int lastIndex = itemsPerLine - 1;
	int count = 0;
	for (auto item : numSet)
	{
		text += to_string(item) + " ";
		++count;
		if (0 == count % itemsPerLine)
		{
			PrintLn(text);
			text.clear();
		}
	}

	if (!text.empty())
		PrintLn(text);
}

template <typename T>
void Tool::bubbleSort(std::vector<T>& items)
{
	ForEach (itrA, items)
		ForEachBegin (itrB, itrA + 1, items)
			if (*itrA > *itrB)
				std::swap(*itrA, *itrB);
}

template <typename Iterator>
void Tool::quickSort(Iterator begin, Iterator end)
{
	auto l = begin;
	auto r = end;
	auto key = *begin;

	while (l < r)
	{
		while (l < r && *r >= key) --r;
		*l = *r;

		while (l < r && *l <= key) ++l;
		*r = *l;
	}
	*l = key;

	if (l - begin > 1)
		quickSort(begin, l - 1);

	if (end - l > 1)
		quickSort(l + 1, end);
}

template <typename T>
void Tool::insertSort(std::vector<T>& items)
{
	T temp;
	int count = items.size();
	for (int i = 0; i < count; ++i)
	{
		temp = items[i];
		int j = i - 1;
		for (; j >= 0 && items[j] > temp; --j)
			items[j + 1] = items[j];

		items[j + 1] = temp;
	}
}

template <typename T>
void Tool::binaryInsertSort(std::vector<T>& items)
{
	T temp;
	int count = items.size();
	for (int i = 1; i < count; ++i)
	{
		temp = items[i];

		int low = 0;
		int high = i - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (temp < items[mid])//Stable sorting result: a < b < c <= low = high < d < e
				high = mid - 1;
			else
				low = mid + 1;
		}

		for (int j = i - 1; j >= high + 1; --j)
			items[j + 1] = items[j];

		items[high + 1] = temp;
	}
}
