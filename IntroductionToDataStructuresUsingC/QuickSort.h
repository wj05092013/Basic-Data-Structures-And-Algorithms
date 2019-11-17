#pragma once

#include <vector>
#include "Algorithm.h"

namespace algorithm
{
	void QuickSort(std::vector<int>& arr, compare::CompareFunctor<int>&& comp);
}
