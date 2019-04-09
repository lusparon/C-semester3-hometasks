#ifndef PRINT_VECT_H
#define PRINT_VECT_H

#include <iostream>
#include <vector>

// замечание: шаблоны функций всегда размещаются в заголовочных файлах
//            в отличие от обычных функций

// шаблон функции печати вектора
template<typename T>
void print_vector(const std::vector<T>& v, char delim = ' ')
{
	for (auto x : v)
		std::cout << x << delim;
}

/* #ifndef PRINT_VECT_H: */
#endif