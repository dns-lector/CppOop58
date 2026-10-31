#pragma once
#include <iostream>

template<typename T>
struct ListNode {
	T data;
	ListNode* prev = NULL;
	ListNode* next = NULL;
};

template<typename T>
class LinkedList {
private:
	ListNode<T>* first = NULL;
	ListNode<T>* last  = NULL;
	size_t size = 0;
public:
	void   add(T data);
	void   insertBefore(T data, size_t index);
	T      remove(size_t index);
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
	if (node == NULL) {
		std::cout << "Empty list, size = " << size << std::endl;
	}
	else {
		std::cout << size << " element(s): ";
		while (node) {
			std::cout << node->data << " ";
			node = node->next;
		}
		std::cout << std::endl;
	}
}

template<typename T>
T LinkedList<T>::remove(size_t index) {
	if (index < size) {
		if (index == 0) {  // видаляємо перший елемент
			ListNode<T>* node = first;  //  first                    last
			T data = node->data;		//   [p|0|n]<->[p|1|n]<->[p|2|n]
			first = first->next;		// NULL        f              NULL
			if (first) {				// first = first->next;
				first->prev = NULL;		// 
			}							//  first last
			delete node;				//   [p|0|n]
			size -= 1;					// NULL   NULL
			if (size == 0) {			// 
				last = NULL;			// 100   200   300  400  
			}							//  1     3     2    4   [200|4|NULL]
			return data;				// 
		}								// [NULL|1|300]  [100|2|200] [300|3|400]

		if (index == size - 1) {        // видаляємо останній елемент
			ListNode<T>* node = last;
			T data = node->data;
			last = last->prev;
			if (last) {
				last->next = NULL;
			}
			delete node;
			size -= 1;
			if (size == 0) {
				first = NULL;
			}
			return data;
		}
		else {  // видалення з середини: ані перший, ані останній
			ListNode<T>* node = first;
			for (size_t i = 0; i < index; ++i) {  //  first      node         last
				node = node->next;                //   [p|0|n]<->[p|1|n]<->[p|2|n]
			}                                     // NULL                       NULL
			node->prev->next = node->next;        //   [p|0|n]<----------->[p|2|n]
			node->next->prev = node->prev;        // [NULL|1|300]  [100|2|200] [300|3|400]
			T data = node->data;                  // [NULL|1|200]              [100|3|400]
			delete node;
			size -= 1;
			return data; 
		}
	}
	else {
		// error
		return T(0);
	}
}
/*
    node
0<-[p|d|n]<->[p|d|n]->0


*/