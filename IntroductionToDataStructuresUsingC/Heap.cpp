#include "Heap.hpp"
#include "Math.h"

namespace data_structure
{
	const int Heap<class Compare>::kDefaultSize = 64;

	template<class Compare>
	Heap<Compare>::Heap() : 
		arr_(nullptr),
		end_idx_(0),
		arr_size_(kDefaultSize)
	{
		arr_ = new int[arr_size_] {};
	}

	template<class Compare>
	Heap<Compare>::Heap(int size) :
		arr_(nullptr),
		end_idx_(0)
	{
		arr_ = new int[size + 1];
	}

	template<class Compare>
	Heap<Compare>::~Heap()
	{
		Clear();
	}

	template<class Compare>
	void Heap<Compare>::Clear()
	{
	}

	template<class Compare>
	void Heap<Compare>::Push(int data)
	{
		// Resize the array if it needs.
		if (end_idx_ == arr_size_ - 1)
		{
			int size = math::Max(kDefaultSize, end_idx_ * 2);
			Resize(size);
		}
		
		++end_idx_;
		int curr = end_idx_;
		int parent = Parent(curr);

		// Find position to insert the 'data'.
		while (parent > 0 && compare_(data, arr_[parent]))
		{
			arr_[curr] = arr_[parent];

			curr = parent;
			parent = Parent(curr);
		}

		arr_[curr] = data;
	}

	template<class Compare>
	void Heap<Compare>::Pop()
	{
		int data = arr_[end_idx_];

		int curr = 1;
		int child = curr;
		int left_child_idx = 0;
		int right_child_idx = 0;

		while()
		{
			left_child_idx = LChild(curr);
			right_child_idx = RChild(curr);

			// If the current node has 2 children.
			if (right_child_idx <= end_idx_)
			{
				int child_idx = right_child_idx;

				if (compare_(arr_[left_child_idx], arr_[right_child_idx]))
					child_idx = left_child_idx;

				if (compare_(arr_[child_idx], data))
				{
					arr_[curr] = arr_[child_idx];
					curr = child_idx;
				}
			}
			// If the current node has just left child node.
			else if (left_child_idx == end_idx_)
			{

			}
		}

		--end_idx_;
	}

	template<class Compare>
	int Heap<Compare>::Top() const
	{
		return arr_[1];
	}

	template<class Compare>
	int Heap<Compare>::Size() const
	{
		return end_idx_ - 1;
	}

	template<class Compare>
	void Heap<Compare>::Resize(int size)
	{
		int* resized = new int[size] {};
		
		for (int = 1; i <= end_idx_; ++i)
			resized[i] = arr_[i];

		delete[]arr_;
		arr_ = resized;
	}

	template<class Compare>
	int Heap<Compare>::Parent(int idx)
	{
		return idx / 2;
	}

	template<class Compare>
	int Heap<Compare>::LChild(int idx)
	{
		return idx * 2;
	}

	template<class Compare>
	int Heap<Compare>::RChild(int idx)
	{
		return idx * 2 + 1;
	}
}