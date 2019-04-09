//������� 1
#include "test3.h" 

void main()
{
	setlocale(LC_ALL,"RUSSIAN");

	// ������� 1
	cout << "������� 1\n";
	vector<int> v{ 1, 2, 3, 4, 5 , 6, 7 ,8 ,9 ,10 };
	cout << "������ �� ��������� : ";
	for (auto p = v.begin(); p != v.end(); ++p)
		cout << *p << " ; ";
	cout << endl;

	inc_on_n(v, 1);
	cout << "������ ����� ���������: ";
	for (auto p = v.begin(); p != v.end(); ++p)
		cout << *p << " ";
	cout << endl;
	assert(v[0] == 2 && v[9] == 11);
	cout << endl;

	// ������� 2
	list<double> l{ 1.5, 2.5, -8, 0 };
	assert(contains_abs_more_than_a(l , 3));
	assert(contains_abs_more_than_a(l , 7));
	cout << "������� 2 , ����� �������!\n";
	cout << endl;

	// ������� 3
	list<string> l2{"key1" , "key2" , "key2" , "key3" , "key1" , "key1"  };
	map<string, int> m1, m2, m3;
	m1 = list_to_map(l2, [&](string s) { return s == "key1"; });
	assert(m1["key1"] == 3);
	m2 = list_to_map(l2, [&](string s) { return s == "key2"; });
	assert(m2["key2"] == 2);
	m3 = list_to_map(l2, [&](string s) { return s == "key3"; });
	assert(m3["key3"] == 1);
	cout << "������� 3 , ����� �������!\n";
	cout << endl;
	
	// ������� 4
	vector<int> v4;
	v4.push_back(9);
	v4.push_back(4);
	v4.push_back(6);
	v4.push_back(5);
	v4.push_back(1);
	merge_sort(v4.begin(), v4.end());
	//for (int i = 0; i < v4.size(); i++)
	//cout << v4[i] << " ; ";
	assert(*v4.begin() == 1);
	assert(v4.back() == 9);
	cout << "������� 4 , ����� �������!!\n";


	system("pause");
}
