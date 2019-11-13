#pragma once

namespace math
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
}