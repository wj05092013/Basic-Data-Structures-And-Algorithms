#pragma once

#include <vector>
#include "Algorithm.h"

namespace algorithm
{
	void InsertionSort(std::vector<int>& arr, compare::CompareFunctor<int>&& comp);
}
