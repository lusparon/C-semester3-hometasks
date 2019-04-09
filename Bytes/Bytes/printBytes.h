#ifndef printBytes_h
#define printBytes_h
#include "myTypes.h"
#include <iostream>
using namespace std;
//функция побайтовой печати переменной типа int
void printBytes(void * p);

//функция побайтовой печати переменной заданного типа:
void printBytes(void * p, Type t);

//функция побайтовой печати  массивов элементов заданного типа.
void printBytes(void * arr, int size, Type t);

//функция печати массива заданной длины с элементами произвольного типа:
template<typename T>
void printArray(T * arr, int size)
{
	for (int i = 0; i < size ; i++ )
	{
		cout << *(T*)arr << " ";
		arr++;
	}
	cout << endl;
}

//функция побайтовой печати заданной величины.
template<typename T>
void printBytes(T * x)
{
	unsigned char * pc = reinterpret_cast<unsigned char *>(x);
	for (int i = 0; i < sizeof(T); i++)
	{
		cout << (int*)*pc << " ";
		pc++;
	}
	cout << endl;
}


#endif printBytes_h
