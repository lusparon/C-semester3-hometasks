#ifndef employee_h
#define employee_h
#include <iostream>
#include <string>
using namespace std;

//Класс person
class Person
{
	string name;
	int age;
public:
	Person(string _name, int _age) : name(_name), age(_age) {}
	void incAge()
	{
		age++;
	}

	virtual void print()
	{
		cout << "Имя : " << name << "\nВозраст : " << age << endl;
	}

};

class Employee : public Person
{
	double salary;
public:
	Employee(string _name, int _age, double _salary) : Person(_name, _age ), salary(_salary){}

	void print() override
	{
		Person::print();
		cout << "Зарплата : " << salary << endl ;
	}

	void addBonus(double percent)
	{
		salary *= (1 + percent / 100);
	}

};


#endif employee_h

