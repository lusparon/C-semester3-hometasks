#include <iostream>
#include <vector>
#include <string>
#include "NormalAlgorifm.h"
using namespace std;


//��������� �������� ����� ����������� ��������� (������ �����������) � �������� ������ 
void Func(std::vector<NormSubs> v, string& s)
{
	int i = 0;
	while ( i < v.size() )
	{
		if (IsSubstr(v[i].s, s) != -1)
		{
			s.replace(IsSubstr(v[i].s, s), v[i].s.size(), v[i].p);
			if (v[i].f)
				break;
			i = 0;
		}
		else
		i++;
	}
}

//�������� �� s0 ���������� s .���� �� , ������� ������ ������� ��������� , ���� ��� ������� -1
int IsSubstr(string s0, string s)
{
	int res = -1;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == s0[0])
			if (s.substr(i, s0.length()) == s0)
			{
				res = i;
				break;
			}
	return res;
}
