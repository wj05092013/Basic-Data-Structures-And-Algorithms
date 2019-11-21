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

	// Use double hashing method.
	template<class DataType>
	class Hash
	{
	public:
		// It is recommended that size of hash table is a prime number.
		//  So, this constructor make the the table's size to a prime number bigger than 'base_size'.
		//  User can turn off the auto resization, but has to make sure that the table is not full in every insertion.
		Hash(int base_size, bool b_auto_resize = true, float resize_percent = 0.75f);

		// User can determine the table's size and hash functions.
		//  User can turn off the auto resization, but has to make sure that the table is not full in every insertion.
		Hash(int size, std::function<int(int)> first, std::function<int(int)> second, bool b_auto_resize = true, float resize_percent = 0.75f);

		void Clear();

		void Insert(int key, const DataType& data);
		void Erase(int key);
		const DataType& Find(int key) const;
		DataType& Find(int key);

		int Count() const;
		int Size() const;
		void Resize(int size);

		const DataType& Get(int key) const;
		const DataType& operator[](int key) const;
		DataType& operator[](int key);

	private:
		int GetWithinRangeIdx(int idx) const;

	private:
		bool b_auto_resize_;
		float resize_percent_;

		int data_count_;
		std::vector<HashSlot<DataType>> arr_;

		std::function<int(int)> first_func_;
		std::function<int(int)> second_func_;
	};
}
