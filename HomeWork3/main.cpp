#include <iostream>
#include "hw-3.h"
#include <vector>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	//������ ���������
	map <std::string, int> mp = { {"Math",0},{ "Russian",0 },{ "Literature",0 },{ "History",0 },{ "Physics",0 } };
	
	//������������� ���������
	Student stud1 = Student("John", 1);
	Student stud2 = Student("Marry", 2);
	Student stud3 = Student("Pauline", 3);
	Student stud4 = Student("Lusparon", 4);

	//���������� ���������
	stud1.Subjects = mp;
	stud2.Subjects = mp;
	stud3.Subjects = mp;
	stud4.Subjects = mp;

	//���������� ������
	stud1.AddMark("Math", 5);
	stud1.AddMark("Russian", 3);
	stud1.AddMark("Literature", 4);
	stud1.AddMark("History", 2);
	stud1.AddMark("Physics", 5);

	stud2.AddMark("Math", 2);
	stud2.AddMark("Russian", 3);
	stud2.AddMark("Literature", 3);
	stud2.AddMark("History", 4);
	stud2.AddMark("Physics", 3);

	stud3.AddMark("Math", 5);
	stud3.AddMark("Russian", 4);
	stud3.AddMark("Literature", 4);
	stud3.AddMark("History", 5);
	stud3.AddMark("Physics", 5);

	stud4.AddMark("Math", 5);
	stud4.AddMark("Russian", 5);
	stud4.AddMark("Literature", 5);
	stud4.AddMark("History", 5);
	stud4.AddMark("Physics", 5);

	//����� ������
	cout << "����� ������\n\n";
	stud1.PrintStudent();
	stud2.PrintStudent();
	stud3.PrintStudent();
	stud4.PrintStudent();

	cout << "\n\n";

	//������������� ������� ��������
	std::vector<Student> v = { stud1,stud2, stud3, stud4 };

	//����� ����������
	cout << "����� ����������\n\n";
	HighAchievers(v);
	cout << "\n\n";

	//����� ��������� , ������� ����� ���� �� ���� 3
	cout << "����� ��������� , ������� ����� ���� �� ���� 3\n\n";
	HaveOne3(v);
	cout << "\n\n";

	//����� ��������� , ������� ����� ���� �� ���� 2
	cout << "����� ��������� , ������� ����� ���� �� ���� 2\n\n";
	HaveOne2(v);
	cout << "\n\n";

	system("pause");
}