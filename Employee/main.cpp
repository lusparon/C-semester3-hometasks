#include "employee.h"

void main()
{
	setlocale(LC_ALL , "RUSSIAN");

	//������� 1. ���������� � ���������� �������������� � ����� C++
	Employee e1 = Employee("Ivan", 53, 31337);
	Person *pp;
	pp = &e1;
	pp->print();
	cout << endl;

	//������� 2. �++ ������
	Person p2 = Employee("John",23,40000);
	p2.print();
	// ������ ������ ������ ����, ����������� � person



	system("pause");
}