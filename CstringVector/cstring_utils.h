#ifndef CSTRINGS_UTILS_H
#define CSTRINGS_UTILS_H

#include <iostream>

char const * QUOTE{ "\"" };

/* �������� ������, ���������� � ������� */
inline void print_cstring(const char * str)
{
	std::cout << QUOTE << str << QUOTE;
}


/* CSTRINGS_UTILS_H */
#endif
