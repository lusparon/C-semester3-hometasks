#ifndef Header_h
#define Header_h
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

//���������, ��� it ��������� � ��������� [beg,end)
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

// ���������� ��������� �������� � ��������� [beg,end)
template<typename It>
It random_it(It beg, It end)
{
	return next(beg, rand() % distance(beg, end)-1 + 1);
}

// ��������� ����������� ����� ��������� ��������� [beg,end) �� k ��������� ������
template<typename It>
void shift_right(It begin, It end, size_t k)
{
	rotate(begin, begin+k, end);
}

//���������� ���������
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

