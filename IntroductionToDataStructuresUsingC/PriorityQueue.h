#pragma once

#include <vector>
#include "Algorithm.h"
#include "Iterator.h"

namespace data_structure
{
	class ConstPriorityQueueIterator : public IteratorBase
	{
	public:
		ConstPriorityQueueIterator(const int* arr, int node_idx) :
			arr_(arr),
			node_idx_(node_idx) {}

		inline ConstPriorityQueueIterator& operator++()
		{
			++node_idx_;
			return *this;
		}

		inline ConstPriorityQueueIterator operator++(int)
		{
			int temp = node_idx_;
			++node_idx_;
			return ConstPriorityQueueIterator(arr_, temp);
		}

		inline ConstPriorityQueueIterator& operator--()
		{
			--node_idx_;
			return *this;
		}

		inline ConstPriorityQueueIterator operator--(int)
		{
			int temp = node_idx_;
			--node_idx_;
			return ConstPriorityQueueIterator(arr_, temp);
		}

		inline const int& operator*() const
		{
			return arr_[node_idx_];
		}

		inline bool operator==(const ConstPriorityQueueIterator& other) const
		{
			return node_idx_ == other.node_idx_;
		}

		inline bool operator!=(const ConstPriorityQueueIterator& other) const
		{
			return node_idx_ != other.node_idx_;
		}

	private:
		const int* arr_;
		int node_idx_;
	};

	// Priority Queue is implemented using the Heap implementation method.
	//	Default is Min-Heap.
	template<class Compare = algorithm::compare::Less<int>>
	class PriorityQueue
	{
	public:
		PriorityQueue();
		PriorityQueue(int reserve_size);
		~PriorityQueue();

		void Clear();

		void Push(int data);
		int Pop();
		int Top() const;

		int Size() const;
		int Capacity() const;
		void Reserve(int size);

		inline ConstPriorityQueueIterator Begin() const
		{
			return ConstPriorityQueueIterator(arr_, 1);
		}

		inline ConstPriorityQueueIterator End() const
		{
			return ConstPriorityQueueIterator(arr_, end_idx_ + 1);
		}

	private:
		int Parent(int idx);
		int LChild(int idx);
		int RChild(int idx);

		Compare compare_;

		int* arr_;
		int end_idx_;
		int arr_size_;

		static const int kDefaultSize;
	};
}