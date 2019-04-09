#include "hw-2.h"
#include <iostream>
#include "print_vect.h"
#include <vector>
#include <assert.h>
#include <climits>
#include <string>
using namespace std;

//Дан номер единицы длины (целое число в диапазоне 1–5) и длина отрезка в этих единицах (вещественное число). Найти длину отрезка в метрах.
double LineLength(MyLength x, double n)
{
	assert(x >= 1 && x <= 5 && n > 0);
	switch (x)
	{
	case 1 :
		return n * 0.1;
	case 2:
		return n * 1000;
	case 3:
		return n;
	case 4:
		return n * 0.001;
	case 5 :
		return n * 0.01;
	}
}

//Дан целочисленный вектор A размера N (> 0). Заполнить его степенями двойки от первой до N-й: 2, 4, 8, 16, 
void DegreeOfTwoVector(std::vector<int>& a)
{
	assert(a.size()>0);
	int s = 2;
	for (int i = 0; i < a.size(); i++)
	{
		a[i] = s;
		s *= 2;
	}
}

//Дан целочисленный вектор A размера N, содержащий хотя бы одно чётное число. Найти первое и последнее чётное число в данном векторе.
void FirstAndLastEven(std::vector<int> a, int& first, int& last)
{
	int f = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] % 2 == 0 && f == 0)
		{
			first = a[i];
			last = a[i];
			f = 1;
		}
		if (a[i] % 2 == 0 && f == 1)
			last = a[i];
	}
}

//Дан вектор A размера N (N — нечетное число). Вывести его элементы с нечётными номерами в порядке убывания номеров
void ReverseOddElems(std::vector<int> a)
{
	assert(a.size() % 2 != 0);
	for (int i = a.size()-2; i > 0 ; i-=2)
	{
		cout << a[i] << " ";
	}
}

//Дан целочисленный вектор размера N и целые числа K и L (0 ≤ K ≤ L < N). Найти среднее арифметическое элементов вектора с номерами от K до L включительно.
double AverageKtoL(std::vector<int> a, int k, int l)
{
	assert(k >=0 && k <= l && l < a.size());
	int sum = 0;
	double count = 0;
	for (int i = k; i <= l; i++)
	{
		sum += a[i];
		count++;
	}
	return sum / count;
}

//Даны два вещественных вектора A и B, каждый размера N. Переписать в вектор B вначале все элементы вектора A с чётными номерами, а затем — с нечётными:
void FromAtoB(std::vector<double> a, std::vector<double>& b)
{
	assert(a.size()==b.size());
	int i2 = 0;
	for (int i = 0; i < a.size(); i+=2)
	{
		b[i2] = a[i];
		i2++;
	}
	for (int i = 1; i < a.size(); i += 2)
	{
		b[i2] = a[i];
		i2++;
	}
}

//Дан вектор размера N (N — чётное число). Поменять местами первую и вторую половины вектора.
void ExpandVector(std::vector<int>& a)
{
	assert(a.size()%2==0);
	int buf;
	int j = a.size() / 2;
	for (int i = 0 ; i<a.size()/2; i++)
	{ 
		buf = a[j];
		a[j] = a[i];
		a[i] = buf; 
		j++;
	}
}

//Дан вектор размера N и целое число K (0 ≤ K < N). Удалить из вектора элемент с порядковым номером K, сдвинув все следующие за ним элементы на одну позицию влево и уменьшив размер вектора на единицу.
void DeleteKElem(std::vector<int>& a, int k)
{
	assert(k >= 0 && k < a.size());
	for (int i = k; i < a.size()-1; i++)
		a[i] = a[i + 1];
	a.resize(a.size() - 1);
}

//Дана строка, изображающая запись целого положительного числа в системе счисления с основанием b (0 < b ≤ 10). Вернуть соответствующее целое число
int StringToInt(std::string s, int b)
{
	assert(b > 0 && b <= 10);
	int x = stoi(s);
	int x1 = x;
	while (x1 > 0)
	{
		if (x1 % 10 >= b)
		{
			cout << "Ошибка!Данное число не относится к заданной системе счистления!\n";
			break;
		}
		x1 = x1 / 10;
	}
	return x;
}

//Дана строка, состоящая из английских слов, набранных заглавными буквами и разделенных пробелами(одним или несколькими).
//Сформировать вектор структур со следующей информацией по каждому слову в строке : позиция начала слова, длина слова.
std::vector<word> VecOfStruct(std::string s)
{
	std::vector<word> v;
	string w;
	word b;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
			w += s[i];

		if (s[i] == ' ')
		{
			if (w == "")
				continue;
			b.s = w;
			b.length = w.length();
			b.pos = i - w.length();
			v.push_back(b);
			w = "";
		}
	}
	if (w != "")
	{
		b.s = w;
		b.length = w.length();
		b.pos = s.length() - w.length();
		v.push_back(b);
	}

	return v;
}

//Фунция печати вектора из прошлого номера
void print_vector_struct(const std::vector<word> v)
{
	for (auto x : v)
		std::cout << "Слово : " << x.s << "\nДлина слова : " << x.length << "\nПозиция слова : " << x.pos << "\n\n";
}


//алгоритм сортировки вектора из предыдущего упражнения по убыванию длины слова
void DecrSort(std::vector<word>& v)
{
	word wbuffer;
	int i, j;
	for (i = 0; i < v.size(); i++)
		for (j = i + 1; j < v.size(); j++)
			if (v[i].length < v[j].length)
			{
				wbuffer = v[j];
				v[j] = v[i];
				v[i] = wbuffer ;
			}
	
}