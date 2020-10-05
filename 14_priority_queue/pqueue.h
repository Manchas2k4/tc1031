// =================================================================
//
// File: bubble.h
// Author: Pedro Perez
// Description: This file contains the implementation of the
//				bubble sort.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#ifndef PQUEUE_H
#define PQUEUE_H

#include <string>
#include <sstream>
#include "exception.h"
#include "queue.h"

using namespace std;

typedef unsigned int uint;

template <class T> class PriorityQueue;

/* Declaration of the Node class */
template <class T>
class Node {
private:
	Node(T);
	Node(T, Node<T>*, Node<T>*);

	T	    value;
	Node<T> *previous;
	Node<T> *next;

	friend class PriorityQueue<T>;
};

/* Implementation of the Node class */
template <class T>
Node<T>::Node(T val)
	: value(val), previous(0), next(0) {}

template <class T>
Node<T>::Node(T val, Node *prev, Node* nxt)
	: value(val), previous(prev), next(nxt) {}

	/* Declaration of the PriorityQueue class */
	template <class T>
	class PriorityQueue : public Queue<T>{
	private:
		Node<T> *head;
		Node<T> *tail;

	public:
		PriorityQueue();
		~PriorityQueue();

		bool contains(T) const;

		void enqueue(T);
		void dequeue();
		T front() const;
		bool empty() const;
		void clear();
		string toString() const;
	};

/* Implementation of the PriorityQueue clas */
template <class T>
PriorityQueue<T>::PriorityQueue()
	: head(0), tail(0) {}

template <class T>
PriorityQueue<T>::~PriorityQueue() {
	clear();
}

template <class T>
bool PriorityQueue<T>::contains(T val) const {
	Node<T> *p;

	p = head;
	while (p != 0) {
		if (p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}

template <class T>
void PriorityQueue<T>::enqueue(T val) {
    Node<T> *p, *q, *new_link;

		new_link = new Node<T>(val);
		if (empty()) {
			head = new_link;
			tail = new_link;
			return;
    }

		if (val < head->value) {
			new_link->next = head;
			head->previous = new_link;
			head = new_link;
			return;
		}

		if (val >= tail->value) {
			new_link->previous = tail;
      tail->next= new_link;
      tail = new_link;
			return;
		}

		p = head;
		while (p != NULL && p->value < val) {
			p = p->next;
		}

		q = p->previous;
		new_link->next = p;
		new_link->previous = q;

		q->next = new_link;
		p->previous = new_link;
}

template <class T>
void PriorityQueue<T>::dequeue() {
    T val;
    Node<T> *p;

    if (empty()) {
        throw NoSuchElement();
    }

    p = head;
    val = p->value;
    if (head == tail) {
        head = 0;
        tail = 0;
    } else {
        head = p->next;
        p->next->previous = 0;
    }
    delete p;
}

template <class T>
T PriorityQueue<T>::front() const {
	if (empty()) {
		throw NoSuchElement();
	}
	return head->value;
}

template <class T>
bool PriorityQueue<T>::empty() const {
	return (head == 0 && tail == 0);
}

template <class T>
void PriorityQueue<T>::clear() {
	Node<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
}

template <class T>
string PriorityQueue<T>::toString() const {
	std::stringstream aux;
	Node<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}
#endif /* PQUEUE_H */
