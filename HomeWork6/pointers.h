#ifndef pointers_h
#define pointers_h

extern int counter;

void ReadAndCount(bool(*pred)(int));

void ZipInt(int *a, int *b, int *c, size_t size, int(*f)(int, int));

void PrintArray(int * a, size_t size);

#endif pointers_h