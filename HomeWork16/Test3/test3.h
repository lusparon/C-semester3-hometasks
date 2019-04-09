//Вариант 1
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

//Задание 1.Увеличивает каждый элемент на заданную величину . 
void inc_on_n(vector<int> & v, int n);

//Задание 2.По данному списку вещественных чисел  и целому положительному числу  возвращает истину, если список содержит хотя бы один элемент, 
//модуль которого превосходит число a, и ложь в противном случае. Для пустого списка функция возвращает ложь. 
bool contains_abs_more_than_a(list<double> l, int a);

//Задание 3.По данному списку элементов типа T и данному предикату шаблонного параметра-типа Pred возвращает отображение  элементов T в int,
//в котором подсчитано количество вхождений каждого элемента списка, удовлетворяющего предикату Pred. 
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

//Задание 4.Сортировка слиянием
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