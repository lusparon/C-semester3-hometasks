#include <iostream>
#include "hw.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	//ЧАСТЬ 1

	//Задание1 
	/*cout << "Введите а и b : " ;
	int a, b;
	cin >> a >> b;
	cout << "Произведение всех целых чисел, кратных трём, от A до B включительно : " << ProdMult3(a, b) << "\n";
	cout << "\n";

	//Задание2
	cout << "Введите цену киллограмма конфет : ";
	double x;
	cin >> x;
	PriceOfSweet(x);
	cout << "\n";

	//Задание3
	cout << "Введите а и n : ";
	double a;
	int n;
	cin >> a >> n;
	cout << "Сумма ряда : " << MyPow(a, n) << "\n";
	cout << "\n";

	//Задание4
	cout << "Введите x и n : ";
	double x;
	int n;
	cin >> x >> n;
	cout << "Результат : " << My(x, n) << "\n";
	cout << "\n";

	//Задание5
	cout << "Введите n : ";
	int n;
	cin >> n;
	cout << "n-ное число Каталана : " << Catalan(n) << "\n";
	cout << "\n";


	//ЧАСТЬ 2

	//Задание1
	cout << "Введите число : ";
	int n;
	cin >> n;
	cout << "Результат для числа " << "n : " << NewNum(n) << "\n";
	cout << "\n";

	//Задание2
	cout << "Введите а и b : ";
	int a, b;
	cin >> a >> b;
	cout << "Поразрядная сумма по модулю 10 чисел " << a << " и " << b << " : " << BitSum(a, b) << "\n";
	cout << "\n";*/

	//Задание3
	cout << "Введите x и eps : ";
	double x , eps;
	cin >> x >> eps;
	cout << "Результат равен : " << My2(x, eps) << "\n";
	cout << atan(x);


	system("pause");
}