#pragma once
#include <vector>
#include <iostream>

namespace std {
	template<typename T>
	ostream& operator << (ostream &os, vector<T> const &v)
	{
		os << "{ ";
		auto it = v.begin();
		if (it != v.end()) {
			os << *it;
			for (++it; it != v.end(); ++it) {
				os << ", " << *it;
			}
		}
		os << " }";
		return os;
	}
}

class CSort
{
public:
	CSort() = default;
	~CSort() = default;

	template <bool bIsAscend = true, typename Ptr>
	void BubbleSort(Ptr begptr, Ptr endptr)
	{
		int nArrSize = endptr - begptr;
		int nLoopTime = nArrSize - 1;
		for (size_t i = 0; i < nLoopTime; i++)
		{
			bool bDidSwap = false;
			for (auto it = begptr; it != endptr - 1; it++)
			{
				if (bIsAscend) {
					if (*it > *(it+1)) {
						bDidSwap = true;
						swap(*it, *(it + 1));
					}
				}
				else {
					if (*it < *(it+1)) {
						bDidSwap = true;
						swap(*it, *(it + 1));
					}
				}
			}
			if (!bDidSwap) break;
			endptr--;
		}
		return;
	}

	template <bool bIsAscend = true, typename Ptr>
	void SelectSort(Ptr begptr, Ptr endptr)
	{
		for (auto it = begptr; it != endptr-1; it++)
		{
			bool bIsUpdate = false;
			auto SwapValue = *it; auto SwapIter = it;
			for (auto it_next = std::next(it); it_next != endptr; it_next++)
			{
				if (bIsAscend) {
					if (*it_next < SwapValue) {
						SwapValue = *it_next;
						SwapIter = it_next;
						bIsUpdate = true;
					}
				}
				else {
					if (*it_next > SwapValue) {
						SwapValue = *it_next;
						SwapIter = it_next;
						bIsUpdate = true;
					}
				}
			}
			if (bIsUpdate) swap(*it, *SwapIter);
		}
		return;
	}

private:
	template <typename T>
	void swap(T &_a, T &_b)
	{
		T temp = _a;
		_a = _b; _b = temp;
		return;
	}
};
