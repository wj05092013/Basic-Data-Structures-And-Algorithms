#include "SelectionSort.h"

namespace algorithm
{
	void SelectionSort(std::vector<int>& arr, compare::CompareFunctor<int>&& comp)
	{
		int selected_idx = 0;

		for (size_t i = 0; i + 1 < arr.size(); ++i)
		{
			selected_idx = i;

			for (size_t j = i + 1; j < arr.size(); ++j)
			{
				if (comp(arr[j], arr[selected_idx]))
					selected_idx = j;
			}

			if(i != selected_idx)
				Swap(arr[i], arr[selected_idx]);
		}
	}
}
