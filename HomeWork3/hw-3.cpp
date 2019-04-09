#include "hw-3.h"
using namespace std;

//������� ���������� �� ���������, ������� ����� ��� �������� �� 5
void HighAchievers(std::vector<Student> v)
{
	for (auto x : v)
		if (x.AverageMark() == 5.0)
			x.PrintStudent();
}

//������� ���������� �� ���������, ������� ����� ���� �� ���� 3
void HaveOne3(std::vector<Student> v)
{
	for (auto x : v)
		if (x.ReturnMark("Math") == 3 || x.ReturnMark("Russian") == 3 || x.ReturnMark("Literature") == 3 || x.ReturnMark("History") == 3 || x.ReturnMark("Physics") == 3 )
			x.PrintStudent();
}

//������� ���������� �� ���������, ������� ����� ���� �� ���� 2
void HaveOne2(std::vector<Student> v)
{
	for (auto x : v)
		if (x.ReturnMark("Math") == 2 || x.ReturnMark("Russian") == 2 || x.ReturnMark("Literature") == 2 || x.ReturnMark("History") == 2 || x.ReturnMark("Physics") == 2)
			x.PrintStudent();
}