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
public:
	void add(T data);
	void insertBefore(T data, size_t index);

	void print();
};

// #include "linked_list.cpp"
template<typename T>
void LinkedList<T>::add(T data) {
	if (first) {
		// шукаємо останній
		ListNode<T>* node = first;
		while (node->next != NULL) {
			node = node->next;
		}
		// після циклу node вказує на останній елемент списку
		// 
		//                                    |попередній = node
		node->next = new ListNode<T> { data, node, NULL };
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