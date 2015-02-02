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

	template <typename ITR>
	static void quickSort(ITR itrL, ITR itrR);

private:
	static Tool tool;///< 静态成员，在Tool构造函数中进行程序初始化，如生成随机数种子
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

template <typename ITR>
void Tool::quickSort(ITR begin, ITR end)
{
	ITR l = begin;
	ITR r = end;
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
