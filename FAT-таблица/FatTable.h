#ifndef FatTable_h
#define FatTable_h
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <functional>
using namespace std;

typedef unsigned int  uint;

class FatTable
{
	vector<uint> table;
	uint size_of_free;
public:
	FatTable(uint size): table(size + 2 , 0 ) , size_of_free(size) {}

	// N свободных кластеров  расположенных последовательно
	uint allocate_sequentially(uint n);

	// N свободных кластеров таблицы случайно.
	uint allocate_randomly(uint n);

	friend ostream & operator<<(ostream & os , FatTable & t)
	{
		t.print(os);
		return os;
	}

	//Возвращает вектор номеров кластеров файла, по номеру первого кластера этого файла.
	vector<uint> get_file_clusters_first(uint first);

	//Возвращает вектор номеров кластеров файла, по номеру любого кластера этого файла.
	vector<uint> get_file_clusters_middle(uint middle);

	//Удалить все кластеры файла по номеру первого кластера этого файла
	void delete_file_clusters_first(uint first);

	//Размер файла, заданного первым кластером, в кластерах.
	uint get_file_size_first(uint first);

	uint get_table_size_mb(uint cluster_size)
	{
		return cluster_size * table.size() / 1024;
	}

private:
	//находит индекс первого свободного кластера, начиная с n-го
	uint find_first_free_from(uint n);

	//находит индекс случайного свободного
	uint find_random_free();

	void print(ostream& os)
	{
		for (int i = 2; i < table.size(); i++)
			os << table[i] << " ; ";
		os << endl;
	}

};

class FatFileSystem
{
	FatTable table;
	map<string, uint> file_start;
	uint cluster_size;
	function<uint(uint)> allocator;
public:
	FatFileSystem(uint tom_size_mb, uint cluster_size_kb = 4) : cluster_size(cluster_size_kb), table(FatTable(tom_size_mb * 1024 / cluster_size_kb))
	{
		allocator = [=](uint N) { return this->table.allocate_sequentially(N); };
	};

	//Создать файл  с заданным именем заданного размера (в мегабайтах)
	void CreateFile(string name, uint size_mb)
	{
		if (size_mb > 0)
		{
			uint begin = allocator(size_mb * 1024 / cluster_size);
			file_start[name] = begin;
		}
	}

	//Установить случайное выделение кластеров
	void useRandomAllocator()
	{
		allocator = [=](uint N) { return this->table.allocate_randomly(N); };
	}

	//Установить последовательное выделение кластеров
	void useSequentialAllocator()
	{
		allocator = [=](uint N) { return this->table.allocate_sequentially(N); };
	}

	//Удалить файл с заданным именем
	void DeleteFile(string i)
	{
		if (file_start.count(i))
			table.delete_file_clusters_first(file_start[i]);
		file_start[i] = 0;
	}

	//Размер файла заданным именем в мегабайтах
	uint GetFileSize(string i)
	{
		if (file_start.count(i))
			return table.get_file_size_first(file_start[i]) * cluster_size / 1024;
		else throw invalid_argument("File does not exist");
	}

	//Дефрагментировать таблицу
	void Defragmentate();

	void printTable()
	{
		cout << "FatFileSystem: ";
		cout << table << endl;
	}
};

#endif FatTable_h

