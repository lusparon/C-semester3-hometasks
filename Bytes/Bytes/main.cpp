#include <iostream>
#include "printBytes.h"
#include <assert.h>
#include "swap.h"
#include "Array.h";
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	//�������� �������
	cout << "�������� �������\n";
	cout << "������� 1 \n";
	cout << "������� ���������� ������  �������� ��������� ��������� ���� : \n";
	int arr[4]{1,2,3,4};
	printBytes(arr, 4, INT);
	cout << endl;
	delete[] arr;

	cout << "������� ������ �������� �������� ��������� ��������� ���� : \n";
	int arr1[4]{5,6,7,8};
	int arr2[4]{ 10,11,12,13 };
	cout << "������ 1 �� �������������� : " << arr1[0] << " " << arr1[1] << " " << arr1[2] << " " << arr1[3] << endl;
	cout << "������ 2 �� �������������� : " << arr2[0] << " " << arr2[1] << " " << arr2[2] << " " << arr2[3] << endl;
	swap(arr1, arr2, 4, INT);
	cout << endl;
	cout << "������ 1 ����� �������������� : " << arr1[0] << " " << arr1[1] << " " << arr1[2] << " " << arr1[3] << endl;
	cout << "������ 2 ����� �������������� : " << arr2[0] << " " << arr2[1] << " " << arr2[2] << " " << arr2[3] << endl;
	cout << endl << endl;
	delete[] arr1 , arr2;


	cout << "������� 2 \n";
	int a = 3, b = 4;
	swapByRef(a, b);
	cout << a << " -- " << b << endl; // 4 -- 3

	double c = 3.14, d = 2.71;
	swapByRef(c, d);
	cout << c << " -- " << d << endl; // 2.71 -- 3.14
	cout << endl << endl;


	cout << "������� 3 \n";
	a = 10;
	b = 20;
	swapByPtr(&a,&b);
	cout << a << " -- " << b << endl; // 20 -- 10
	cout << endl << endl;


	cout << "������� 4 \n";
	int arr3[4]{4,5,6,7};
	double arr4[4]{2.2,3.3,4.4,5.5};
	cout << "������ ����� : ";
	printArray(arr3, 4);
	cout << "������ ������������ : ";
	printArray(arr4, 4);
	cout << endl << endl;
	delete[] arr3 , arr4 ;


	cout << "������� 5 \n";
	int x = 1;
	cout << "����������� ������ ����� " << x << " : ";
	printBytes(&x);
	double y = 1.1;
	cout << "����������� ������ ����� " << y << " : ";
	printBytes(&y);
	cout << endl << endl;


	cout << "������� 6 \n";
	int a2 = 3, b2 = 4;
	swapByRef2(a2, b2);
	cout << a2 << " -- " << b2 << endl; // 4 -- 3

	double c2 = 3.14, d2 = 2.71;
	swapByRef2(c2, d2);
	cout << c2 << " -- " << d2 << endl; // 2.71 -- 3.14
	cout << endl << endl;

	//����� 2
	cout << "����� 2\n";
	cout << "������� 1\n";
	int arr5[4]{1,2,3,2};
	cout << "�������� ������ : ";
	printArray(arr5 , 4);
	int size = 4;
	int n = 2;
	int * arr6 = DeleteN(arr5 , size , n);
	cout << "�������� ������ : ";
	printArray(arr6 , size);
	cout << endl << endl;
	delete[] arr5, arr6;




	system("pause");
}