#pragma once

namespace data_structure
{
	template<class DataType>
	class IIterator
	{
	public:
		virtual bool HasPrev() = 0;
		virtual bool HasNext() = 0;
		virtual IIterator<DataType>& GetPrev() = 0;
		virtual IIterator<DataType>& GetNext() = 0;
		virtual const IIterator<DataType>& GetPrev() const = 0;
		virtual const IIterator<DataType>& GetNext() const = 0;

		// operator·Î º¯°æ
	};
}
