#ifndef matrix_h
#define matrix_h
#include <assert.h>

template<typename T>
bool MatrixEqual(T **m1, size_t rows1, size_t cols1, T **m2, size_t rows2, size_t cols2) {
	assert(m1); assert(m2);
	if (rows1 != rows2 || cols1 != cols2) return false;
	for (auto i = 0; i < rows1; ++i) {
		for (auto j = 0; j < cols1; ++j) {
			if (m1[i][j] != m2[i][j]) return false;
		}
	}
	return true;
}

void UpperMainDig(int **m, size_t size);
void SwapMinMaxInRows(int **m, size_t rows, size_t cols);
#endif matrix_h
