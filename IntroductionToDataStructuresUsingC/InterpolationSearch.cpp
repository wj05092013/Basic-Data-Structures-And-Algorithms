#include "InterpolationSearch.h"

namespace algorithm
{
	size_t InterpolationSearch(const std::vector<int>& arr, int target, size_t begin, size_t end)
	{
		size_t last = end - 1;

		// There is no target element.
		if (target < arr[begin] || arr[last] < target)
			return arr.size();

		size_t mid = 0;
		int divisor = arr[last] - arr[begin];

		// If there is just one element or the begin and last elements are the same.
		if (divisor == 0)
			mid = begin;
		else
			mid = static_cast<size_t>(begin + (last - begin)
				* static_cast<float>(target - arr[begin])
				/ static_cast<float>(arr[last] - arr[begin]));

		if (target < arr[mid])
			return InterpolationSearch(arr, target, begin, mid);
		else if (arr[mid] < target)
			return InterpolationSearch(arr, target, mid + 1, end);
		else
			return mid;
	}

	size_t InterpolationSearch(const std::vector<int>& arr, int target)
	{
		if (arr.size() < 1)
			return arr.size();

		return InterpolationSearch(arr, target, 0, arr.size());
	}
}
