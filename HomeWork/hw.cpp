#include "hw.h"
#include <iostream>
#include <assert.h>
#include <math.h>
using namespace std;

//Найти произведение всех целых чисел, кратных трём, от A до B включительно.
double ProdMult3(int a, int b)
{
	double res = 1;
	for (int i = a; i <= b; i++)
	{
		if (i % 3 == 0)
			res *= i;
	}
	return res;
}

//Дано вещественное число — цена 1 кг конфет. Вывести стоимость 1.2, 1.4, …, 2 кг конфет.
void PriceOfSweet(double x)
{
	for (int i = 1; i <=5; i++)
	{
		cout << "Цена " << 1 + 0.2*i << " кг. конфет : " << x * (1 + 0.2*i) << "\n";
	}
}

//Дано вещественное число A и целое число N (≥ 0). Используя один цикл, найти сумму 1 + A + A^2 + A^3 + … + A^N.
double MyPow(double a, int n)
{
	assert(n >= 0);
	double sum = 1;
	double apow = a;
	if (n == 0) return 1;
	for (int i = 1; i < n+1; i++)
	{
		sum += apow;
		apow *= a;
	}
	return sum;
}

//Дано вещественное число X и целое число N > 0. Найти значение выражения :
double My(double x, int n)
{
	assert(n > 0);
	double res = x;
	int sign = -1;
	double num = x * x*x;
	int den = 1 * 2 * 3;
	for (int i = 1; i <= n ; i++)
	{
		res += sign * num / den;
		sign *= -1;
		num *= x * x;
		den *= (i + 1) * 2 * ((i + 1) * 2 + 1);
	}
	return res;
}

//Вычисляет n-ное число каталана
double Catalan(int n)
{
	double nfact = 1;
	for (int i = 1; i <= n ; i++)
	{
		nfact *= i;
	}
	double nfact2 = 1;
	for (int i = 1; i <= 2*n; i++)
	{
		nfact2 *= i;
	}
	return nfact2/ (nfact*nfact*(n + 1));
}

//Сформировать новое число, нечетные (по порядку) разряды которого совпадают с соответствующими разрядами исходного числа, а четные равны нулю.
int NewNum(int& n)
{
	int res = 0;
	int i = 1;
	while (n != 0)
	{
		res += (n % 10)*i;
		i *= 100;
		n = n/100;
	}
	return res;
}

//Даны два целых числа с одинаковым количеством разрядов. Найти их поразрядную сумму по модулю 10. 
int BitSum(int a, int b)
{
	int res = 0;
	int i = 1;
	while (a != 0)
	{
		res += (a % 10 + b % 10) % 10 * i;
		i *= 10;
		a = a / 10;
		b = b / 10;
	}
	return res;
}

//Дано вещественное число X (|X| < 1) и вещественное число eps (> 0). Найти значение выражения
double My2(double x, double eps)
{
	assert(x > -1 && x < 1 && eps > 0);
	int sign = -1;
	double num = x * x*x;
	double den = 3;
	double res = 0;
	double res1 = x;
	while (abs(res1 - res) > eps)
	{
		res += res1;
		res1 += sign * num / den;
		sign *= -1;
		num *= x * x;
		den += 2;
	}
	return res1;
}
	
