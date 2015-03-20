#pragma once
#include <vector>
#include <iostream>

#ifdef _DEBUG
#define DebugErr std::cout << "[Error] " << __FILE__ << "(" << __LINE__ << ")" << std::endl
#else
#define DebugErr
#endif

#define ForEachBeginEnd(itr, begin, end, container) for (auto (itr) = (begin); (itr) != (end); ++(itr))
#define ForEachBegin(itr, begin, container) ForEachBeginEnd((itr), (begin), container.end(), container)
#define ForEachEnd(itr, end, container) ForEachBeginEnd((itr), container.begin(), (end), container)
#define ForEach(itr, container) ForEachBegin((itr), container.begin(), container)
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
	static bool check(const std::vector<T>& items);

	template <typename T>
	static void bubbleSort(std::vector<T>& items);

	template <typename T>
	static void quickSort(std::vector<T>& items);

	template <typename T>
	static void insertSort(std::vector<T>& items);

	template <typename T>
	static void binaryInsertSort(std::vector<T>& items);

	template <typename T>
	static void cocktailSort(std::vector<T>& items);

	template <typename T>
	static void selectSort(std::vector<T>& items);

	template <typename T>
	static void heapSort(std::vector<T>& items);

	template <typename T>
	static void peagonholeSort(std::vector<T>& items);

	template <typename T>
	static void mergeSort(std::vector<T>& items);

private:
	template <typename Iterator>
	static void quickSort(Iterator itrL, Iterator itrR);

	template <typename T>
	static void heapAdjust(int index, std::vector<T>& items, int count);

	template <typename T>
	static void mergeSort(std::vector<T>& items, std::vector<T>& tmp, size_t st, size_t ed);

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
bool Tool::check(const std::vector<T>& items)
{
	ForEachBegin (itr, items.begin() + 1, items)
		if (*(itr - 1) > *itr)
			return false;

	return true;
}

template <typename T>
void Tool::bubbleSort(std::vector<T>& items)
{
	ForEach (itrA, items)
		ForEachBegin (itrB, itrA + 1, items)
			if (*itrA > *itrB)
				std::swap(*itrA, *itrB);
}

template <typename T>
void Tool::quickSort(std::vector<T>& items)
{
	quickSort(items.begin(), items.end() - 1);
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

template <typename T>
void Tool::cocktailSort(std::vector<T>& items)
{
	int count = items.size();
	int halfCount = count / 2;
	for (int i = 0; i < halfCount; ++i)
	{
		for (int j = i + 1; j < count - i; ++j)
			if (items[j - 1] > items[j])
				std::swap(items[j - 1], items[j]);

		for (int j = count - i - 2; j > i; --j)
			if (items[j - 1] > items[j])
				std::swap(items[j - 1], items[j]);
	}
}

template <typename T>
void Tool::selectSort(std::vector<T>& items)
{
	int count = items.size();
	for (int i = 0; i < count; ++i)
	{
		int swapIndex = i;
		for (int j = i + 1; j < count; ++j)
			if (items[j] < items[swapIndex])
				swapIndex = j;

		if (swapIndex != i)
			std::swap(items[i], items[swapIndex]);
	}
}

template <typename T>
void Tool::heapAdjust(int index, std::vector<T>& items, int count)
{
	int l = (index << 1) + 1;
	int r = (index << 1) + 2;
	int minIndex = index;
	if (l < count && items[l] > items[index])
		minIndex = l;

	if (r < count && items[r] > items[minIndex])
		minIndex = r;

	if (minIndex != index)
	{
		std::swap(items[index], items[minIndex]);
		heapAdjust(minIndex, items, count);
	}
}

template <typename T>
void Tool::heapSort(std::vector<T>& items)
{
	size_t count = items.size();
	for (int i = (count - 2) / 2; i >= 0; --i)
		heapAdjust(i, items, count);

	for (int i = count - 1; i > 0; --i)
	{
		std::swap(items[0], items[i]);
		heapAdjust(0, items, i);
	}
}

template <typename T>
void Tool::peagonholeSort(std::vector<T>& items)
{
	if (items.size() < 2)
		return;

	T minNum = items.front();
	T maxNum = items.front();

	for (const T& item : items) {
		if (maxNum < item) maxNum = item;
		if (minNum > item) minNum = item;
	}

	for (T& item : items)
		item -= minNum;

	std::vector<T> indexSet(maxNum - minNum + 1, 0);
	for (T& item : items)
		++(indexSet[item]);

	int index = 0;
	for (size_t i = 0; i < indexSet.size(); ++i)
		for (int j = 0; j < indexSet[i]; ++j)
			items[index++] = i + minNum;
}

template <typename T>
void Tool::mergeSort(std::vector<T>& items, std::vector<T>& tmp, size_t st, size_t ed)
{
	if (st < ed)
	{
		size_t mid = (st + ed) / 2;
		mergeSort(items, tmp, st, mid);
		mergeSort(items, tmp, mid + 1, ed);

		size_t i = st;
		size_t j = mid + 1;
		size_t k = st;
		while (i <= mid && j <= ed)
		{
			if (items[i] < items[j])
				tmp[k++] = items[i++];
			else
				tmp[k++] = items[j++];
		}

		while (i <= mid)
			tmp[k++] = items[i++];

		while (j <= ed)
			tmp[k++] = items[j++];

		for (i = st; i <= ed; ++i)
			items[i] = tmp[i];
	}
}

template <typename T>
void Tool::mergeSort(std::vector<T>& items)
{
	size_t end = items.size() - 1;
	std::vector<T> tmp(items.size());
	mergeSort(items, tmp, 0, end);
}
