#include "Tool.h"
#include <string>
#include <algorithm>
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

	int origin = range.max - range.min;
	if (count <= 0 || origin < 0)
	{
		DebugErr;
		return;
	}
	
	if (origin == 0)
	{
		numSet = std::vector<int>(count, range.min);
		return;
	}

	numSet.resize(count);
	std::generate(numSet.begin(), numSet.end(), [&] { return rand() % origin + range.min; });

	return;
}
