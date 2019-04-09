#include <iostream>
#include "test1.h"
#include <vector>
#include <assert.h>
#include <math.h>
using namespace std;


//��� ������������� ������ � ����� ����� k. ��������� ����� ������, ���������� ������ ������ �������� ��������� �������, ������������� k.
std::vector<int> MoreThenK(std::vector<int> v, int k)
{
	vector<int> res;
	for (int x : v)
		if (x % 2 == 0 && x > k)
			res.emplace_back(x);
	return res;
}

//��������� �������� ������� ����������, ���������� ��������� ������ �������� ������� (�.�. ���������� ������ �� ���� � �� �������) �� ��������� [0,N].
void Eratosthenes(std::vector<int>& v, int n)
{
	int *a = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		a[i] = i;
	for (int p = 2; p < n + 1; p++)
	{
		if (a[p] != 0)
		{
			v.emplace_back(a[p]);
			for (int j = p * p; j < n + 1; j += p)
				a[j] = 0;
		}
	}
}

//��������� ����� ������� ����� � ������, ����������� �������� ����� K. ���� ������ ����� ���, �� ������� ����.
int FirstPowK(int k, std::vector<int> v)
{
	assert(k > 0);
	int res = 0;
	int i = 0;
	int b = 0;
	while (v[i] != 0)
	{
		int a = v[i];
		while (a != 1)
		{
			b += a % k;
			a /= k;
		}
		if (b == 0)
		{
			res = i + 1;
			break;
		}
		b = 0;
		i++;
	}
	return res;
}

//���� N � ������ �������������� ����� ������� N. ��������� ����� ������, ���������� �������� �������� x1*y1,...xs*ys, ��� x1,...xp - ������������� �������� ��������� �������,
//������ � ������ ������� ����������, y1,...yq - ��������������� �������� ��������� �������, ������ � �������� ������� ����������, s= min{p,q}.
std::vector<double>  MyNewVec(int n, std::vector<double> v)
{
	vector<double> res;
	vector<double> x;
	vector<double> y;
	for (double a : v)
		if (a < 0)
			x.emplace_back(a);
	for (int i = n-1 ; i >= 0 ; i--)
		if (v[i] >= 0)
			y.emplace_back(v[i]);
	int min = y.size();
	if (x.size() < min)
		min = x.size();
	for (int i = 0; i < min ; i++)
		res.emplace_back(x[i]*y[i]);
	return res;
}

//���� ������ S, S0 � ����� ����� k. ����������, ������� �� � ������ S ��� ������� k ��������� ��������� S0.
bool HowMuchS0inS(string s, string s0, int k)
{
	bool res;
	int count = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == s0[0])
			if (s.substr(i, s0.length()) == s0)
			{
				count++;
				i += s0.length() - 1;
			}
	res = count >= k;
	return res;
}