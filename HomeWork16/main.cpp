#include "Header.h"

void main()
{
	setlocale(LC_ALL,"RUSSIAN");
	//������� 1
	cout << "������� 1\n";
	string s = "hello world hello i am world i hello";
	cout << "�������� ������ : " << s << endl ;
	auto m = count_words(s);
	for (auto& x : m)
		cout << x.first << " : " << x.second << endl;
	cout << endl;

	//������� 2
	cout << "������� 2\n";
	auto st = key_set(m);
	for (auto& x : st)
		cout << x << " ; " ;
	cout << endl;

	system("pause");
}