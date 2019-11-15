#pragma once

#include "PriorityQueue.h"
#include "Math.h"

namespace data_structure
{
	template<class Compare>
	const int PriorityQueue<Compare>::kDefaultSize = 64;

	template<class Compare>
	PriorityQueue<Compare>::PriorityQueue() : 
		arr_(nullptr),
		end_idx_(0),
		arr_size_(kDefaultSize + 1)
	{
		arr_ = new int[arr_size_] {};
	}

	template<class Compare>
	PriorityQueue<Compare>::PriorityQueue(int reserve_size) :
		arr_(nullptr),
		end_idx_(0)
	{
		arr_size_ = reserve_size + 1;
		arr_ = new int[arr_size_];
	}

	template<class Compare>
	PriorityQueue<Compare>::~PriorityQueue()
	{
		Clear();

		delete[]arr_;
	}

	template<class Compare>
	void PriorityQueue<Compare>::Clear()
	{
		end_idx_ = 0;
	}

	template<class Compare>
	void PriorityQueue<Compare>::Push(int data)
	{
		// Resize the memory if it needs.
		if (end_idx_ == arr_size_ - 1)
		{
			int size = algorithm::Max(kDefaultSize, end_idx_ * 2);
			Reserve(size);
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
	int PriorityQueue<Compare>::Pop()
	{
		int pop_data = arr_[1];
		int end_data = arr_[end_idx_];

		int curr = 1;
		int left_child_idx = 0;
		int right_child_idx = 0;

		while (true)
		{
			left_child_idx = LChild(curr);
			right_child_idx = RChild(curr);

			// If the current node has 2 children.
			if (right_child_idx <= end_idx_)
			{
				int child_idx = right_child_idx;
				if (compare_(arr_[left_child_idx], arr_[right_child_idx]))
					child_idx = left_child_idx;

				if (compare_(arr_[child_idx], end_data))
				{
					arr_[curr] = arr_[child_idx];
					curr = child_idx;
				}
				else
					break;		// Found new position.
			}
			// If the current node has just left child node.
			else if (left_child_idx == end_idx_)
			{
				if (compare_(arr_[left_child_idx], end_data))
				{
					arr_[curr] = arr_[left_child_idx];
					curr = left_child_idx;
				}
				else
					break;		// Found new position.
			}
			// If the current node has no child.
			else
				break;
		}

		arr_[curr] = end_data;
		--end_idx_;

		return pop_data;
	}

	template<class Compare>
	int PriorityQueue<Compare>::Top() const
	{
		return arr_[1];
	}

	template<class Compare>
	int PriorityQueue<Compare>::Size() const
	{
		return end_idx_;
	}

	template<class Compare>
	inline int PriorityQueue<Compare>::Capacity() const
	{
		return arr_size_ - 1;
	}

	template<class Compare>
	void PriorityQueue<Compare>::Reserve(int size)
	{
		arr_size_ = size + 1;

		int* resized = new int[arr_size_] {};
		
		int end_idx = algorithm::Min(end_idx_, arr_size_ - 1);

		for (int i = 1; i <= end_idx; ++i)
			resized[i] = arr_[i];

		delete[]arr_;
		arr_ = resized;
	}

	template<class Compare>
	int PriorityQueue<Compare>::Parent(int idx)
	{
		return idx / 2;
	}

	template<class Compare>
	int PriorityQueue<Compare>::LChild(int idx)
	{
		return idx * 2;
	}

	template<class Compare>
	int PriorityQueue<Compare>::RChild(int idx)
	{
		return idx * 2 + 1;
	}
}