#pragma once

namespace algorithm
{
	template<class T>
	const T& Min(const T& a, const T& b)
	{
		return (a <= b) ? a : b;
	}

	template<class T>
	const T& Max(const T& a, const T& b)
	{
		return (a > b) ? a : b;
	}

	template<class T>
	void Swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	namespace compare
	{
		template<class T>
		struct CompareFunctor
		{
			virtual bool operator()(const T& ls, const T& rs) = 0;
		};

		template<class T>
		struct Less : public CompareFunctor<T>
		{
			bool operator()(const T& ls, const T& rs)
			{
				return ls < rs;
			}
		};

		template<class T>
		struct Greater : public CompareFunctor<T>
		{
			bool operator()(const T& ls, const T& rs)
			{
				return ls > rs;
			}
		};
	}
}