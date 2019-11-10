#include "Print.h"

namespace print
{
	void PrintArray(const std::vector<int>& arr)
	{
		for (size_t i = 0; i < arr.size(); ++i)
		{
			std::cout << arr[i] << " ";
		}
	}

	void PrintLinkedList(const data_structure::LinkedList& list)
	{
		for (auto iter = list.Begin(); iter != list.End(); ++iter)
		{
			std::cout << *iter << " ";
		}
	}
}