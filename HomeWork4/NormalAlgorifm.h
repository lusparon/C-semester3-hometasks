#ifndef normalalgorifm_h
#define normalalgorifm_h
#include <string>
#include <vector>
//Структура для хранения нормальной подстановки.
struct NormSubs
{
	std::string s;
	std::string p;
	bool f;
};

//применяет заданную схему нормального алгорифма (вектор подстановок) к заданной строке 
void Func(std::vector<NormSubs> v, std::string& s);

//является ли s0 подстрокой s .Если да , вернуть индекс первого вхождения , если нет вернуть -1
int IsSubstr(std::string s0,std::string s);


#endif normalalgorifm_h
