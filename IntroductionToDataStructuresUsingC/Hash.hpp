#include "Hash.h"

namespace data_structure
{
	template<class DataType>
	inline void Hash<DataType>::SetHashFunc(std::function<int(int)> first, std::function<int(int)> second)
	{
		first_func_ = first;
		second_func_ = second;
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
		int idx = first_func_(key);
		
		if (arr_[idx].status == ESlotStatus::eInuse)
		{
			idx += second_func_(key);
			
			while (idx >= arr_.size())
				idx -= arr_.size();
		}
		else
		{
			arr_[idx] = { key, ESlotStatus::eInuse, data };
		}
	}

	template<class DataType>
	inline void Hash<DataType>::Erase(int key)
	{
	}

	template<class DataType>
	inline int Hash<DataType>::Count() const
	{
		return 0;
	}

	template<class DataType>
	inline int Hash<DataType>::Size() const
	{
		return 0;
	}

	template<class DataType>
	inline void Hash<DataType>::Resize() const
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
}
