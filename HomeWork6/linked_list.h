#ifndef linked_list_h
#define linked_list_h

#include <iostream>

template <typename T>
struct Node {
	T value;
	Node<T> *next;
	Node<T> *prev;
	Node(T value_, Node<T>* prev_ = nullptr, Node<T>* next_ = nullptr)
		:value(value_), prev(prev_), next(next_) {}
};

template <typename T>
class LinkedList
{
public:
	LinkedList() : head(nullptr), tail(nullptr) {}

	void PrintLn() {
		auto current = head;
		while (current) {
			std::cout << current->value << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	void Add(T value) {
		if (head == nullptr) {
			head = new Node<T>(value);
			return;
		}
		auto current = head;
		while (current->next) {
			current = current->next;
		}
		current->next = new Node<T>(value, current);
	}

	void Filter(bool(*pred)(T)) {
		auto current = head;
		while (current) {
			auto next = current->next;
			if (!pred(current->value))
				DeleteNode(current);
			current = next;
		}
	}

	void DeleteNode(Node<T> *node) {
		if (head == node) {
			head = node->next;
			if (node->next)
				node->next->prev = nullptr;
			delete node;
			return;
		}
		auto next = node->next;
		auto prev = node->prev;
		if (prev)
			prev->next = next;
		if (next)
			next->prev = prev;
		node->next = nullptr;
		node->prev = nullptr;
		auto old_node = node;
		delete old_node;
	}

	Node<T> *Begin() const {
		return head;
	}

private:
	Node<T> *head;
	Node<T> *tail;
	~LinkedList() {
		while (head != tail) {
			auto current = head;
			head = current->next;
			delete current;
		}
		delete tail;
	}
};

template <typename T>
LinkedList<T>* ReadList(size_t count) {
	if (count <= 0) return nullptr;
	LinkedList<T> * result = new LinkedList<T>();
	for (auto i = 0; i < count; ++i) {
		T value;
		std::cin >> value;
		result->Add(value);
	}
	return result;
}

template <typename T>
void AddAfter(Node<T> *node, T value) {
	auto next = node->next;
	auto new_node = new Node<T>(value, node, next);
	node->next = new_node;
	if (next)
		next->prev = new_node;
}

double Average(LinkedList<double> *list);

void AddZeros(LinkedList<double> *list, double n);

#endif linked_list_h

