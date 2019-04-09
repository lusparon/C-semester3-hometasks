//������� 1
#include "test3.h" 

//������� 1.����������� ������ ������� �� �������� �������� . 
void inc_on_n(vector<int> & v, int n) 
{
	transform(v.begin(), v.end(), v.begin(), [&](int a) { return a += n; });
}

//������� 2.�� ������� ������ ������������ �����  � ������ �������������� �����  ���������� ������, ���� ������ �������� ���� �� ���� �������, 
//������ �������� ����������� ����� a, � ���� � ��������� ������. ��� ������� ������ ������� ���������� ����. */
bool contains_abs_more_than_a(list<double> l, int a)
{
	if (l.empty())
		return false;
	return any_of(l.begin(), l.end(), [&](double x) { return fabs(x) > a; });
}



