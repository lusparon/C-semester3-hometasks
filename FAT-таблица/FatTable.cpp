#include "FatTable.h"
#include <ctime>
#include <assert.h>


// N свободных кластеров  расположенных последовательно
uint FatTable::allocate_sequentially(uint n)
{
	if (!n)
		throw std::logic_error("error: file with 0 clusters");
	if (n > this->size_of_free)
		throw std::logic_error("error: not enough space");
	uint cur = find_first_free_from(2);// для find_first_free_from аргумент = 2
	uint res = cur;
	uint first = cur;   // возвращаемое значение функции
	this->size_of_free -= n;
	while (--n) {
		table[cur] = 1;            // пометили кластер #cur занятым
		cur = table[cur] = find_first_free_from(cur); // для find_first_free_from аргумент = cur
	}
	table[cur] = 1;

	return res;
}

// N свободных кластеров  расположенных хаотично
uint FatTable::allocate_randomly(uint n)
{
	if (!n)
		throw std::logic_error("error: file with 0 clusters");
	if (n > this->size_of_free)
		throw std::logic_error("error: not enough space");
	uint cur = find_random_free();
	uint res = cur;
	uint first = cur;   
	this->size_of_free -= n;
	while (--n) {
		table[cur] = 1;           
		cur = table[cur] = find_random_free(); 
	}
	table[cur] = 1;

	return res;
}

//находит индекс первого свободного кластера, начиная с n-го
uint FatTable::find_first_free_from(uint n)
{
	for (int i = n; i < table.size(); i++)
		if (table[i] == 0)
			return i;
}

//находит индекс случайного свободного
uint FatTable::find_random_free()
{
	srand(time(NULL));
	uint a = rand() % (table.size()-2) + 2;
	while (table[a] != 0)
	{
		if (a == table.size() - 1)
			a = 2;
		else a++;
	}
	return a;
}

//Возвращает вектор номеров кластеров файла, по номеру первого кластера этого файла.
vector<uint> FatTable::get_file_clusters_first(uint first)
{
	assert(first <= this->size_of_free+2);
	vector<uint> v;
	while (first != 1)
	{
		v.push_back(first);
		first = this->table[first];
	}
	return v;
}

//Возвращает вектор номеров кластеров файла, по номеру любого кластера этого файла.
vector<uint> FatTable::get_file_clusters_middle(uint middle)
{
	assert(middle <= this->size_of_free + 2);
	uint first = middle;
	middle = find(table.begin() + 2, table.end(), middle) - table.begin();
	while (middle < table.size())
	{
		first = middle;
		middle = find(table.begin() + 2, table.end(), middle) - table.begin();
	}
	return get_file_clusters_first(first);
}

//Удалить все кластеры файла по номеру первого кластера этого файла
void FatTable::delete_file_clusters_first(uint first)
{
	uint next = 0;
	while (next != 1)
	{
		next = table[first];
		table[first] = 0;
		first = next;
		size_of_free++;
	}
	table[next] = 0;
}

//Размер файла, заданного первым кластером, в кластерах.
uint FatTable::get_file_size_first(uint first)
{
	uint count = 0;
	while (first > 1)
	{
		first = table[first];
		count++;
	}
	if (first = 1) count++;
	return count;
}

//Дефрагментировать таблицу
void FatFileSystem::Defragmentate()
{
	FatFileSystem::useSequentialAllocator();
	FatFileSystem cloud(table.get_table_size_mb(cluster_size), cluster_size);
	for (auto x : file_start)
	{
		cloud.CreateFile(x.first, GetFileSize(x.first));
	}
	table = cloud.table;
	swap(this->file_start, cloud.file_start);
	swap(this->cluster_size, cloud.cluster_size);
	swap(this->allocator, cloud.allocator);
}