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

	// Open addressing hash table using double hashing method.
	template<class DataType>
	class HashTable
	{
	public:
		// It is recommended that size of hash table is a prime number.
		//  So, this constructor make the the table's size to a prime number bigger than or equal to 'minimum_size'.
		HashTable(int minimum_size, std::function<int(int)> hasher_1, std::function<int(int)> hasher_2);

		void Clear();

		bool Insert(int key, const DataType& data);
		void Erase(int key);
		const DataType& Find(int key) const;
		DataType& Find(int key);

		int Size() const;
		int SlotCount() const;
		void Rehash(int minimum_size);

		const DataType& Get(int key) const;
		const DataType& operator[](int key) const;
		DataType& operator[](int key);

	private:
		int GetWithinRangeIdx(int idx) const;

	private:
		static const float kRehashPercent;

		int data_count_;
		std::vector<HashSlot<DataType>> arr_;

		std::function<int(int)> hasher_1_;
		std::function<int(int)> hasher_2_;
	};
}
