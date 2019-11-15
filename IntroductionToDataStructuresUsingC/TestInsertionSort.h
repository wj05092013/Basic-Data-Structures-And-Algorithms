#pragma once

#include "InsertionSort.h"

namespace test_insertion_sort
{
	enum ECaseNum
	{
		eCase1 = 0,
		eCase2,
		eCase3,
		eCase4,
		eCase5,
		eCase6,
	};

	enum ESortOrder
	{
		eAscending,
		eDescending
	};

	extern std::vector<std::vector<int>> test_cases;

	void InitTestCases();
	void Test(ECaseNum case_num, ESortOrder sort);
	void TestAll();
}
