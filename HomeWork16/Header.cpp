#include "Header.h"

//������� �������� ���������� ��������� ���� � ������ ������
map<string, int> count_words(string const & input)
{
	map<string, int> res;
	istringstream is(input);
	while (true) {
		string a;
		is >> a;
		if (!is)
			break;
		++res[a];
	}
	return res;
}