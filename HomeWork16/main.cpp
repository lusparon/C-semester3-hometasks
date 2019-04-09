#include "Header.h"

void main()
{
	setlocale(LC_ALL,"RUSSIAN");
	//Задание 1
	cout << "Задание 1\n";
	string s = "hello world hello i am world i hello";
	cout << "Исходная строка : " << s << endl ;
	auto m = count_words(s);
	for (auto& x : m)
		cout << x.first << " : " << x.second << endl;
	cout << endl;

	//Задание 2
	cout << "Задание 2\n";
	auto st = key_set(m);
	for (auto& x : st)
		cout << x << " ; " ;
	cout << endl;

	system("pause");
}