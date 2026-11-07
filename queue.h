#pragma once
#include "data_structures/linked_list.h"
#include <stdexcept>

// реалізація структури даних "черга"
template<typename T>
class Queue {
private:
	LinkedList<T>* queue = NULL;
public:
	void enqueue(T data) {  // поставити в чергу
		queue->add(data);
	}

	T dequeue() {   // вилучити з черги (черговий елемент)
		if (getLength() > 0) {
			return queue->remove(0);
		}
		else {
			throw std::length_error("Queue<T>::dequeue(): Dequeue requested for empty queue");
		}
	}

	size_t getLength() {
		return queue->getSize();
	}

	bool isEmpty() {
		return getLength() == 0;
	}

	Queue() {
		queue = new LinkedList<T>();
	}
	Queue(const Queue<T>& other) {
		// this->queue = other->queue; - неправильно, це друге посилання на один ресурс
		// "глибоке" копіювання - створення повної копії ресурсу (переліку)
		// див. linked_list::clone
		this->queue = other.queue->clone();
		std::cout << "Queue copied" << std::endl;
	}
	Queue(Queue<T>&& other) noexcept {
		this->queue = other.queue;
		other.queue = NULL;
		std::cout << "Queue moved" << std::endl;
	}
	~Queue() {
		if(queue) delete queue;
	}
};
/*
Глибоке копіювання.
Q1
 *list1
   *first1 --> [p|d|n]<-->[p|d|n]...[]
   *last1 -------------------------->

Q2 = Q1 - зробити копію, так, щоб зміни, внесені до Q1 ніяк
не відбивались на Q2 і навпаки

a) без зусиль: Q2 = Q1
Q2
 *list2 = *list1 - копія поля, але з тим же значенням
 копія адреси не копіює об'єкт, а створює друге посилання на нього

б) клонуємо "перший рівень"
Q2
 *list2 = new List(list1)
                *first2 = *first1 -- об'єкт "список" інший, але 
				має ті ж посилання на дані

в) глибоке копіювання - реалізація повної копії даних 
*/