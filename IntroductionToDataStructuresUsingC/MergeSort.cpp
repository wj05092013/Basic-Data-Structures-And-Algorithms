#include "MergeSort.h"

namespace algorithm
{
	void Merge(std::vector<int>& arr, size_t begin, size_t mid, size_t end, compare::CompareFunctor<int>& comp)
	{
		std::vector<int> sorted_arr(end - begin);
		size_t insert_idx = 0;
		size_t left_idx = begin;
		size_t right_idx = mid;
		int curr_data = 0;

		while (insert_idx < sorted_arr.size())
		{
			if (left_idx < mid && right_idx < end)
			{
				if (comp(arr[left_idx], arr[right_idx]))
				{
					curr_data = arr[left_idx];
					++left_idx;
				}
				else
				{
					curr_data = arr[right_idx];
					++right_idx;
				}
			}
			else if (left_idx < mid)
			{
				curr_data = arr[left_idx];
				++left_idx;
			}
			else
			{
				curr_data = arr[right_idx];
				++right_idx;
			}

			sorted_arr[insert_idx] = curr_data;
			++insert_idx;
		}

		for (size_t i = 0; i < sorted_arr.size(); ++i)
			arr[begin + i] = sorted_arr[i];
	}

	void MergeSort(std::vector<int>& arr, size_t begin, size_t end, compare::CompareFunctor<int>& comp)
	{
		if (end - begin < 2)
			return;

		size_t mid = (begin + end) / 2;

		MergeSort(arr, begin, mid, comp);
		MergeSort(arr, mid, end, comp);

		Merge(arr, begin, mid, end, comp);
	}

	void MergeSort(std::vector<int>& arr, compare::CompareFunctor<int>&& comp)
	{
		MergeSort(arr, 0, arr.size(), comp);
	}
}