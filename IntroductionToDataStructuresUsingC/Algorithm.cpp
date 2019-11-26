#include <iostream>
#include "Algorithm.h"

namespace algorithm
{
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
}