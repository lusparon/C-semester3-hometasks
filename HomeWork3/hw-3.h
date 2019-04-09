#ifndef HW3_H
#define HW3_H
#include <iostream>
#include <map>
#include <assert.h>
#include <string>
#include <vector>
using namespace std;

//��������� �������
struct Student
{
	std::string Name; //��� �������� 
	int RegNum; //��������������� �����
	map <std::string, int> Subjects; //"�������� ����������" �  "������ ��������"

	//�����������
	Student(std::string name, int regnum)
	{
		Name = name;
		RegNum = regnum;
	}

	//���������� ������ �� ����������
	void AddMark(std::string DiscName, int mark)
	{
		assert(mark  >= 1 && mark <= 5);
		Subjects[DiscName] = mark;
	}

	//���������� ������ �������� �� ���������� ����������
	int ReturnMark(std::string DiscName)
	{
		return Subjects[DiscName];
	}

	//��������� ������� ������(������� ��������������) �������� �� ���� �����������
	double AverageMark()
	{
		int sum = 0;
		double count = 0;
		for (auto x : Subjects)
		{
			sum += x.second;
			count++;
		}
		return sum / count;
	}

	//���������� ����������� ������ �������� ����� ���� ���������
	int MinMark()
	{
		int min = 6;
		for (auto x : Subjects)
			if (x.second < min)
				min = x.second;
		return min;
	}

	//���������� ������������ ������ �������� ����� ���� ���������
	int MaxMark()
	{
		int max = 0;
		for (auto x : Subjects)
			if (x.second > max)
				max = x.second;
		return max;
	}

	//������� ������ �� ��������, ��� ��������������� �����, ���, ��� �������, ����������� � ������������ ������.
	void PrintStudent()
	{
		cout << "��������������� ����� : " << RegNum << "\n��� : "<< Name << "\n������� ������ : " << AverageMark() << "\n����������� ������ : " << MinMark() << "\n������������ ������ : " << MaxMark() << "\n\n";
	}


};

//������� ���������� �� ���������, ������� ����� ��� �������� �� 5
void HighAchievers(std::vector<Student>);

//������� ���������� �� ���������, ������� ����� ���� �� ���� 3
void HaveOne3(std::vector<Student>);

//������� ���������� �� ���������, ������� ����� ���� �� ���� 2
void HaveOne2(std::vector<Student>);

#endif HW3_H