#ifndef normalalgorifm_h
#define normalalgorifm_h
#include <string>
#include <vector>
//��������� ��� �������� ���������� �����������.
struct NormSubs
{
	std::string s;
	std::string p;
	bool f;
};

//��������� �������� ����� ����������� ��������� (������ �����������) � �������� ������ 
void Func(std::vector<NormSubs> v, std::string& s);

//�������� �� s0 ���������� s .���� �� , ������� ������ ������� ��������� , ���� ��� ������� -1
int IsSubstr(std::string s0,std::string s);


#endif normalalgorifm_h
