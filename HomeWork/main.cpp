#include <iostream>
#include "hw.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	//����� 1

	//�������1 
	/*cout << "������� � � b : " ;
	int a, b;
	cin >> a >> b;
	cout << "������������ ���� ����� �����, ������� ���, �� A �� B ������������ : " << ProdMult3(a, b) << "\n";
	cout << "\n";

	//�������2
	cout << "������� ���� ����������� ������ : ";
	double x;
	cin >> x;
	PriceOfSweet(x);
	cout << "\n";

	//�������3
	cout << "������� � � n : ";
	double a;
	int n;
	cin >> a >> n;
	cout << "����� ���� : " << MyPow(a, n) << "\n";
	cout << "\n";

	//�������4
	cout << "������� x � n : ";
	double x;
	int n;
	cin >> x >> n;
	cout << "��������� : " << My(x, n) << "\n";
	cout << "\n";

	//�������5
	cout << "������� n : ";
	int n;
	cin >> n;
	cout << "n-��� ����� �������� : " << Catalan(n) << "\n";
	cout << "\n";


	//����� 2

	//�������1
	cout << "������� ����� : ";
	int n;
	cin >> n;
	cout << "��������� ��� ����� " << "n : " << NewNum(n) << "\n";
	cout << "\n";

	//�������2
	cout << "������� � � b : ";
	int a, b;
	cin >> a >> b;
	cout << "����������� ����� �� ������ 10 ����� " << a << " � " << b << " : " << BitSum(a, b) << "\n";
	cout << "\n";*/

	//�������3
	cout << "������� x � eps : ";
	double x , eps;
	cin >> x >> eps;
	cout << "��������� ����� : " << My2(x, eps) << "\n";
	cout << atan(x);


	system("pause");
}