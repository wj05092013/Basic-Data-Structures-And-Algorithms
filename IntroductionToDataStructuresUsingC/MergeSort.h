#pragma once

#include <vector>
#include "Algorithm.h"

namespace algorithm
{
	void MergeSort(std::vector<int>& arr, compare::CompareFunctor<int>&& comp);
}
