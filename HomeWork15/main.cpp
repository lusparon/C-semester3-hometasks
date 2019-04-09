#include "iterator.h"
#include <assert.h>

void main()
{
	setlocale(LC_ALL,"RUSSIAN");
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	cout << "Задание 1\n";
	cout << "Вектор до переворота : \n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ; ";
	cout << endl;
	cout << "Вектор после переворота : \n";
	my_rotate(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ; ";
	cout << endl;
	cout << endl;

	cout << "list до переворота : \n";
	list<int> l{1,2,3,4,5,6};
	for (auto i = l.begin();i != l.end();i++)
		cout << *i << " ; ";
	cout << endl;
	cout << "list после переворота : \n";
	my_rotate(l.begin(), l.end());
	for (auto i = l.begin(); i != l.end();i++)
		cout << *i << " ; ";
	cout << endl;
	cout << endl;

	cout << "Задание 2\n";
	list<int> l1{1,2,-3,4,5 -6};
	cout << "list до вставки : \n";
	for (auto i = l1.begin();i != l1.end();i++)
		cout << *i << " ; ";
	cout << endl;
	insert_null(l1);
	cout << "list после вставки : \n";
	for (auto i = l1.begin(); i != l1.end();i++)
		cout << *i << " ; ";
	cout << endl;
	cout << endl;

	cout << "Задание 3\n";
	vector<int> v2;
	for (int i = 1; i < 10; ++i) v2.push_back(i);
	cout << "Вектор до сортировки : \n";
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ; ";
	cout << endl;
	cout << "Вектор после сортировки : \n";
	gather(v2.begin(), v2.end(), next(v2.begin(), distance(v2.begin(), v2.end()) / 2), [](int i) {return i % 2==0;});
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ; ";
	cout << endl;
	list<int> l2{ 1,-2,-3,4,5 - 6 };
	cout << "list до сортировки : \n";
	for (auto i = l2.begin();i != l2.end();i++)
		cout << *i << " ; ";
	cout << endl;
	gather(l2.begin(), l2.end(), next(l2.begin(), distance(l2.begin(), l2.end()) / 2), [](int i) {return i > 0;});
	cout << "list после сортировки : \n";
	for (auto i = l2.begin(); i != l2.end();i++)
		cout << *i << " ; ";
	cout << endl;
	cout << endl;

	//Часть 2
	cout << "Задание 4\n";
	cout << "Вектор  : ";
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ; ";
	cout << endl;
	cout << "Сумма элементов : " << sum(v2.begin() , v2.end() , 0);
	cout << endl;
	cout << endl;

	cout << "Задание 5\n";
	cout << "Вектор  : ";
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ; ";
	cout << endl;
	auto s = sum(v2.begin(), v2.end());
	cout << "Сумма элементов : " << s ;
	cout << endl;
	cout << endl;
	list<double> l3{1.4,5.6,2.3};
	cout << "list : ";
	for (auto i = l3.begin();i != l3.end();i++)
		cout << *i << " ; ";
	cout << endl;
	cout << "Сумма элементов : " << sum(l3.begin(),l3.end());
	cout << endl;
	cout << endl;

	cout << "Задание 6\n";
	auto il = { 10, 20, 30 };
	cout << "Сумма элементов : " << sum(il.begin(),il.end());
	cout << endl;



	system("pause");
}