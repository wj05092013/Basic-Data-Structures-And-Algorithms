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

	int PrimeNumberSmallerThan(int n)
	{
		if (n <= 2)
			return -1;

		int i = n - 1;
		while (!IsPrimeNumber(i)) { --i; }
		return i;
	}

	int PrimeNumberBiggerThan(int n)
	{
		int i = n + 1;
		while (!IsPrimeNumber(i)) { ++i; }
		return i;
	}

	bool IsPrimeNumber(int n)
	{
		double root_n = sqrt(n);
		for (int i = 2; static_cast<double>(i) < root_n; ++i)
		{
			if (n % i == 0)
				return false;
		}
		return true;
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