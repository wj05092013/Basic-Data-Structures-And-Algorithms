#include "TestInterpolationSearch.h"
#include "Print.h"

namespace test_interpolation_search
{
	const std::vector<std::vector<int>> test_cases{
		std::vector<int>{1,3,4,5,7,9,11,22,23,25},
		std::vector<int>{1,3,4,5,7,9,11,22,23,25},
		std::vector<int>{1,3,4,5,7,9,11,22,23,25},
		std::vector<int>{},
		std::vector<int>{3},
		std::vector<int>{6},
		std::vector<int>{7,7,7,7,7},
		std::vector<int>{5,5,5,5}
	};

	const std::vector<int> targets{
		23,
		8,
		31,
		1,
		3,
		5,
		7,
		6
	};

	void Test(ECaseNum case_num)
	{
		std::cout << "Test Case " << case_num + 1 << ": ";
		print::PrintArray(test_cases[case_num]);
		std::cout << std::endl;

		std::cout << "Target: " << targets[case_num] << std::endl;

		int target_idx = algorithm::InterpolationSearch(test_cases[case_num], targets[case_num]);

		if (target_idx == test_cases[case_num].size())
			std::cout << "No Target." << std::endl;
		else
			std::cout << "Target Index: " << target_idx << std::endl;
		std::cout << std::endl;
	}

	void TestAll()
	{
		Test(ECaseNum::eCase1);
		Test(ECaseNum::eCase2);
		Test(ECaseNum::eCase3);
		Test(ECaseNum::eCase4);
		Test(ECaseNum::eCase5);
		Test(ECaseNum::eCase6);
		Test(ECaseNum::eCase7);
		Test(ECaseNum::eCase8);
	}
}