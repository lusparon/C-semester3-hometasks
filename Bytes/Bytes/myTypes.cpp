#include <iostream>
#include "myTypes.h"
using namespace std;

//по элементу перечисления возвращает размер соответствующего типа
int mySizeOf(Type t)
{
	switch (t) {
	case INT: return sizeof(int);
	case SHORT: return sizeof(short);
	case CHAR: return sizeof(char);
	case BOOL: return sizeof(bool);
	case DOUBLE: return sizeof(double);
	case FLOAT: return sizeof(float);
	}
}
