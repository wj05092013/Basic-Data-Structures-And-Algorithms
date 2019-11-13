#pragma once

#include <vector>
#include "Compare.h"

namespace data_structure
{
	// Default is Min-Heap.
	template<class Compare = compare::Less<int>>
	class Heap
	{
	public:
		Heap();
		Heap(int size);
		~Heap();

		void Clear();

		void Push(int data);
		void Pop();
		int Top() const;

		int Size() const;
		void Resize(int size);

	private:
		int Parent(int idx);
		int LChild(int idx);
		int RChild(int idx);

		static const int kDefaultSize;

		Compare compare_;

		int* arr_;
		int end_idx_;
		int arr_size_;
	};
}
