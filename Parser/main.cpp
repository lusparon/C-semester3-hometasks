#include "Parser.h"
#include <assert.h>

void main()
{
	setlocale(LC_ALL,"RUSSIAN");

	// * - + находятся в файле операторов
	/*Parser p("fname.txt");
	p.data.input = " 35   * ( 4 - 11   ) + 27";

	Token * t = p.nextToken();
	assert((string)(*t) == "35");
	assert(dynamic_cast<Number *>(t));
	delete t;

	t = p.nextToken();
	assert((string)(*t) == "*");
	assert(dynamic_cast<Op *>(t));
	delete t;

	t = p.nextToken();
	assert((string)(*t) == "(");
	assert(dynamic_cast<LeftPar *>(t));
	delete t;

	t = p.nextToken();
	assert((string)(*t) == "4");
	assert(dynamic_cast<Number *>(t));
	delete t;

	t = p.nextToken();
	assert((string)(*t) == "-");
	assert(dynamic_cast<Op *>(t));
	delete t;

	t = p.nextToken();
	assert((string)(*t) == "11");
	assert(dynamic_cast<Number *>(t));
	delete t;

	t = p.nextToken();
	assert((string)(*t) == ")");
	assert(dynamic_cast<RightPar *>(t));
	delete t;

	// при обработке строк ниже должны выбрасываться исключения

	p.data.input = "4566q";
	p.currentPos = 0;
	try
	{
		t = p.nextToken();
		assert(false);
		delete t;
	}
	catch (std::exception) {}

	p.data.input = "yu";
	p.currentPos = 0;
	try
	{
		t = p.nextToken();
		assert(false);
		delete t;
	}
	catch (std::exception) {}

	// оператора &&& в файле операторов нет
	p.data.input = " 35   &&& 4";
	p.currentPos = 0;
	t = p.nextToken();
	delete t;
	try
	{
		t = p.nextToken();
		assert(false);
		delete t;
	}
	catch (std::exception) {}*/



	system("pause");
}