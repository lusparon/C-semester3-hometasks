#include <iostream>
#include "swap.h"
using namespace std;

//переставляет два значения данного типа t, переданных по указателям
void swap(void * a, void * b, Type t)
{
	int size = mySizeOf(t);
	char * x = reinterpret_cast<char *>(a);
	char * y = reinterpret_cast<char *>(b);
	for (int i = 0; i < size ; i++)
	{
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
		x++;
		y++;
	}
}

//функция обмена значений массивов элементов заданного типа.
void swap(void * arr1, void * arr2, int size ,  Type t)
{
	int size1 = mySizeOf(t);
	char * x = reinterpret_cast<char *>(arr1);
	char * y = reinterpret_cast<char *>(arr2);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			*x ^= *y;
			*y ^= *x;
			*x ^= *y;
			x++;
			y++;
		}
	}
}