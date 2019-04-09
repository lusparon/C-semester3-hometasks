//ВАРИАНТ 1
#include <iostream>
#include "test1.h"
#include <vector>
#include "print_vector.h"
#include <assert.h>
#include <string>
#include "NormalAlgorifm.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << "КОНТРОЛЬНАЯ РАБОТА ВАРИАНТ 1\n";
	//Задание 1
	cout << "Задание 1\n";
	vector<int> a {1,2,3,4,5,6,7,3,4,6};
	int k = 1;
	cout << "Старый вектор : ";
	print_vector(a);
	cout << " ; число : " << k <<"\nНовый вектор : ";
	print_vector(MoreThenK(a,k));
	cout << "\n";
	cout << "\n";

	//Задание 2
	cout << "Задание 2\n";
	vector<int> v;
	int n = 50;
	cout << "Простые числа от 0 до N : ";
	Eratosthenes(v,n);
	print_vector(v);
	cout << "\n";
	cout << "\n";
	cout << "\n";

	//Задание 3
	cout << "Задание 3\n";
	vector<int> a1 {5,7,3,9,15,16 , 8, 5 , 4 ,0};
	k = 2;
	cout << "Номер первого числа в наборе, являющегося степенью числа K : " << FirstPowK(k, a1) << "\n";
	cout << "\n";
	cout << "\n";

	//Задание 4
	cout << "Задание 4\n";
	vector<double> v1{1.0,-2.0,5.0,-3.0};
	int n1 = 4;
	cout << "Старый вектор : ";
	print_vector(v1);
	cout << "\nНовый вектор : ";
	print_vector(MyNewVec(n1,v1));
	cout << "\n";
	cout << "\n";

	//Задание 5
	cout << "Задание 5\n";
	string s = "we are go to go hello lusparon abcgo !!";
	string s0 = "go";
	int w = 3;
	std::cout << std::boolalpha;
	cout << "Имеется ли в строке \"" << s << "\" как минимум " << w << " вхождений подстроки \"" << s0 << "\" ? \n- " << HowMuchS0inS(s, s0, w) << "\n";
	cout << "\n";
	cout << "\n";


	//Проект “Нормальные алгорифмы”
	cout << "Проект “Нормальные алгорифмы”\n";
	vector<NormSubs> v5{ { "ab","", false },{ "a","b",false } };
	string s1 = "aababab";
	Func(v5, s1);
	cout << "Результат пример 1 : " << s1 << endl;

	vector<NormSubs> v6{ { "b","a",true },{ "a","b",false } };
	string s2 = "aaa";
	Func(v6, s2);
	cout << "Результат пример 2 : " << s2 << endl;

	vector<NormSubs> v7{ { "ab","aaa", false },{ "a","b",false },{ "bbb","c", false },{ "bb","a",false } };
	string s3 = "bbb";
	Func(v7, s3);
	cout << "Результат пример 3 : " << s3 << endl;

	vector<NormSubs> v8{ { "cc","", true },{ "ab","cc",false } };
	string s4 = "abccabba";
	Func(v8, s4);
	cout << "Результат пример 4 : " << s4 << endl;

	/*Происходит зацикливание!!!
	vector<NormSubs> v9{ { "a","b",false },{ "b","a",false } };
	string s5 = "aabb";
	Func(v9, s5);
	cout << "Результат пример 4 : " << s5 << endl;*/




	system("pause");
}