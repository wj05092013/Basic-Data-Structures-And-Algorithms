#include "exercise_7_2.h"

namespace exercise_7_2
{
	std::string Reverse(std::string::const_iterator& iter)
	{
		if (*iter == 'w' || *iter == 'b')
		{
			++iter;
			return std::string(iter - 1, iter);
		}
		else
		{
			++iter;		// Pass the character x.

			std::string top_left = Reverse(iter);
			std::string top_right = Reverse(iter);
			std::string bottom_left = Reverse(iter);
			std::string bottom_right = Reverse(iter);

			return std::string("x") + bottom_left + bottom_right + top_left + top_right;
		}
	}

	void Exercise_7_2()
	{
		std::ifstream fin("exercise_7_2.txt");

		int test_case_count = 0;
		std::string test_case;

		fin >> test_case_count;
		for (int i = 0; i < test_case_count; ++i)
		{
			fin >> test_case;

			auto iter = test_case.begin();
			std::string reversed_string = Reverse(iter);
			std::cout << reversed_string << std::endl;
		}

		fin.close();
	}
}
