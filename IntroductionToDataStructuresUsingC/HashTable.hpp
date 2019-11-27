#pragma once

#include "HashTable.h"
#include "Algorithm.h"

namespace data_structure
{
	//
	// HashTableIterator Class Template
	//

	template<class DataType>
	inline HashTableIterator<DataType>::HashTableIterator() :
		idx_(0),
		arr_(nullptr)
	{
	}

	template<class DataType>
	inline HashTableIterator<DataType>::HashTableIterator(const std::vector<HashSlot<DataType>>* arr, int idx) :
		arr_(const_cast<std::vector<HashSlot<DataType>>*>(arr)),
		idx_(idx)
	{
	}

	template<class DataType>
	inline HashTableIterator<DataType>& HashTableIterator<DataType>::operator++()
	{
		idx_ += 1;
		int size = static_cast<int>(arr_->size());

		while (idx_ < size && (*arr_)[idx_].status != ESlotStatus::eInuse)
			++idx_;
		
		return *this;
	}

	template<class DataType>
	inline HashTableIterator<DataType> HashTableIterator<DataType>::operator++(int)
	{
		HashTableIterator origin(*this);
		operator();
		return origin;
	}

	template<class DataType>
	inline HashTableIterator<DataType>& HashTableIterator<DataType>::operator--()
	{
		int curr_idx = idx_ - 1;

		while (curr_idx >= 0)
		{
			if ((*arr_)[curr_idx].status == ESlotStatus::eInuse)
			{
				idx_ = curr_idx;
				break;
			}
			--curr_idx;
		}
		return *this;
	}

	template<class DataType>
	inline HashTableIterator<DataType> HashTableIterator<DataType>::operator--(int)
	{
		HashTableIterator origin(*this);
		operator--();
		return origin;
	}

	template<class DataType>
	inline DataType& HashTableIterator<DataType>::operator*()
	{
		return (*arr_)[idx_].data;
	}

	template<class DataType>
	inline const DataType& HashTableIterator<DataType>::operator*() const
	{
		return (*arr_)[idx_].data;
	}

	template<class DataType>
	inline bool HashTableIterator<DataType>::operator==(const HashTableIterator& other) const
	{
		return idx_ == other.idx_;
	}

	template<class DataType>
	inline bool HashTableIterator<DataType>::operator!=(const HashTableIterator& other) const
	{
		return idx_ != other.idx_;
	}

	//
	// ConstHashTableIterator Class Template
	//

	template<class DataType>
	inline ConstHashTableIterator<DataType>::ConstHashTableIterator() :
		HashTableIterator<DataType>()
	{
	}

	template<class DataType>
	inline ConstHashTableIterator<DataType>::ConstHashTableIterator(const std::vector<HashSlot<DataType>>* arr, int idx) :
		HashTableIterator<DataType>(arr, idx)
	{
	}

	template<class DataType>
	inline ConstHashTableIterator<DataType>& ConstHashTableIterator<DataType>::operator++()
	{
		HashTableIterator<DataType>::operator++();
		return *this;
	}

	template<class DataType>
	inline ConstHashTableIterator<DataType> ConstHashTableIterator<DataType>::operator++(int)
	{
		ConstHashTableIterator<DataType> origin(*this);
		HashTableIterator<DataType>::operator++();
		return origin;
	}

	template<class DataType>
	inline ConstHashTableIterator<DataType>& ConstHashTableIterator<DataType>::operator--()
	{
		HashTableIterator<DataType>::operator--();
		return *this;
	}

	template<class DataType>
	inline ConstHashTableIterator<DataType> ConstHashTableIterator<DataType>::operator--(int)
	{
		ConstHashTableIterator<DataType> origin(*this);
		HashTableIterator<DataType>::operator--();
		return origin;
	}

	template<class DataType>
	inline const DataType& ConstHashTableIterator<DataType>::operator*() const
	{
		return HashTableIterator<DataType>::operator*();
	}

	//
	// HashTable Class Template
	//

	template<class DataType>
	const float HashTable<DataType>::kRehashPercent = 0.75f;

	template<class DataType>
	inline HashTable<DataType>::HashTable(int minimum_size) :
		data_count_(0),
		arr_(algorithm::PrimeNumberBiggerThan(minimum_size))
	{
		hasher_1_= [this](int key)->int {
			return key % static_cast<int>(SlotCount());
		};

		hasher_2_ = [](int key)->int {
			return 1 + (key % 13);
		};
	}

	template<class DataType>
	inline HashTable<DataType>::HashTable(int minimum_size, std::function<int(int)> hasher_1, std::function<int(int)> hasher_2) :
		data_count_(0),
		arr_(algorithm::PrimeNumberBiggerThan(minimum_size)),
		hasher_1_(hasher_1),
		hasher_2_(hasher_2)
	{
	}

	template<class DataType>
	void HashTable<DataType>::Clear()
	{
		int size = static_cast<int>(arr_.size());
		for (int i = 0; i < size; ++i)
		{
			arr_[i].status = ESlotStatus::eEmpty;
		}
	}

	template<class DataType>
	inline bool HashTable<DataType>::Insert(int key, const DataType& data)
	{
		// Add new slots if nescessary.
		if (static_cast<float>(Size()) / SlotCount() > kRehashPercent)
			Rehash(algorithm::PrimeNumberBiggerThan(2 * SlotCount()));

		// Get initial position.
		int idx = hasher_1_(key);
		idx = GetWithinRangeIdx(idx);
		
		// Check next positions.
		while (arr_[idx].status == ESlotStatus::eInuse)
		{
			if (arr_[idx].key == key)
				return false;

			idx += hasher_2_(key);
			idx = GetWithinRangeIdx(idx);
		}

		arr_[idx] = { key, ESlotStatus::eInuse, data };

		++data_count_;
		return true;
	}

	template<class DataType>
	inline void HashTable<DataType>::Erase(int key)
	{
		int idx = hasher_1_(key);
		idx = GetWithinRangeIdx(idx);

		while (true)
		{
			if (arr_[idx].status == ESlotStatus::eInuse)
			{
				// Found, then delete.
				if (arr_[idx].key == key)
				{
					arr_[idx].status = ESlotStatus::eDeleted;
					--data_count_;
					return;
				}
			}
			// There is no data which key is value of the 'key'.
			else if (arr_[idx].status == ESlotStatus::eEmpty)
				return;

			idx = hasher_2_(key);
			idx = GetWithinRangeIdx(idx);
		}
	}

	template<class DataType>
	inline ConstHashTableIterator<DataType> HashTable<DataType>::Find(int key) const
	{
		int idx = hasher_1_(key);
		idx = GetWithinRangeIdx(idx);

		while (true)
		{
			if (arr_[idx].status == ESlotStatus::eInuse)
			{
				if (arr_[idx].key == key)
					return ConstHashTableIterator<DataType>(&arr_, idx);
			}
			else if(arr_[idx].status == ESlotStatus::eEmpty)
				return End();

			idx += hasher_2_(key);
			idx = GetWithinRangeIdx(idx);
		}
	}

	template<class DataType>
	inline HashTableIterator<DataType> HashTable<DataType>::Find(int key)
	{
		return HashTableIterator<DataType>(static_cast<const HashTable<DataType>*>(this)->Find(key));
	}

	template<class DataType>
	inline int HashTable<DataType>::Size() const
	{
		return data_count_;
	}

	template<class DataType>
	inline int HashTable<DataType>::SlotCount() const
	{
		return static_cast<int>(arr_.size());
	}

	template<class DataType>
	inline void HashTable<DataType>::Rehash(int minimum_size)
	{
		int new_size = algorithm::PrimeNumberBiggerThan(minimum_size);
		if (new_size <= static_cast<int>(arr_.size()))
			return;

		int count = data_count_;
		std::vector<HashSlot<DataType>> temp(count);

		int i = 0;
		int j = 0;

		// Migrate slots which are in use to temporary array.
		while (i < data_count_)
		{
			while (arr_[j].status != ESlotStatus::eInuse)
				++j;

			temp[i] = arr_[j];
			++i;
			++j;
		}

		// Clear and resize the original array.
		arr_.clear();
		arr_.resize(new_size);
		data_count_ = 0;

		// Insert the data to the newly resized array.
		for (int k = 0; k < count; ++k)
			Insert(temp[k].key, temp[k].data);
	} 

	template<class DataType>
	inline const DataType& HashTable<DataType>::operator[](int key) const
	{
		return *Find(key);
	}

	template<class DataType>
	inline DataType& HashTable<DataType>::operator[](int key)
	{
		return *Find(key);
	}

	template<class DataType>
	inline ConstHashTableIterator<DataType> HashTable<DataType>::Begin() const
	{
		int idx = 0;
		while (idx < static_cast<int>(arr_.size()))
		{
			if (arr_[idx].status == ESlotStatus::eInuse)
				return ConstHashTableIterator<DataType>(&arr_, idx);
			++idx;
		}

		return End();
	}

	template<class DataType>
	inline HashTableIterator<DataType> HashTable<DataType>::Begin()
	{
		return HashTableIterator<DataType>(static_cast<const HashTable<DataType>*>(this)->Begin());
	}

	template<class DataType>
	inline ConstHashTableIterator<DataType> HashTable<DataType>::End() const
	{
		return ConstHashTableIterator<DataType>(&arr_, static_cast<int>(arr_.size()));
	}

	template<class DataType>
	inline HashTableIterator<DataType> HashTable<DataType>::End()
	{
		return HashTableIterator<DataType>(&arr_, static_cast<int>(arr_.size()));
	}

	template<class DataType>
	inline int HashTable<DataType>::GetWithinRangeIdx(int idx) const
	{
		int size = static_cast<int>(arr_.size());

		while (idx >= size)
			idx -= size;
		return idx;
	}
}
