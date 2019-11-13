#include "Heap.hpp"
#include "Math.h"

namespace data_structure
{
	const int Heap<class Compare>::kMinSize = 64;

	template<class Compare>
	Heap<Compare>::Heap() : 
		arr_(nullptr),
		size_(0)
	{
		arr_ = new int[kMinSize] {};
	}

	template<class Compare>
	Heap<Compare>::Heap(int size) :
		arr_(nullptr),
		size_(0)
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
		while

		++size_;
	}

	template<class Compare>
	void Heap<Compare>::Pop()
	{
	}

	template<class Compare>
	int Heap<Compare>::Top() const
	{
		return arr_[1];
	}

	template<class Compare>
	int Heap<Compare>::Size() const
	{
		return size_;
	}

	template<class Compare>
	void Heap<Compare>::Resize()
	{
		int size = 2 * math::Max(kMinSize, size_);
		int* resized = new int[size] {};
		
		for (int = 1; i <= size_; ++i)
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