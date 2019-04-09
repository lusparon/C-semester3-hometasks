#ifndef PRINT_VECT_H
#define PRINT_VECT_H

#include <iostream>
#include <vector>

// ���������: ������� ������� ������ ����������� � ������������ ������
//            � ������� �� ������� �������

// ������ ������� ������ �������
template<typename T>
void print_vector(const std::vector<T>& v, char delim = ' ')
{
	for (auto x : v)
		std::cout << x << delim;
}

/* #ifndef PRINT_VECT_H: */
#endif