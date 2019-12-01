#include "QuickSort.h"

namespace algorithm
{
	size_t SelectPivotIdx(std::vector<int>& arr, size_t begin, size_t end, compare::CompareFunctor<int>& comp)
	{
		size_t last = end - 1;
		size_t mid = (begin + last) / 2;

		// Choose median of three(first, middle and last element).
		if (comp(arr[begin], arr[mid]))
		{
			if (comp(arr[mid], arr[last]))
				return mid;
			else
			{
				if (comp(arr[begin], arr[last]))
					return last;
				else
					return begin;
			}
		}
		else
		{
			if (comp(arr[mid], arr[last]))
			{
				if (comp(arr[begin], arr[last]))
					return begin;
				else
					return last;
			}
			else
				return mid;
		}
	}

	void QuickSort(std::vector<int>& arr, size_t begin, size_t end, compare::CompareFunctor<int>& comp)
	{
		if (end - begin < 2)
			return;

		size_t pivot = SelectPivotIdx(arr, begin, end, comp);
		Swap(arr[begin], arr[pivot]);
		pivot = begin;

		size_t low = begin + 1;
		size_t high = end - 1;

		while (true)
		{
			while (low < end - 1 && comp(arr[low], arr[pivot]))
				++low;
			while (begin < high && !comp(arr[high], arr[pivot]))
				--high;

			if (high <= low)
				break;

			Swap(arr[low], arr[high]);
		}

		Swap(arr[pivot], arr[high]);

		QuickSort(arr, begin, high, comp);
		QuickSort(arr, high + 1, end, comp);
	}

	void QuickSort(std::vector<int>& arr, compare::CompareFunctor<int>&& comp)
	{
		QuickSort(arr, 0, arr.size(), comp);
	}
}
