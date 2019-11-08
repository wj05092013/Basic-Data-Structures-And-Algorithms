#include "Print.h"

namespace print
{
	void PrintArray(const std::vector<int>& arr)
	{
		for (size_t i = 0; i < arr.size(); ++i)
		{
			std::cout << arr[i] << " ";
		}
	}
}