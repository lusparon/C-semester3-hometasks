#ifndef rsaed_files_h
#define rsaed_files_h
#include <iostream>
#include <assert.h>
#include <NTL/ZZ.h>
#include <cstdio>
#include <string.h>
#include "rsa.h"
#include <fstream>
#include <type_traits>
using namespace NTL;
using namespace std;

//шифрованный файл на запись
class rsaed_ofile
{
	FILE * _file;
	PubKey _key;
	unsigned char * buf;
	int buf_size;
	int buf_size_plain;
	int buf_occupied;

public:
	//конструктор
	rsaed_ofile(const string & name, const string & RSAname = "id_rsa.pub") 
	{
		_file = fopen(name.c_str(), "wb");
		ifstream ifs(RSAname);
		//ZZ e, n;
		ifs >> _key.e >> _key.n;
		//ifs >> n;
		//_key.e = e;
		//_key.n = n;
		buf_size = NTL::NumBytes(_key.n);
		buf = new unsigned char[buf_size];
		buf_size_plain = buf_size - 1;
		buf_occupied = 0;
	}

	//диструктор
	~rsaed_ofile()
	{
		if (buf_occupied > 0)
			flush_buffer();
		fclose(_file);
		delete[] buf;
	}

	rsaed_ofile(rsaed_ofile && name) = delete;

	// запись в шифрованный файл целого значени€
	template<typename T>
	rsaed_ofile & operator<<(T const & t)
	{
		//static_assert(!is_pod<T>::value || is_pointer<T *>::value);
		T t1 = t;
		n_bytes_to_buffer(&t1, sizeof(T));
		return *this;
	}


private:

	// поместить в буффер n байт из пам€ти по адресу p
	void n_bytes_to_buffer(void * p, int n)
	{
		auto q = static_cast<unsigned char *>(p);
		for (int i = 0; i < n; ++i)                 // побайтова€ запись с контролем границы буфера
		{
			if (buf_occupied == buf_size_plain)
				flush_buffer();
			buf[buf_occupied++] = *q++;
		}
		flush_buffer();//....
	}

	// сброс содержимого буфера в файл с предварительным шифрованием
	void flush_buffer()
	{
		ZZ m = NTL::ZZFromBytes(buf, buf_occupied);  // buf_occupied -- количество байт исходных данных
		ZZ mrca = PowerMod(m, _key.e, _key.n); // шифрограмма
		NTL::BytesFromZZ(buf, mrca, buf_size);       // размер шифрограммы Ч buf_size
		fwrite(buf, sizeof(char), buf_size, _file);
		buf_occupied = 0;
	}

};

//шифрованный файл на чтение
class rsaed_ifile
{
	FILE * _file;
	PrivateKey _key;
	unsigned char * buf;
	int buf_size;
	int buf_size_plain;
	int buf_consumed;

public:
	//конструктор
	rsaed_ifile(const string & name, const string & RSAname = "id_rsa") 
	{
		_file = fopen(name.c_str(), "rb");
		if (_file == 0)
			throw std::runtime_error("<file doesn't exist>");
		ifstream ifs(RSAname);
		ZZ d, n;
		ifs >> d;
		ifs >> n;
		_key.d = d;
		_key.n = n;
		buf_size = NTL::NumBytes(n);
		buf = new unsigned char[buf_size];
		buf_size_plain = buf_size - 1;
		buf_consumed = buf_size_plain;
	}

	//диструктор
	~rsaed_ifile()
	{
		fclose(_file);
		delete[] buf;
	}

	rsaed_ifile(rsaed_ifile && name) = delete;

	template<typename T>
	rsaed_ifile & operator>>(T & t)
	{
		//static_assert(!is_pod<T>::value || is_pointer<T *>::value);
		n_bytes_from_buffer(&t, sizeof(T));
		return reinterpret_cast<rsaed_ifile &>(*this);
	}

private:

	// поместить в буффер n байт из пам€ти по адресу p
	void n_bytes_from_buffer(void * p, int n)
	{
		auto q = static_cast<unsigned char *>(p);
		load_buffer();
		for (int i = 0; i < n; ++i)                 // побайтова€ запись с контролем границы буфера
		{
			*q++ = buf[buf_consumed++];
			if (buf_consumed == buf_size_plain)
				load_buffer();
		}
		p = q;
	}

	// сброс содержимого буфера в файл с предварительным шифрованием
	void load_buffer()
	{
		buf_consumed = 0;
		fread(buf, sizeof(char), buf_size, _file);
		ZZ mrca;
		NTL::ZZFromBytes(mrca, buf, buf_size);       // размер шифрограммы Ч buf_size
		mrca = PowerMod(mrca, _key.d, _key.n); // шифрограмма
		NTL::BytesFromZZ(buf, mrca, buf_size);  // buf_occupied -- количество байт исходных данных
	}

};


#endif rsaed_files_h

