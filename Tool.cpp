#include "Tool.h"
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

Tool Tool::tool;

Tool::Tool(void)
{
	srand((unsigned int)time(NULL));
}

Tool::~Tool(void)
{
}

void Tool::generateRandNum(int count, const Range& range, std::vector<int>& numSet)
{
	numSet.clear();

	if (count <= 0)
	{
		DebugErr;
		return;
	}

	int origin = range.max - range.min;
	if (origin < 0)
	{
		DebugErr;
		return;
	}
	else if (origin == 0)
	{
		numSet = std::vector<int>(count, range.min);
		return;
	}
	else
	{
		numSet.resize(count);

		for (auto& item : numSet)
		{
			item = rand() % origin + range.min;
		}
	}

	return;
}
