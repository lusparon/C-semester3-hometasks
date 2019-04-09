#include "linked_list.h"
#include <cassert>

double Average(LinkedList<double> *list) {
	auto current = list->Begin();
	double sum = 0;
	int count = 0;
	for (count = 0; current; ++count) {
		sum += current->value;
		current = current->next;
	}
	return sum / count;
}

void AddZeros(LinkedList<double> *list, double n) {
	assert(n > 0);
	auto current = list->Begin();
	while (current) {
		if (current->value < 0) continue;
		if (sqrt(current->value) > n)
			AddAfter<double>(current, 0);
		current = current->next;
	}
}