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
		size += 1;
	}
	else {
		first = new ListNode<T> { data, NULL, NULL };
	}
}

template<typename T>
void LinkedList<T>::insertBefore(T data, size_t index) {

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