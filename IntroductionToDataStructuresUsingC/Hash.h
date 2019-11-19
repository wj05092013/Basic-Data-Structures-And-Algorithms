#pragma once

#include <vector>

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

		inline void SetFirstHashFunc(int(*first_func)(int)) { first_func_ = first_func; }
		inline void SetSecondHashFunc(int(*second_func)(int)) { second_func_ = second_func; }

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




		// Functor로 만들기
		int(*first_func_)(int);
		int(*second_func_)(int);
	};
}
