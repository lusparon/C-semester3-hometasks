//�����
#include <iostream>
#include <vector>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	//������� 1
	//������� ����� ���� ����� ������ 1000 ������� 3 ��� 5.
	int sum = 0;
	for (int i = 1; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}
	cout << "��������� ������� 1 : " << sum << "\n";

	//������� 2
	//������� ����� ���� ������ ��������� ���� ���������, ������� �� ��������� ������ ��������.
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
	cout << "��������� ������� 2 : " << sum2 << "\n";

	//������� 3
	
				

	system("pause");
}