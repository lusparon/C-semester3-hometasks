#ifndef iterator_h
#define iterator_h
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

// ������������ ������� ����� � ������ �������� ����������� ���������.
template<typename It>
void my_rotate(It begin, It end)
{
	rotate(begin, next(begin, distance(begin, end) / 2), end);
}

//��� ������ ����� ����� L, ���������� ��� �������������, ��� � ������������� ��������.
//�������� ������� ������� ����� ������� �������������� �������� � ����� ��������� ������������� ���������.
void insert_null(list<int>& l);

// �������� �������� ��������� [beg, end), ��������������� ��������� s ������ ������� p
template<typename It , typename UnPred>
void gather(It beg, It end, It p, UnPred s)
{
	stable_partition(beg,p, [=](typename std::iterator_traits<It>::value_type c) {return !s(c);});
	stable_partition(next(p), end, s);
}

// ������� ����� ��������� ������� ���������  � ��������� ���������� �������� init
template<typename T,typename It>
T sum(It beg, It end, T const & init)
{
	T res = init;
	for_each(beg, end, [&](T t) {res += t;});
	return res;
}

template<typename It>
auto sum(It beg, It end) //-> decltype(*beg) 
{
	typedef decltype(*beg) RRconst;
	typedef typename std::remove_reference<RRconst>::type Res;
	return sum(beg, end, Res());
}

template<typename T>
T sum(initializer_list<T> il)
{
	return sum(il.begin(), il.end());
}


#endif iterator_h

