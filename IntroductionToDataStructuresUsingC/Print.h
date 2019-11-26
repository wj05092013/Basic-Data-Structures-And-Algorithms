#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.h"
#include "Set.h"
#include "HashTable.hpp"

namespace print
{
	void PrintArray(const std::vector<int>& arr);
	void PrintLinkedList(const data_structure::List& list);
	void PrintSet(const data_structure::Set& set);
	void PrintHashTable(const data_structure::HashTable<std::string>& table);
}