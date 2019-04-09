#include "task.h"
#pragma warning(disable : 4996)

//��������� �������� ������� ��������� (����� �����).
int eval(char * expr)
{
	if (expr == nullptr || *expr == '\0')
		return 0;
	int res = *expr - '0';
	++expr;
	while (*expr)
	{
		char n = *expr++;
		int x = *expr - '0';
		if (n == '+')
			res += x;
		else res -= x;
		expr++;
	}
	return res;
}

//���� C-������. ������������� � ��� ��� ��������� ��������� ����� � ��������. ������� ������ ���������� ���������� ����������� �����.
int to_lower(char * str)
{
	int res = 0;
	while (*str)
	{
		if (isupper(*str))
		{
			tolower(*str);
			res++;
		}
		str++;
	}
	return res;
}

//������� ������ ��������� ������� � ������ ������, ���������� ���� �� ���� ����� �����.
char first_gossip(char * str)
{
	return *(str+strcspn(str , "aAeEiIoOuUyY"));
}

//���� ������ � �������. ��������� �������� strtok, ������������ �� ������� ��� ����� ������.
void print_all_words(char* str)
{
	char * x = strtok(str, " ,.;:");
	while (x != NULL)
	{
		printf("%s\n", x);
		x = strtok(NULL, " ,.-");
	}

}

//������� ������ ���������� ������� � ������ ������.
int last_space(char* str)
{
	int i = 0;
	int j = 0;
	while (*str)
	{
		char c;
		if (*str == ' ')
		{
			c = *str;
			j = i;
		}
		i++;
		str++;
	}
	return j;
}

//��������� ���������� ��������� ������ s2 � ������ s1
int count_subs(char* s1, char * s2)
{
	int res = 0;
	char * p=s1;
	while (true) {
		p = strstr(p, s2);
		if (p != NULL)
			res++;
		else
			break;
		p += strlen(s2);
	}
	return res;
}

//������� �� ������ s1 ��� ��������� ������ s2.
void delete_all_subs(char* s1, char * s2)
{
	char * p = s1;
	while (true) {
		p = strstr(p, s2);
		if (p != NULL)
		{
			*p = '\0';
			strcat(s1, p + strlen(s2));
		}
		else
			break;
		p += strlen(s2);
	}
}


void print(const char * first, const char * last)
{
	while (first <= last) {
		cout << *(first++);
	}
	cout << " ";
}

void print_numbers(char *str)
{
	assert(str);
	while (auto pos = strpbrk(str, "0123456789")) 
	{
		auto len = strspn(pos, "0123456789");
		print(pos, pos + len - 1);
		str = pos + len;
	}
	cout << endl;
}

void swap_min_max(double *arr, int n)
{
	assert(arr);
	auto min = arr, max = arr;
	for (auto i = 0; i < n; ++i) {
		if (*(arr + i) < *min) min = arr + i;
		if (*(arr + i) > *max) max = arr + i;
	}
	auto temp = *min;
	*min = *max;
	*max = temp;
}

void swap_halves(int *arr, int n)
{
	assert(arr);
	assert(n % 2 == 0);
	for (int i = 0; i < n / 2; ++i) {
		std::swap(*(arr + n / 2 + i), *(arr + i));
	}
}