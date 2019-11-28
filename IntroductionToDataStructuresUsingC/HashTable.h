#pragma once

#include <vector>
#include <functional>
#include "Iterator.h"

namespace data_structure
{
	enum ESlotStatus
	{
		eEmpty = 0,
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
	class HashTableIterator : public IteratorBase
	{
	public:
		HashTableIterator();
		HashTableIterator(const std::vector<HashSlot<DataType>>* arr, int idx);
		
		HashTableIterator& operator++();
		HashTableIterator operator++(int);
		HashTableIterator& operator--();
		HashTableIterator operator--(int);

		DataType& operator*();
		const DataType& operator*() const;

		bool operator==(const HashTableIterator& other) const;
		bool operator!=(const HashTableIterator& other) const;

	protected:
		int idx_;
		std::vector<HashSlot<DataType>>* arr_;
	};

	template<class DataType>
	class ConstHashTableIterator : public HashTableIterator<DataType>
	{
	public:
		ConstHashTableIterator();
		ConstHashTableIterator(const std::vector<HashSlot<DataType>>* arr, int idx);

		ConstHashTableIterator& operator++();
		ConstHashTableIterator operator++(int);
		ConstHashTableIterator& operator--();
		ConstHashTableIterator operator--(int);

		const DataType& operator*() const;
	};

	// Open addressing hash table using double hashing method.
	template<class DataType>
	class HashTable
	{
	public:
		/*
			It is recommended that size of hash table is a prime number.
				So, these constructors make the the table's size to a prime number bigger than or equal to 'minimum_size'.
		*/

		HashTable(int minimum_size);
		HashTable(int minimum_size, std::function<int(int)> hasher_1, std::function<int(int)> hasher_2);

		void Clear();

		bool Insert(int key, const DataType& data);
		void Erase(int key);
		
		// Return the number of elements stored in this table.
		int Size() const;

		// Return the capacity of this table.
		int SlotCount() const;

		// Only expand the capacity of this table.
		void Rehash(int minimum_size);

		const DataType& operator[](int key) const;
		DataType& operator[](int key);

		/*
			The iterator doesn't guarantee any type of orders of data elements.
			 The order of elements is the same as the order in the array.
		*/

		ConstHashTableIterator<DataType> Find(int key) const;
		HashTableIterator<DataType> Find(int key);

		ConstHashTableIterator<DataType> Begin() const;
		HashTableIterator<DataType> Begin();
		ConstHashTableIterator<DataType> End() const;
		HashTableIterator<DataType> End();

	private:
		// Recalculate index if the input 'idx' is out of range.
		int GetWithinRangeIdx(int idx) const;

	private:
		static const float kRehashPercent;

		int data_count_;
		std::vector<HashSlot<DataType>> arr_;

		std::function<int(int)> hasher_1_;
		std::function<int(int)> hasher_2_;
	};
}
