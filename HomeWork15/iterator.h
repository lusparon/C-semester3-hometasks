#ifndef iterator_h
#define iterator_h
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

// переставл€ет местами левую и правую половину переданного диапазона.
template<typename It>
void my_rotate(It begin, It end)
{
	rotate(begin, next(begin, distance(begin, end) / 2), end);
}

//ƒан список целых чисел L, содержащий как отрицательные, так и положительные элементы.
//¬ставить нулевой элемент после первого отрицательного элемента и перед последним положительным элементом.
void insert_null(list<int>& l);

// собирает элементы диапазона [beg, end), удовлетвор€ющие предикату s вокруг позиции p
template<typename It , typename UnPred>
void gather(It beg, It end, It p, UnPred s)
{
	stable_partition(beg,p, [=](typename std::iterator_traits<It>::value_type c) {return !s(c);});
	stable_partition(next(p), end, s);
}

// находит сумму элементов данного диапазона  с заданного стартового значени€ init
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

