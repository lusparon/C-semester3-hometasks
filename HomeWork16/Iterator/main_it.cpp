#include "iterator.h"

int main()
{
	Person p("abc", 5);
	cout << p;

	list<Person> l{
		Person{ "c", 2},
		Person{ "a", 2 },
		Person{ "1", 2 },
		Person{ "b", 2 },
		Person{ "a", 3 },
		Person{ "a", 1 }
	};
	cout << endl;

	cout << "Sorted list:\n";
	sortPersons(l);
	printList(l);

	set<Person,PersonLess> s;
	cout << "Set from file:\n";
	cout << "from first inc:" << fillPersonSetFromFile("names.txt", s) << "\n";
	cout << "from second inc:" << fillPersonSetFromFile("names1.txt", s) << "\n";
	printSet(s);

	compareTwoPersonFiles("names.txt", "names1.txt");

	system("pause");
}