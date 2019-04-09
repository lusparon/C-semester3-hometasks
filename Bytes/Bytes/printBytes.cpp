#include <iostream>
#include "printBytes.h"
#include <assert.h>
using namespace std;

//������� ���������� ������ ���������� ���� int
void printBytes(void * p)
{
	unsigned char * pc = reinterpret_cast<unsigned char *>(p);
	for (int i = 0; i < sizeof(int); i++)
	{
		cout << (int*)*pc << " ";
		pc++;
	}
}

//������� ���������� ������ ���������� ��������� ����:
void printBytes(void * p, Type t)
{
	int size = mySizeOf(t);
	unsigned char * pc = reinterpret_cast<unsigned char *>(p);
	for (int i = 0; i < size; i++)
	{
		cout << (int*)*pc << " ";
		pc++;
	}
}

//������� ���������� ������  �������� ��������� ��������� ����.
void printBytes(void * arr, int size, Type t)
{
	int size1 = mySizeOf(t);
	unsigned char * pc = reinterpret_cast<unsigned char *>(arr);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			cout << (int*)*pc << " ";
			pc++;
		}
		cout << endl;
	}
}
