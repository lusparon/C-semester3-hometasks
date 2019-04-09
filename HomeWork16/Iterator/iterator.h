#ifndef iterator_h
#define iterator_h
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <set>
#include <map>
using namespace std;

template <typename T>
void printList(std::list<T> l)
{
	for (auto x : l)
		std::cout << x << "\n";
	std::cout << std::endl;
}

template <typename T, typename C>
void printSet(std::set<T, C> s)
{
	for (auto x : s)
		std::cout << x << "\n";
	std::cout << std::endl;
}

class Person
{
public:
	Person(string name_, int age_) :
		name(name_), age(age_) {}

	string getName() const
	{
		return name;
	}

	int getAge() const
	{
		return age;
	}

	bool operator<(const Person & p) const
	{
		auto c = name.compare(p.name);
		return c < 0 ||
			(c == 0 && age << p.age);
	}

	bool operator==(const Person & p) const
	{
		return name == p.name && age == p.age;
	}

	operator string() const
	{
		return name + " " + to_string(age);
	}

private:
	string name;
	int age;
};

ostream & operator<< (ostream & stream, const Person & p)
{
	stream << p.getName() << ", age:" << p.getAge();
	return stream;
}

struct PersonLess
{
	bool operator()(const Person & p1, const Person & p2) const
	{
		auto n1 = p1.getName();
		auto n2 = p2.getName();
		auto c = n1.compare(n2);
		return  c < 0 ||
			(c == 0 && p1.getAge() < p2.getAge());
	}
};

void sortPersons(list<Person> & l)
{
	
	PersonLess comp;
	auto pr = [comp](Person p1, Person p2) {return comp(p1, p2); };
	l.sort(pr);
}

int fillPersonSetFromFile(string file, set<Person, PersonLess> & s)
{
	fstream stream(file);
	int c = 0;
	while (!stream.eof())
	{
		string name; stream >> name;
		int age; stream >> age;
		Person p(name, age);
		if (s.insert(p).second)
			c++;
	}
	return c;
}

void compareTwoPersonFiles(string f1, string f2)
{
	set<Person, PersonLess> s1, s2;
	fillPersonSetFromFile(f1, s1);
	fillPersonSetFromFile(f2, s2);
	for (auto p : s1)
	{
		if (s2.find(p) != s2.end())
			cout << p << "\n";
	}
}

#endif iterator_h



