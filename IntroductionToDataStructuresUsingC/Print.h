#pragma once

#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "Set.h"

namespace print
{
	void PrintArray(const std::vector<int>& arr);
	void PrintLinkedList(const data_structure::List& list);
	void PrintSet(const data_structure::Set& set);
}