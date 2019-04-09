#ifndef printBytes_h
#define printBytes_h
#include "myTypes.h"
#include <iostream>
using namespace std;
//������� ���������� ������ ���������� ���� int
void printBytes(void * p);

//������� ���������� ������ ���������� ��������� ����:
void printBytes(void * p, Type t);

//������� ���������� ������  �������� ��������� ��������� ����.
void printBytes(void * arr, int size, Type t);

//������� ������ ������� �������� ����� � ���������� ������������� ����:
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

//������� ���������� ������ �������� ��������.
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
