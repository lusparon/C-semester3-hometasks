#include "Array.h";

//Дан целочисленный массив. На его основе создать новый массив, в котором удалены все вхождения заданного числа.
int * DeleteN(int a[], int& size , int n)
{
	int * res = new int[size];
	int * a2 = new int[size];
	a2 = a;
	int x = *a2;
	int n1 = 0;
	for (int i = 0; i < size; i++)
	{
		if (x != 2)
		{
			*res = x;
			res++;
			n1++;
		}
		a2++;
		x = *a2;
	}

	size = n1;
	res = res - n1;
	return res;
}

//Дан целочисленный массив, все элементы которого различны. Вернуть массив, содержащий последний промежуток монотонности данного массива
int * last_mono_interval(int * a, int sz, int& new_sz)
{
	bool f1 = a[sz - 2] < a[sz - 1]; int j = 0, jj = 0;
	for (int i = sz - 2; i >= 1; i--)
	{
		if (f1 != a[i - 1] < a[i])
		{
			j = i;
			break;
		}
	}
	new_sz = sz - j;
	int * res = new int[new_sz];
	for (int i = 0; i < new_sz; i++, j++)
	{
		res[i] = a[j];
	}
	return res;
}

//Дана квадратная целочисленная матрица порядка M. Подсчитать сумму элементов на её побочной диагонали
int sum_on_side_diag(int ** m, int rows, int cols)
{
	int s = 0;
	for (int i = 0; i < rows; i++)
		s += m[i][rows - i - 1];
	return s;
}