#ifndef CSTRING_VECTOR_H
#define CSTRING_VECTOR_H
#define _CRT_SECURE_NO_WARNINGS

#include <cassert>

#include <vector>
#include <iostream>
#include <cstring>
#include <string>

#include "cstring_utils.h"
using namespace std;


char const * DELIM{ ", " };

/* динамический массив —-строк */
class cstring_vector {

	/* массив —-строк */
	char ** data;
	/* логический размер (заполненность) */
	size_t  size;
	/* физический размер (Ємкость) */
	size_t capasity;


public:

	cstring_vector()
	{
		data = new char*[MIN_CAPACITY];
		size = 0;
		capasity = MIN_CAPACITY;
	}

	cstring_vector(char ** cstr_array, size_t size)
	{
		init_from_cstr_array(cstr_array, size);
	}

	cstring_vector(char const ** cstr_array, size_t size)
	{
		init_from_cstr_array(const_cast<char**>(cstr_array), size);
	}

	cstring_vector(std::vector<std::string> v)
	{
		data = new char*[v.size()*CAPACITY_FACTOR];
		for (int i = 0; i < v.size(); i++)
		{
			data[i] = new char[v[i].length() + 1];
			strcpy(data[i], v[i].c_str());
		}
		this->size = v.size();
		this->capasity = v.size() * CAPACITY_FACTOR;

	}

	/* размер массива */
	size_t GetSize() { return size; };

	/* печать содержимого массива */
	void print() const
	{
		assert(data);
		//assert(size <= capacity);
		std::cout << "{";
		if (size)
		{
			for (size_t i = 0; i < size - 1; ++i)
			{
				print_cstring(data[i]);
				std::cout << DELIM;
			}
			print_cstring(data[size - 1]);
		}
		std::cout << "}";
	}

	/* печать содержимого массива */
	void println() const
	{
		print();
		std::cout << std::endl;
	}

	//диструктор
	~cstring_vector()
	{
		if (data != nullptr)
		{
			for (int i = 0; i < size; i++)
			{
				delete[] data[i];
			}
			delete[] data;
		}
	}

	//конструктор копий
	cstring_vector(cstring_vector const & other)
	{
		cout << "¬ызван конструктор копий" << endl;
		this->init_from_cstr_array(other.data, other.size);
	};

	cstring_vector(cstring_vector && other)
	{
		cout << "¬ызван move конструктор" << endl;
		size = other.size;
		data = other.data;
		capasity = other.capasity;
		// Ќе позволит сразу удалить временный объект  
		other.data = nullptr;
	}

	void swap(cstring_vector & c)
	{
		std::swap(this->data, c.data);
		std::swap(this->size, c.size);
		std::swap(this->capasity, c.capasity);
	}

	cstring_vector operator=(cstring_vector && c)
	{
		swap(c);
		return *this;
	}


	//операци€ обращени€ по индексу
	char* operator[](int i) //возможность мен€ть строки: их адреса, их длину, их отдельные символы
	{
		return data[i];
	}

	char* operator[](int i) const
	{
		return data[i];
	}

	void push_back(const char * str)
	{
		if (capasity - size == 0)
			reallocate();
		data[size] = new char[strlen(str)];
		strcpy(data[size], str);
		size++;
	}

	vector<string> convert_to_string_vector()
	{
		vector<string> ss;
		for (int i = 0; i < size; i++)
			ss.push_back(data[i]);
		return ss;
	}

	friend ostream& operator << (ostream& os, const cstring_vector& c)
	{
		if (c.size)
		{
			for (size_t i = 0; i < c.size - 1; ++i)
			{
				os << c.data[i] << DELIM;
			}
			os << c.data[c.size - 1];
		}
		return os;
	}


private:

	const int MIN_CAPACITY = 5;
	const int CAPACITY_FACTOR = 2;

	/* инициализаци€ текущего массива
	   копией массива строк cstr_array из size элементов */
	void init_from_cstr_array(char ** cstr_array, size_t size)
	{
		data = new char*[size * CAPACITY_FACTOR];
		for (int i = 0; i < size; i++)
		{
			data[i] = new char[strlen(cstr_array[i]) + 1];
			strcpy(data[i], cstr_array[i]);
		}
		this->size = size;
		this->capasity = size * CAPACITY_FACTOR;
	}


	void reallocate()
	{
		char ** new_data = new char *[size * CAPACITY_FACTOR];
		copy(data, data + size, new_data);
		for (int i = 0; i < size; i++)
		{
			delete[] data[i];
		}
		delete[] data;
		data = new_data;
		capasity = size * CAPACITY_FACTOR;
	};

};

//читает строки с клавиатуры, пока не будет введена пуста€ строка
cstring_vector read_cstring_vector()
{
	cstring_vector c = cstring_vector();
	char * istr = new char[128];
	cin.getline(istr, 128);
	while (strcmp(istr, "") != 0)
	{
		c.push_back(istr);
		cin.getline(istr, 128);
	}
	return c;
};


/* CSTRING_VECTOR_H */
#endif

