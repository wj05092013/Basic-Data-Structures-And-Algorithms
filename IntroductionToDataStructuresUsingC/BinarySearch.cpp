#include "BinarySearch.h"

namespace algorithm
{
	int BinarySearch(const std::vector<int>& arr, int target, int begin, int end)
	{
		// There's no target element.
		if (begin >= end)
			return -1;

		int mid = (begin + end) / 2;

		// Target found.
		if (arr[mid] == target)
			return mid;

		if (target < arr[mid])
			return BinarySearch(arr, target, begin, mid);
		else
			return BinarySearch(arr, target, mid + 1, end);
	}
}
