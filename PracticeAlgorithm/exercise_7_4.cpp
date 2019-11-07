#include "exercise_7_4.h"

namespace exercise_7_4
{
	int CalcMaxArea(std::vector<int> heights, int begin, int end)
	{
		if (end - begin == 1)
			return heights[begin];

		int mid = (begin + end) / 2;
		int area = std::max(CalcMaxArea(heights, begin, mid), CalcMaxArea(heights, mid, end));

		int min_height = std::min(heights[mid - 1], heights[mid]);
		area = std::max(area, 2 * min_height);

		int left = mid - 1;
		int right = mid;
		while (begin < left && right < end - 1)
		{
			if (begin < left && (right == end - 1 || heights[left - 1] >= heights[right + 1]))
			{
				--left;
				min_height = std::min(min_height, heights[left]);
			}
			else
			{
				++right;
				min_height = std::min(min_height, heights[right]);
			}

			area = std::max(area, min_height * (right + 1 - left));
		}

		return area;
	}
	void Exercise_7_4()
	{
		std::ifstream fin("exercise_7_4.txt");

		int test_case_count = 0;
		fin >> test_case_count;

		std::vector<std::vector<int>> test_case(test_case_count);

		int board_count = 0;
		for (int case_idx = 0; case_idx < test_case_count; ++case_idx)
		{
			fin >> board_count;
			test_case[case_idx].resize(board_count);

			for (int board_idx = 0; board_idx < board_count; ++board_idx)
			{
				fin >> test_case[case_idx][board_idx];
			}
		}

		fin.close();

		for (size_t i = 0; i < test_case.size(); ++i)
		{
			std::cout << CalcMaxArea(test_case[i], 0, test_case[i].size() - 1) << std::endl;
		}
	}
}