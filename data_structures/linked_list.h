#pragma once
#include <iostream>

template<typename T>
struct ListNode {
	T data;
	ListNode* prev;
	ListNode* next;
};

template<typename T>
class LinkedList {
private:
	ListNode<T>* first = NULL;
	ListNode<T>* last  = NULL;
	size_t size = 0;
public:
	void add(T data);
	void insertBefore(T data, size_t index);
	size_t getSize() const { return size; }

	void print();
};

// #include "linked_list.cpp"
template<typename T>
void LinkedList<T>::add(T data) {
	if (last) {  //                           |попередній = last
		last->next = new ListNode<T> { data, last, NULL };
		last = last->next;
	}
	else {
		first = last = new ListNode<T> { data, NULL, NULL };
	}
	size += 1;
}

template<typename T>
void LinkedList<T>::insertBefore(T data, size_t index) {
	if (index == 0) {
		// додавання в першу позицію (перед першим)
		if (first) {
			first = first->prev = new ListNode<T>{ data, NULL, first };
			size += 1;
		}
		else {
			add(data);
		}
	}
	else {
		if (index < size) {
			ListNode<T>* node = first;
			for (size_t i = 0; i < index - 1; ++i) {
				node = node->next;
			}
			// зупинились перед index, додаємо після нього
			node->next = new ListNode<T>{ data, node, node->next };
			node->next->next->prev = node->next;
			size += 1;
		}
		else {
			// помилка - index out of range
		}
	}
}

template<typename T>
void LinkedList<T>::print() {
	ListNode<T>* node = first;
	while (node) {
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << std::endl;
}

/*
    node
0<-[p|d|n]<->[p|d|n]->0
*/