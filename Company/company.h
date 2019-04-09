#ifndef company_h
#define company_h
#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
using namespace std;

//класс worker
class worker
{
	string _name;
	double _salary;
	string _job;

public:
	//констурктор
	worker(string name, double salary, string job) :_name(name), _salary(salary), _job(job){}

	string name() const { return _name; }
	double salary() const { return _salary; }
	string job() const { return _job; }

	void name(string n) { _name = n; }
	void salary(double s) { _salary = s; }
	void job(string j) { _job = j; }

};

//класс department
class department
{
	string _name;
	vector<worker> _workers;

public:
	//конструктор
	department(string name, vector<worker> workers) :_name(name), _workers(workers) {}

	string name() const { return _name; }
	vector<worker> workers() const { return _workers; }

	//добавляет в массив сотрудников нового сотрудника;
	void operator+=(worker w)
	{
		_workers.push_back(w);
	}

	// возвращает текущее количество сотрудников;
	int get_number_of_workers()
	{
		return _workers.size();
	}

	//вычисляет среднюю зарплату сотрудников данного отдела
	double get_average_salary()
	{
		double sum=0;
		double count = _workers.size();
		for (worker w : _workers)
			sum += w.salary();
		return sum *1.0/ count;
	}

};

//Перегруженная операция вывода работника в поток
inline ostream & operator<<(ostream & os, const worker & w)
{
	return os << "Имя : " << w.name() << " ; Зарплата : " << w.salary() << " ; Должность : " << w.job() << endl;
}

//Перегруженная операция вывода отдела в поток
inline ostream & operator<<(ostream & os, const department & d)
{
	os << "Название отдела : " << d.name() << "\nСписок работников : \n" ;
	for(worker w : d.workers())
		os << w;
	return os;
}

#endif company_h

