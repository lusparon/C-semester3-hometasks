#include <iostream>
#include "pointers.h"

int counter;

void ReadAndCount(bool(*pred)(int)) {
	counter = 0;
	while (true) {
		int value;
		std::cin >> value;
		if (value == 0) break;
		counter += pred(value);
	}
}
void ZipInt(int *a, int *b, int *c, size_t size, int(*f)(int, int)) {
	for (auto i = 0; i < size; ++i) {
		c[i] = f(a[i], b[i]);
	}
}

void PrintArray(int * a, size_t size)
{
	for (int i = 0; i < size; ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}