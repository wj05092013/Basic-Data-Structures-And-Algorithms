#pragma once

#include <vector>
#include "Algorithm.h"

namespace algorithm
{
	void SelectionSort(std::vector<int>& arr, compare::CompareFunctor<int>&& comp);
}
