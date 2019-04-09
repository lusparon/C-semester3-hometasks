#include "rsaed_files.h"

void main()
{
	setlocale(LC_ALL,"RUSSIAN");
	{
		rsaed_ofile my_file("myfile.txt");
		my_file << 25;
		my_file << 50;
	}
	{
		rsaed_ifile my_file("myfile.txt");
		int x;
		int y;
		my_file >> x;
		my_file >> y;
		cout << "Файл целых: " << x << " " << y << endl;
	}
	{
		rsaed_ofile my_file2("my_file2.txt");
		my_file2 << 25.5;
		my_file2 << 50.9;
	}
	{
		rsaed_ifile my_file2("my_file2.txt");
		double x;
		double y;
		my_file2 >> x;
		my_file2 >> y;
		cout << "Файл вещественных : " << x << " " << y << endl;
	}
	system("pause");
}