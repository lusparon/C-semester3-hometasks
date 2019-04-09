#include "task.h"


void main()
{
	setlocale(LC_ALL,"RUSSIAN");
	//Задание 1
	char s[] = "4+7−2−8";
	assert(eval(s)==1);
	char s1[] = "5+5+7";
	assert(eval(s1) == 17);
	cout << "Задание 1 , тесты успешны!\n";

	//Задание 2
	char s3[] = "HellO WORLD";
	assert(to_lower(s3)==7);
	char s4[] = "ENTER STRING";
	assert(to_lower(s4) == 11);
	cout << "Задание 2 , тесты успешны!\n";

	//Задание 3
	char s5[] = "HllO WORLD";
	assert(first_gossip(s5)=='O');
	char s6[] = "hhhdfffra";
    assert(first_gossip(s6) == 'a');
	cout << "Задание 3 , тесты успешны!\n";

	//Задание 4
	cout << "Задание 4\n";
	char s7[] = "HllO WORLD first second last";
	cout << "Все слова строки S7 : \n";
	print_all_words(s7);
	cout << "\n";

	//Задание 5
	char s8[] = "HellO W";
	assert(last_space(s8)==5);
	char s9[] = "01234 6";
	assert(last_space(s9) == 5);
	cout << "Задание 5 , тесты успешны!\n";

	//Задание 6
	char s10[] = "I want to goto go go go 123 ";
	char s11[] = "go";
	assert(count_subs(s10,s11)==4);
	char s12[] = "This is a simple string ";
	char s13[] = "simple";
	assert(count_subs(s12, s13) == 1);
	cout << "Задание 6 , тесты успешны!\n";


	//Задание 7
	char s14[] = "abcXXXdefXXXgh";
	char s15[] = "XXX";
	delete_all_subs(s14, s15);
	assert(strcmp(s14, "abcdefgh\0") == 0);
	cout << "Задание 7 , тесты успешны!\n";


	//Задание 8
	char s16[] = "The least Carmichael number is 561.  234 jhgv 459";
	cout << "Задание 8\n";
	cout << "Все числа строки S16 : \n";
	print_numbers(s16);
	cout << "\n";

	//Задание 9
	double arr[3]{1.0 , 2.0 , 3.0};
	swap_min_max(arr,3);
	assert(arr[0]==3.0 && arr[2] == 1.0);
	cout << "Задание 9 , тесты успешны!\n";

	//Задание 10
	int arr1[4]{ 1 , 2 , 3 , 4 };
	cout << "Задание 10 \nмассив до изменения : ";
	for (int i = 0; i < 4; i++)
		cout << arr1[i] << " ";
	cout << "\n";
	swap_halves(arr1,4);
	cout << "массив после изменения : ";
	for (int i = 0; i < 4; i++)
		cout << arr1[i] << " ";
	cout << "\n";


	system("pause");
}