#include "iterator.h"

//Дан список целых чисел L, содержащий как отрицательные, так и положительные элементы.
//Вставить нулевой элемент после первого отрицательного элемента и перед последним положительным элементом.
void insert_null(list<int>& l)
{
	auto iter = find_if(l.begin(), l.end(), [=](int i) {return i < 0;});
	l.insert(next(iter), 0);
	auto iter1 = std::find_if(l.rbegin(), l.rend(), [](int x) { return x > 0; }).base();
	l.insert(--iter1 , 0);
}