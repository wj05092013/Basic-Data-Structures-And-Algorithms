#include "Hash.h"
#include "Algorithm.h"

namespace data_structure
{
	template<class DataType>
	inline Hash<DataType>::Hash(int base_size, bool b_auto_resize, float resize_percent) :
		b_auto_resize_(b_auto_resize),
		resize_percent_(resize_percent),
		data_count_(0),
		arr_(algorithm::PrimeNumberBiggerThan(base_size))
	{
		first_func_ = [](int key)->int {
			return key % Size();
		};

		second_func_ = [](int key)->int {
			return 1 + (key%);
		};
	}

	template<class DataType>
	inline Hash<DataType>::Hash(int size, std::function<int(int)> first, std::function<int(int)> second, bool b_auto_resize, float resize_percent) :
		b_auto_resize_(b_auto_resize),
		resize_percent_(resize_percent),
		data_count_(0),
		arr_(size),
		first_func_(first),
		second_func_(second)
	{
	}

	template<class DataType>
	void Hash<DataType>::Clear()
	{
		for (int i = 0; i < arr_.size(); ++i)
		{
			arr_[i].status = ESlotStatus::eEmpty;
		}
	}

	template<class DataType>
	inline void Hash<DataType>::Insert(int key, const DataType& data)
	{
		if (b_auto_resize_)
		{
			if (static_cast<float>(Count()) / Size() > resize_percent_)
				Resize(algorithm::PrimeNumberBiggerThan(2 * Size()));
		}

		// Get initial position.
		int idx = first_func_(key);
		idx = GetWithinRangeIdx(idx);
		
		// Check next positions.
		while (arr_[idx].status == ESlotStatus::eInuse)
		{
			idx += second_func_(key);
			GetWithinRangeIdx(idx);
		}

		arr_[idx] = { key, ESlotStatus::eInuse, data };

		++data_count_;
	}

	template<class DataType>
	inline void Hash<DataType>::Erase(int key)
	{
		int idx = first_func_(key);
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

			idx = second_func_(key);
			idx = GetWithinRangeIdx(idx);
		}
	}

	template<class DataType>
	inline const DataType& Hash<DataType>::Find(int key) const
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
	}

	template<class DataType>
	inline DataType& Hash<DataType>::Find(int key)
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
	}

	template<class DataType>
	inline int Hash<DataType>::Count() const
	{
		return 0;
	}

	template<class DataType>
	inline int Hash<DataType>::Size() const
	{
		return arr_.size();
	}

	template<class DataType>
	inline void Hash<DataType>::Resize(int size)
	{
	}

	template<class DataType>
	inline const DataType& Hash<DataType>::Get(int key) const
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
	}

	template<class DataType>
	inline const DataType& Hash<DataType>::operator[](int key) const
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
	}

	template<class DataType>
	inline DataType& Hash<DataType>::operator[](int key)
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
	}

	template<class DataType>
	inline int Hash<DataType>::GetWithinRangeIdx(int idx) const
	{
		int size = static_cast<int>(arr_.size());

		while (idx >= size)
			idx -= size;
		return idx;
	}
}
