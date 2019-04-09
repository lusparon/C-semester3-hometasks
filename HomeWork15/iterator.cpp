#include "iterator.h"

//��� ������ ����� ����� L, ���������� ��� �������������, ��� � ������������� ��������.
//�������� ������� ������� ����� ������� �������������� �������� � ����� ��������� ������������� ���������.
void insert_null(list<int>& l)
{
	auto iter = find_if(l.begin(), l.end(), [=](int i) {return i < 0;});
	l.insert(next(iter), 0);
	auto iter1 = std::find_if(l.rbegin(), l.rend(), [](int x) { return x > 0; }).base();
	l.insert(--iter1 , 0);
}