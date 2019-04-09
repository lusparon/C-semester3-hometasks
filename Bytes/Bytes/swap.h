#ifndef swap_h
#define swap_h
#include "myTypes.h";
//������������ ��� �������� ������� ���� t, ���������� �� ����������
void swap(void * a, void * b, Type t);

//������� ������ �������� �������� ��������� ��������� ����.
void swap(void * arr1, void * arr2, int size ,  Type t);

template<typename T>
void swapByRef(T & a, T & b) {
	T aCopy = a;
	a = b;
	b = aCopy;
}

template<typename T>
void swapByPtr(T * a, T * b)
{
	T x = *(T*)a;
	*(T*)a = *(T*)b;
	*(T*)b = x;
}

//������ ������� ������ ���� �������� ���������� �� ������
template<typename T>
void swapByRef2(T & a, T & b) {
	char * x = reinterpret_cast<char *>(&a);
	char * y = reinterpret_cast<char *>(&b);
	for (int i = 0; i < sizeof(T); i++)
	{
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
		x++;
		y++;
	}
}

#endif swap_h
