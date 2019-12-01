#include "TestQuickSort.h"
#include "Print.h"

namespace test_quick_sort
{
	std::vector<std::vector<int>> test_cases;

	void InitTestCases()
	{
		test_cases = {
			std::vector<int>{1,2,3,4,5},
			std::vector<int>{},
			std::vector<int>{3},
			std::vector<int>{5,5,5,5,5,5,5,5,5,5},
			std::vector<int>{1,2,3,4,5,6,7,8,9,10},
			std::vector<int>{10,9,8,7,6,5,4,3,2,1}
		};
	}

	void Test(ECaseNum case_num, ESortOrder sort)
	{
		std::cout << "Test Case " << case_num + 1;
		std::cout << "-> "; print::PrintArray(test_cases[case_num]); std::cout << std::endl;

		if (sort == ESortOrder::eAscending)
		{
			std::cout << "QuickSort() (Ascending)";
			algorithm::QuickSort(test_cases[case_num], algorithm::compare::Less<int>());
		}
		else
		{
			std::cout << "QuickSort() (Descending)";
			algorithm::QuickSort(test_cases[case_num], algorithm::compare::Greater<int>());
		}

		std::cout << "-> "; print::PrintArray(test_cases[case_num]); std::cout << std::endl << std::endl;
	}

	void TestAll()
	{
		InitTestCases();

		Test(ECaseNum::eCase1, ESortOrder::eAscending);
		Test(ECaseNum::eCase2, ESortOrder::eAscending);
		Test(ECaseNum::eCase3, ESortOrder::eAscending);
		Test(ECaseNum::eCase4, ESortOrder::eAscending);
		Test(ECaseNum::eCase5, ESortOrder::eAscending);
		Test(ECaseNum::eCase6, ESortOrder::eAscending);

		InitTestCases();

		Test(ECaseNum::eCase1, ESortOrder::eDescending);
		Test(ECaseNum::eCase2, ESortOrder::eDescending);
		Test(ECaseNum::eCase3, ESortOrder::eDescending);
		Test(ECaseNum::eCase4, ESortOrder::eDescending);
		Test(ECaseNum::eCase5, ESortOrder::eDescending);
		Test(ECaseNum::eCase6, ESortOrder::eDescending);
	}
}
