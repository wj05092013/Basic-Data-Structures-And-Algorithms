#include "PriorityQueue.h"
#include "Math.h"

namespace data_structure
{
	template<class Compare>
	const int PriorityQueue<Compare>::kDefaultSize = 4;

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
			int size = math::Max(kDefaultSize + 1, end_idx_ * 2);
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
	void PriorityQueue<Compare>::Pop()
	{
		int data = arr_[end_idx_];

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

				if (compare_(arr_[child_idx], data))
				{
					arr_[curr] = arr_[child_idx];
					curr = child_idx;
				}
			}
			// If the current node has just left child node.
			else if (left_child_idx == end_idx_)
			{
				if (compare_(arr_[left_child_idx], data))
				{
					arr_[curr] = arr_[left_child_idx];
					curr = left_child_idx;
				}
			}
			// If the current node has no child.
			else
				break;
		}

		arr_[curr] = data;
		--end_idx_;
	}

	template<class Compare>
	int PriorityQueue<Compare>::Top() const
	{
		return arr_[1];
	}

	template<class Compare>
	int PriorityQueue<Compare>::Size() const
	{
		return end_idx_ - 1;
	}

	template<class Compare>
	void PriorityQueue<Compare>::Reserve(int size)
	{
		int* resized = new int[size] {};
		
		for (int i = 1; i <= end_idx_; ++i)
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