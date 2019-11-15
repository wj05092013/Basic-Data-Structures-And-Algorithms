#include "InsertionSort.h"

namespace algorithm
{
	void InsertionSort(std::vector<int>& arr, compare::CompareFunctor<int>&& comp)
	{
		int arr_size = static_cast<int>(arr.size());

		for (int i = 1; i < arr_size; ++i)
		{
			int curr_data = arr[i];
			int j = i - 1;

			while (j >= 0 && comp(curr_data, arr[j]))
			{
				arr[j + 1] = arr[j];
				--j;
			}

			arr[j + 1] = curr_data;
		}
	}
}
