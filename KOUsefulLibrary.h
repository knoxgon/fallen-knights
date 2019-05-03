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

	class RandomizeAndRetrieve {
	public:
		/*
		*		std::vector<std::unique_ptr<Gear>>::iterator
		*							T
		*/
		template<class T>
		static KOLIBRARY_API T randomSelection(T begin, T end, std::mt19937& ran);

		/*
		*				std::vector<std::vector<std::unique_ptr<Gear>>::iterator>
		*										T
		*						std::vector<std::unique_ptr<Gear>>::iterator
		*										Y
		*
		*/
		template<class T, class Y>
		static KOLIBRARY_API T _randomSelection(Y& begin, Y& end, std::size_t amount);
	};
	template<class T>
	inline KOLIBRARY_API T RandomizeAndRetrieve::randomSelection(T begin, T end, std::mt19937 & ran)
	{
		std::uniform_int_distribution<> dist(0, std::distance(begin, end) - 1);
		std::advance(begin, dist(ran));
		return begin;
	}
	template<class T, class Y>
	inline KOLIBRARY_API T RandomizeAndRetrieve::_randomSelection(Y & begin, Y & end, std::size_t amount)
	{
		T it;
		std::random_device randDev;
		std::mt19937 gen(randDev());
		T::iterator last;

		for (std::size_t i = 0; i < amount; i++) {
			it.push_back(randomSelection(begin, end, gen));
			std::sort(it.begin(), it.end());
			last = std::unique(it.begin(), it.end());
			if (last != it.end()) {
				it.erase(last, it.end());
				i--;
			}
		}
		return it;
	}
}