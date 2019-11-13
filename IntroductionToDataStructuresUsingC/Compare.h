#pragma once

namespace data_structure
{
	namespace compare
	{
		template<class T>
		struct Less
		{
			bool operator()(const T& ls, const T& rs)
			{
				return ls < rs;
			}
		};

		template<class T>
		struct Greater
		{
			bool operator()(const T& ls, const T& rs)
			{
				return ls > rs;
			}
		};
	}
}