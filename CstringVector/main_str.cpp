#include "cstring_vector.h"

int main()
{
	/*
	cstring_vector sv0;
	sv0.println();

	int const N1{ 3 };
	const char * cstr_arr[N1] = { "Hello,", " ", "world!" };
	cstring_vector sv1(cstr_arr, N1);
	sv1.println();

	char const * consts_cstr_arr[] = { "Anything", "you", "like" };
	cstring_vector sv2(consts_cstr_arr, N1);
	sv2.println();

	std::vector<std::string> v;
	v.push_back("Hello ");
	v.push_back("my ");
	v.push_back("friend");
	cstring_vector sv3(v);
	sv3.println();

	cstring_vector sv4(sv3);
	sv4.println();

	cstring_vector sv5 = sv4;
	sv5.println();

	print_cstring(sv5[1]);
	std::cout << "\n";*/

	//��
	setlocale(LC_ALL,"RUSSIAN");
	cout << endl << "�������������� � vector :" << endl;

	int const N1{ 3 };
	const char * cstr_arr[N1] = { "Hello " , " , " , "world " };
	cstring_vector sv1(cstr_arr, N1);

	vector<string> sv = sv1.convert_to_string_vector();
	for (int i = 0; i < sv.size(); i++)
		cout << sv[i] << " ";
	cout << endl;

	cout << endl << "���� � ���������� (����� ����� - ������ ������) :" << endl;
	cstring_vector sv8;
	sv8 = read_cstring_vector();
	cout << sv8 << endl;


	system("pause");
}
/*
�������������� � vector :
Hello   ,  world

���� � ���������� (����� ����� - ������ ������) :
Hello
world
my name is lusparon

������ move �����������
������ ����������� �����
Hello, world, my name is lusparon*/