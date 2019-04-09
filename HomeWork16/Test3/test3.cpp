//Вариант 1
#include "test3.h" 

//Задание 1.Увеличивает каждый элемент на заданную величину . 
void inc_on_n(vector<int> & v, int n) 
{
	transform(v.begin(), v.end(), v.begin(), [&](int a) { return a += n; });
}

//Задание 2.По данному списку вещественных чисел  и целому положительному числу  возвращает истину, если список содержит хотя бы один элемент, 
//модуль которого превосходит число a, и ложь в противном случае. Для пустого списка функция возвращает ложь. */
bool contains_abs_more_than_a(list<double> l, int a)
{
	if (l.empty())
		return false;
	return any_of(l.begin(), l.end(), [&](double x) { return fabs(x) > a; });
}



