#include "Header.h"
#include <vector>
#include <list>
#include <assert.h>
#include <ctime>

void main()
{
	setlocale(LC_ALL,"RUSSIAN");
	vector<int> v;
	vector<int> v1;
	v.push_back(5);
	v.push_back(6);
	v.push_back(8);
	v.push_back(12);
	v.push_back(3);
	v.push_back(6);
	v.push_back(9);
	v.push_back(0);
	list<int> l{1,2,3,4,5,6,7,8,9};
	list<int> l1{ 1,2,3 };
	


	assert(in_range(v.begin(),v.end(),v.begin()+3));
	assert(in_range(v.begin(), v.end(), v.begin() + 6));
	assert(!in_range(v.begin(), v.end(), v.end()));
	assert(in_range(l.begin(), l.end(), l.begin()));
	assert(!in_range(l.begin(), l.end(), l.end()));
	cout << "Задание 1 , тесты успешны!\n";

	srand(time(0));
	assert(in_range(v.begin(),v.end(),random_it(v.begin(), v.end())));
	assert(in_range(l.begin(), l.end(), random_it(l.begin(), l.end())));
	assert(!in_range(l.begin(), l.end(), l.end()));
	cout << "Задание 2 , тесты успешны!\n";
	cout << endl;

	cout << "Задание 3\n";
	cout << "Вектор до сдвига : \n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ; ";
	cout << endl;
	cout << "Вектор после сдвига : \n";
	shift_right(v.begin(),v.end(),4);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ; ";
	cout << endl;
	cout << endl;

	cout << "Часть 2. Сортировка вставками\n";
	cout << "Вектор до сортировки : \n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ; ";
	cout << endl;

	ins_sort(v.begin(),v.end());
	cout << "Вектор после сортировки по возрастанию : \n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ; ";
	cout << endl;

	ins_sort(v.begin(), v.end(), [](int a, int b) { return a > b;});
	cout << "Вектор после сортировки по убыванию : \n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ; ";
	cout << endl;
	cout << endl;

	cout << "Часть 3. Быстрая сортировка\n";
	quick_sort(v.begin(), v.end());
	cout << "Вектор после сортировки по возрастанию : \n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ; ";
	cout << endl;


	system("pause");
}