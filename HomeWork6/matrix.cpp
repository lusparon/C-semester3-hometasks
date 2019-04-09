#include <assert.h>
#include "matrix.h"

void UpperMainDig(int **m, size_t size) {
	for (auto i = 0; i < size; ++i)
		for (auto j = i + 1; j < size; ++j)
			m[i][j] = 0;
}

void SwapMinMax(int *arr, size_t size) {
	assert(arr);
	auto min = arr;
	auto max = arr;
	for (auto i = 1; i < size; ++i) {
		if (arr[i] < *min) min = (arr + i);
		if (arr[i] > *max) max = (arr + i);
	}
	int t = *min;
	*min = *max;
	*max = t;
}

void SwapMinMaxInRows(int **m, size_t rows, size_t cols) {
	assert(m);
	for (auto i = 0; i < rows; ++i) {
		SwapMinMax(m[i], cols);
	}
}