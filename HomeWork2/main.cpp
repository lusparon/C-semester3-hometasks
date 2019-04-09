#include <iostream>
#include "hw-2.h"
#include "print_vect.h"
#include <assert.h>
#include <string>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	//������� 1
	assert(LineLength(decimeter, 10) == 1);
	assert(LineLength(kilometer, 5) == 5000);
	assert(LineLength(millimeter, 1000) == 1);
	assert(LineLength(centimeter, 1000) == 10);
	cout << "������� 1 : ����� �������! \n\n";

	//������� 2
	cout << "������� 2\n";
	vector<int> a(5);
	DegreeOfTwoVector(a);
	cout << "������ ������� 5 : ";
	print_vector(a);
	cout << "\n";
	vector<int> b(8);
	DegreeOfTwoVector(b);
	cout << "������ ������� 8 : ";
	print_vector(b);
	cout << "\n\n";

	//������� 3
	vector<int> a1{ 1,2,3,4,5,6,7,8,9 };
	int first, last;
	FirstAndLastEven(a1, first, last);
	assert(first==2 && last == 8);
	cout << "������� 3 : ����� �������! \n\n";

	//������� 4
	cout << "������� 4\n";
	vector<int> a2{ 0,1,2,3,4,5,6,7,8,9,10 };
	cout << "��������� ��� ������� �2 : ";
	ReverseOddElems(a2);
	cout << "\n\n";

	//������� 5
	vector<int> a3{ 0,1,2,3,4,5,6,7,8,9,10 };
	int k = 3;
	int l = 7;
	assert(AverageKtoL(a3,k,l)==5);
	cout << "������� 5 : ����� �������! \n\n";

	//������� 6
	cout << "������� 6\n";
	vector<double> a4{0,1,2,3,4,5,6,7,8,9,10};
	vector<double> b1(11);
	FromAtoB(a4,b1);
	cout << "��������� ��� �������� a4 , b1 : ";
	print_vector(b1);
	cout << "\n\n";

	//������� 7
	cout << "������� 7\n";
	vector<int> a5{ 1,2,3,4,5,6,7,8,9,10};
	ExpandVector(a5);
	cout << "��������� ��� ������� a5 : ";
	print_vector(a5);
	cout << "\n\n";

	//������� 8
	cout << "������� 8\n";
	vector<int> a6{ 0,1,2,3,4,5,6,7,8,9,10 };
	DeleteKElem(a6, 5);
	cout << "��������� ��� ������� a6 : ";
	print_vector(a6);
	assert(a6.size() == 10);
	cout << "\n\n";

	//������� 9
	cout << "������� 9\n";
	std::string s = "111011";
	cout << "��������� ��� ������ s : " << StringToInt(s, 2) << "\n";
	cout << "\n\n";

	//������� 10
	cout << "������� 10\n";
	std::string s1 = "HELLO   WORLD MY NAME IS LUSPARON";
	std::vector<word> v = VecOfStruct(s1);
	print_vector_struct(v);
	cout << "\n\n";

	//������� 11
	cout << "������� 11\n";
	DecrSort(v);
	print_vector_struct(v);

	system("pause");
}