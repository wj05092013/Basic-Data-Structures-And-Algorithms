#pragma once

#include <vector>
#include "Compare.h"

namespace data_structure
{
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

	private:
		void Resize();

		int Parent(int idx);
		int LChild(int idx);
		int RChild(int idx);

		static const int kMinSize;

		int* arr_;
		int size_;
	};
}
