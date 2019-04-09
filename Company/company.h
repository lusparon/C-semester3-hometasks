#ifndef company_h
#define company_h
#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
using namespace std;

//����� worker
class worker
{
	string _name;
	double _salary;
	string _job;

public:
	//�����������
	worker(string name, double salary, string job) :_name(name), _salary(salary), _job(job){}

	string name() const { return _name; }
	double salary() const { return _salary; }
	string job() const { return _job; }

	void name(string n) { _name = n; }
	void salary(double s) { _salary = s; }
	void job(string j) { _job = j; }

};

//����� department
class department
{
	string _name;
	vector<worker> _workers;

public:
	//�����������
	department(string name, vector<worker> workers) :_name(name), _workers(workers) {}

	string name() const { return _name; }
	vector<worker> workers() const { return _workers; }

	//��������� � ������ ����������� ������ ����������;
	void operator+=(worker w)
	{
		_workers.push_back(w);
	}

	// ���������� ������� ���������� �����������;
	int get_number_of_workers()
	{
		return _workers.size();
	}

	//��������� ������� �������� ����������� ������� ������
	double get_average_salary()
	{
		double sum=0;
		double count = _workers.size();
		for (worker w : _workers)
			sum += w.salary();
		return sum *1.0/ count;
	}

};

//������������� �������� ������ ��������� � �����
inline ostream & operator<<(ostream & os, const worker & w)
{
	return os << "��� : " << w.name() << " ; �������� : " << w.salary() << " ; ��������� : " << w.job() << endl;
}

//������������� �������� ������ ������ � �����
inline ostream & operator<<(ostream & os, const department & d)
{
	os << "�������� ������ : " << d.name() << "\n������ ���������� : \n" ;
	for(worker w : d.workers())
		os << w;
	return os;
}

#endif company_h

