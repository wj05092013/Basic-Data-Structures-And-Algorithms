#include "HashTable.h"
#include "Algorithm.h"

namespace data_structure
{
	template<class DataType>
	const float HashTable<DataType>::kRehashPercent = 0.75f;

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
		for (int i = 0; i < arr_.size(); ++i)
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
			GetWithinRangeIdx(idx);
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
	inline const DataType& HashTable<DataType>::Find(int key) const
	{
		ind idx = hasher_1_(key);
		idx = GetWithinRangeIdx(idx);

		while (true)
		{
			if (arr_[idx].status == ESlotStatus::eInuse)
			{
				if (arr_[idx].key == key)
					return arr_[idx].data;
			}
			else if(arr_[idx].status == ESlotStatus::eEmpty)
				
		}
	}

	template<class DataType>
	inline DataType& HashTable<DataType>::Find(int key)
	{
		return const_cast<DataType&>(static_cast<const HashTable<DataType>*>(this)->Find(key));
	}

	template<class DataType>
	inline int HashTable<DataType>::Size() const
	{
		return 0;
	}

	template<class DataType>
	inline int HashTable<DataType>::SlotCount() const
	{
		return arr_.size();
	}

	template<class DataType>
	inline void HashTable<DataType>::Rehash(int minimum_size)
	{
	}

	template<class DataType>
	inline const DataType& HashTable<DataType>::Get(int key) const
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
	}

	template<class DataType>
	inline const DataType& HashTable<DataType>::operator[](int key) const
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
	}

	template<class DataType>
	inline DataType& HashTable<DataType>::operator[](int key)
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
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
