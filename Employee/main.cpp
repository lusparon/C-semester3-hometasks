#include "employee.h"

void main()
{
	setlocale(LC_ALL , "RUSSIAN");

	//Задание 1. Понижающее и повышающее преобразование в языке C++
	Employee e1 = Employee("Ivan", 53, 31337);
	Person *pp;
	pp = &e1;
	pp->print();
	cout << endl;

	//Задание 2. С++ срезка
	Person p2 = Employee("John",23,40000);
	p2.print();
	// объект хранит только поля, относящиеся к person



	system("pause");
}