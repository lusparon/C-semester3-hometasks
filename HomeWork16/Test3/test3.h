//������� 1
#ifndef test3_h
#define test3_h
#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <map>
#include <algorithm>
#include <assert.h>
using namespace std;

//������� 1.����������� ������ ������� �� �������� �������� . 
void inc_on_n(vector<int> & v, int n);

//������� 2.�� ������� ������ ������������ �����  � ������ �������������� �����  ���������� ������, ���� ������ �������� ���� �� ���� �������, 
//������ �������� ����������� ����� a, � ���� � ��������� ������. ��� ������� ������ ������� ���������� ����. 
bool contains_abs_more_than_a(list<double> l, int a);

//������� 3.�� ������� ������ ��������� ���� T � ������� ��������� ���������� ���������-���� Pred ���������� �����������  ��������� T � int,
//� ������� ���������� ���������� ��������� ������� �������� ������, ���������������� ��������� Pred. 
template<typename T, typename Pred>
map<T, int> list_to_map(list<T> l, Pred pred)
{
	map<T, int> res;
	for (auto x = l.begin(); x != l.end(); ++x)
		if (pred(*x))
		{
			if (res.find(*x) == res.end())
				res[*x] = 1;
			else
				++res[*x];
		}

	return res;
}

//������� 4.���������� ��������
template<typename It>
void merge_sort(It beg, It end)
{
	auto dis = distance(beg, end);
	if (dis == 0) return;
	if (dis == 1) return;
	auto n = next(beg, dis / 2);
	merge_sort(n, end);
	merge_sort(beg, n);
	inplace_merge(beg, n, end);
}

#endif test3_h