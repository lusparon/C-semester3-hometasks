#include "company.h"

void main()
{
	setlocale(LC_ALL,"RUSSIAN");
	worker john = worker("John",10000,"developer");

	assert(john.name() == "John");
	assert(john.salary() == 10000);
	assert(john.job() == "developer");

	john.name("Karl");
	john.salary(15000);
	john.job("teacher");

	assert(john.name() == "Karl");
	assert(john.salary() == 15000);
	assert(john.job() == "teacher");

	cout << "Задание 1 , тесты успешны!\n";

	vector<worker> w;
	w.push_back(john);
	department d = department("First", w);
	worker alice = worker("Alice", 15000, "developer");
	d += alice;
	assert(d.get_number_of_workers()==2);
	worker alex = worker("Alex", 30000, "barista");
	d += alex;
	assert(d.get_number_of_workers() == 3);
	assert(d.get_average_salary()==20000);

	cout << "Задание 2 , тесты успешны!\n\n\n";

	cout << "Вывод работника : ";
	cout << alex;
	cout << endl;

	cout << "Вывод отдела : \n";
	cout << d;


	system("pause");
}