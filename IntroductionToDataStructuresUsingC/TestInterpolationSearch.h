#pragma once

#include "InterpolationSearch.h"

namespace test_interpolation_search
{
	enum ECaseNum
	{
		eCase1 = 0,
		eCase2,
		eCase3,
		eCase4,
		eCase5,
		eCase6,
		eCase7,
		eCase8
	};

	extern const std::vector<std::vector<int>> test_cases;
	extern const std::vector<int> targets;

	void Test(ECaseNum case_num);
	void TestAll();
}
