//Эйлер
#include <iostream>
#include <vector>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	//Задание 1
	//Найдите сумму всех чисел меньше 1000 кратных 3 или 5.
	int sum = 0;
	for (int i = 1; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}
	cout << "Результат задания 1 : " << sum << "\n";

	//Задание 2
	//Найдите сумму всех чётных элементов ряда Фибоначчи, которые не превышают четыре миллиона.
	int first = 1;
	int second = 2;
	int f;
	int sum2 = 2;
	while (second <= 4000000)
	{
		f = second;
		second = second + first;
		first = f;
		if (second % 2 == 0 && second <= 4000000)
			sum2 += second;
	}
	cout << "Результат задания 2 : " << sum2 << "\n";

	//Задание 3
	
				

	system("pause");
}