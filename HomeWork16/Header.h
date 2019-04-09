#ifndef Header_h
#define Header_h
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <set>
using namespace std;

//Функция подсчёта количества вхождений слов в данной строке
map<string, int> count_words(string const & input);

//
template<typename T1, typename T2>
ostream & operator<<(ostream & os, pair<T1, T2> const & p)
{
	return os << "(" << p.first << ", " << p.second << ") ";
}

//по данному отображению map возвращает множество ключей этого отображения
template<typename M>
set<typename M::key_type> key_set(M const & m)
{
	set<typename M::key_type> res;
	for (auto&x : m)
	{
		res.insert(x.first);
	}
	return res;
}
#endif Header_h

