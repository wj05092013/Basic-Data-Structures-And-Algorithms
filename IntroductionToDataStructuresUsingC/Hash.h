#pragma once

#include <vector>
#include <functional>

namespace data_structure
{
	enum ESlotStatus
	{
		eEmpty,
		eDeleted,
		eInuse
	};

	template<class DataType>
	struct HashSlot
	{
		int key;
		ESlotStatus status;
		DataType data;
	};

	template<class DataType>
	class Hash
	{
	public:
		inline Hash(int size) : arr_(size) {}

		inline void SetHashFunc(std::function<int(int)> first, std::function<int(int)> second);

		void Clear();

		void Insert(int key, const DataType& data);
		void Erase(int key);

		int Count() const;
		int Size() const;
		void Resize() const;

		const DataType& Get(int key) const;
		const DataType& operator[](int key) const;
		DataType& operator[](int key);

	private:
		std::vector<HashSlot<DataType>> arr_;

		std::function<int(int)> first_func_;
		std::function<int(int)> second_func_;
	};
}
