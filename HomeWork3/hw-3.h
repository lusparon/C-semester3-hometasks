#ifndef HW3_H
#define HW3_H
#include <iostream>
#include <map>
#include <assert.h>
#include <string>
#include <vector>
using namespace std;

//структура студент
struct Student
{
	std::string Name; //имя студента 
	int RegNum; //регистрационный номер
	map <std::string, int> Subjects; //"Название дисциплины" и  "Оценка студента"

	//конструктор
	Student(std::string name, int regnum)
	{
		Name = name;
		RegNum = regnum;
	}

	//Добавдение оценки по дисциплине
	void AddMark(std::string DiscName, int mark)
	{
		assert(mark  >= 1 && mark <= 5);
		Subjects[DiscName] = mark;
	}

	//Возвращает оценку студента по переданной дисциплине
	int ReturnMark(std::string DiscName)
	{
		return Subjects[DiscName];
	}

	//Вычисляет среднюю оценку(среднее арифметическое) студента по всем дисциплинам
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

	//Возвращает минимальную оценку студента среди всех дисциплин
	int MinMark()
	{
		int min = 6;
		for (auto x : Subjects)
			if (x.second < min)
				min = x.second;
		return min;
	}

	//Возвращает максимальную оценку студента среди всех дисциплин
	int MaxMark()
	{
		int max = 0;
		for (auto x : Subjects)
			if (x.second > max)
				max = x.second;
		return max;
	}

	//Выводит сводку по студенту, его регистрационный номер, имя, его среднюю, минимальную и максимальную оценки.
	void PrintStudent()
	{
		cout << "Регистрационный номер : " << RegNum << "\nИмя : "<< Name << "\nСредняя оценка : " << AverageMark() << "\nМинимальная оценка : " << MinMark() << "\nМаксимальная оценка : " << MaxMark() << "\n\n";
	}


};

//Выводит информацию по студентам, которые сдали все предметы на 5
void HighAchievers(std::vector<Student>);

//Выводит информацию по студентам, которые имеют хотя бы одну 3
void HaveOne3(std::vector<Student>);

//Выводит информацию по студентам, которые имеют хотя бы одну 2
void HaveOne2(std::vector<Student>);

#endif HW3_H