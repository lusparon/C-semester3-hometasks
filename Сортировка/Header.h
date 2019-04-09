#ifndef Header_h
#define Header_h
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

//проверяет, что it находится в диапазоне [beg,end)
template<typename It>
bool in_range(It beg, It end, It it)
{
	while (beg != end)
	{
		if (it == beg)
			return true;
		beg++;
	}
	return false;
}

// возвращает случайный итератор в диапазоне [beg,end)
template<typename It>
It random_it(It beg, It end)
{
	return next(beg, rand() % distance(beg, end)-1 + 1);
}

// выполняет циклический сдвиг элементов диапазона [beg,end) на k элементов вправо
template<typename It>
void shift_right(It begin, It end, size_t k)
{
	rotate(begin, begin+k, end);
}

//Сортировка вставками
template<typename It, typename Comparator = std::less<>>
void ins_sort(It beg, It end, Comparator comp = Comparator{})
{
	for (auto it = beg; it < end; it++)
	{
		rotate(upper_bound(beg,it,*it,comp),it,next(it));
	}
}

//
template<typename It>
void quick_sort(It beg, It end)
{
	if (distance(beg, end) < 2) return;
	auto pivot = next(beg, distance(beg, end) / 2);
	nth_element(beg, pivot, end);
	quick_sort(beg, pivot);
	quick_sort(pivot, end);
}


#endif Header_h

