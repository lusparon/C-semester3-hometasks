#include "linked_list.h"
#include "matrix.h"
#include "pointers.h"
#include <assert.h>
#include <iostream>
using namespace std;

bool has2(int x)
{
	while (x > 0)
	{
		if (x % 10 == 2)
			return true;
		x /= 10;
	}
	return false;
}

int main()
{
	setlocale(LC_ALL,"RUSSIAN");
	auto matr1 = new int*[3]{
		new int[3]{ 1, 2, 3 },
		new int[3]{ 4, 5, 6 },
		new int[3]{ 7, 8, 9 }
	};

	auto matr2 = new int*[3]{
		new int[3]{ 1, 0, 0 },
		new int[3]{ 4, 5, 0 },
		new int[3]{ 7, 8, 9 }
	};

	auto matr3 = new int*[3]{
		new int[3]{ 3, 2, 1 },
		new int[3]{ 6, 5, 4 },
		new int[3]{ 9, 8, 7 }
	};

	UpperMainDig(matr1, 3);

	assert(MatrixEqual(matr1, 3, 3, matr2, 3, 3));

	matr1 = new int*[3]{
		new int[3]{ 1, 2, 3 },
		new int[3]{ 4, 5, 6 },
		new int[3]{ 7, 8, 9 }
	};

	SwapMinMaxInRows(matr1, 3, 3);

	assert(MatrixEqual(matr1, 3, 3, matr3, 3, 3));

	size_t n;
	cout << "������� ���������� ��������� : " << std::endl;
	cin >> n;
	cout << "������� " << n << " ���������" << std::endl;
	LinkedList<double> * list = ReadList<double>(n);
	cout << "������ ��������� : " << std::endl;
	list->PrintLn();
	
	cout << "������� �������������� ����� � ������ ������: " << Average(list) << std::endl;
	cout << "������ ����� �������� ��������� : " << std::endl;
	list->Filter([](double x) {return sin(x) >= 0; });
	list->PrintLn();
	cout << "������ ��������� : " << std::endl;
	list->PrintLn();
	AddZeros(list, 1);
	cout << "������ ����� ���������� ����� : " << std::endl;
	list->PrintLn();

	cout << "������� ������������������ , ��������������� ����� : " << std::endl;
	ReadAndCount(has2);
	std::cout << "����� , ���������� 2 : " << counter << std::endl;

	int ar1[4] = { 2 , 8 , 1 , 4 };
	int ar2[4] = { 3 , 6 , 4 , 9 };
	int ar3[4];

	ZipInt(ar1, ar2, ar3, 4, [](int x, int y) {return x + y; });
	cout << "����� ar1 � ar2 :\n";
	PrintArray(ar3, 4);

	ZipInt(ar1, ar2, ar3, 4, [](int x, int y) {return x * y; });
	cout << "������������ ar1 � ar2:\n";
	PrintArray(ar3, 4);

	ZipInt(ar1, ar2, ar3, 4, [](int x, int y) {return x < y ? y : x; });
	cout << "��������� ar1 � ar2:\n";
	PrintArray(ar3, 4);

	system("pause");
};