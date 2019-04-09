#include "FatTable.h"

void main()
{
	setlocale(LC_ALL,"RUSSIAN");
	FatTable t(7);
	cout << "Пустая таблица : " << t;
	t.allocate_randomly(2);
	cout << "Заполним случайно : " << t;
	t.allocate_sequentially(4);
	cout << "Заполним последовательно : " << t;
	cout << endl;

	FatTable t1(7);
	t1.allocate_sequentially(3);
	cout << "Заполним последовательно : " << t1;
	vector<uint> v = t1.get_file_clusters_first(2);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ; ";
	cout << endl;

	FatTable t2(7);
	t2.allocate_sequentially(5);
	cout << "Заполним последовательно : " << t2;
	vector<uint> v1 = t2.get_file_clusters_middle(4);
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ; ";
	cout << endl;

	cout << endl << "Файловая система: " << endl;
	FatFileSystem fs(20, 256);
	fs.CreateFile("first.txt", 8);
	fs.useRandomAllocator();
	fs.CreateFile("second.txt", 4);
	fs.useSequentialAllocator();
	fs.CreateFile("third.txt", 6);
	fs.CreateFile("new.txt", 2);
	fs.printTable();

	cout << endl << "Удаление файла: " << endl;
	fs.DeleteFile("first.txt");
	fs.printTable();

	cout << "Размер second.txt: " << fs.GetFileSize("second.txt") << " Mb" << endl;

	cout << endl << "Дефрагментация: " << endl;
	fs.useRandomAllocator();
	fs.Defragmentate();
	fs.printTable();


	




	system("pause");
}