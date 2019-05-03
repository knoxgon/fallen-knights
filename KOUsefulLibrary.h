#pragma once
#include <string>
#include <random>

#ifdef KOLIBRARY_EXPORTS
#define KOLIBRARY_API __declspec(dllexport)
#else
#define KOLIBRARY_API __declspec(dllexport)
#endif

namespace UsefulLibrary {
	class KOLibrary {
	public:
		static KOLIBRARY_API void u_charestic_betweenRanges(int setStat, unsigned short& originalstat, const int maxValue, std::string errMsg);
		static KOLIBRARY_API void charestic_betweenRanges(int setStat, short& originalstat, const int maxValue, std::string errMsg);
		static KOLIBRARY_API bool compare_length(std::string const& lhs, std::string const& rhs);
		static KOLIBRARY_API int Random(int start, int end);
	};
}