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

#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <string>
#include <sstream>
#include "exception.h"

using namespace std;

typedef unsigned int uint;

template <class T> class Dequeue;

/* Declaration of the Node class */
template <class T>
class Node {
private:
	Node(T);
	Node(T, Node<T>*, Node<T>*);

	T	    value;
	Node<T> *previous;
	Node<T> *next;

	friend class Dequeue<T>;
};

/* Implementation of the Node class */
template <class T>
Node<T>::Node(T val)
	: value(val), previous(0), next(0) {}

template <class T>
Node<T>::Node(T val, Node *prev, Node* nxt)
	: value(val), previous(prev), next(nxt) {}

	/* Declaration of the Dequeue class */
	template <class T>
	class Dequeue {
	private:
		Node<T> *head;
		Node<T> *tail;
		uint 	 size;

	public:
		Dequeue();
		~Dequeue();

		bool empty() const;
		uint length() const;
		bool contains(T) const;
		void clear();
		T    get(uint) const;

		T    front() const;
		T		 back() const;

		void push_front(T);
		void push_back(T);

		T    remove_front();
		T    remove_back();

		string toString() const;
	};

/* Implementation of the Dequeue clas */
template <class T>
Dequeue<T>::Dequeue()
	: head(0), tail(0), size(0) {}

template <class T>
Dequeue<T>::~Dequeue() {
	clear();
}

template <class T>
bool Dequeue<T>::empty() const {
	return (head == 0 && tail == 0);
}

template <class T>
uint Dequeue<T>::length() const {
	return size;
}

template <class T>
bool Dequeue<T>::contains(T val) const {
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
void Dequeue<T>::clear() {
	Node<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}

template <class T>
T Dequeue<T>::get(uint index) const {
	uint pos;
	Node<T> *p;

	if (index >= size) {
		throw IndexOutOfBounds();
	}

	if (index == 0) {
		return front();
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	return p->value;
}

template <class T>
T Dequeue<T>::front() const {
	if (empty()) {
		throw NoSuchElement();
	}
	return head->value;
}

template <class T>
T Dequeue<T>::back() const {
	if (empty()) {
		throw NoSuchElement();
	}
	return tail->value;
}


template <class T>
void Dequeue<T>::push_front(T val) {
    Node<T> *new_link;
    new_link = new Node<T>(val);

    if (empty()) {
        head = new_link;
        tail = new_link;
    } else {
        new_link->next = head;
        head->previous = new_link;
        head = new_link;
    }
    size++;
}

template <class T>
void Dequeue<T>::push_back(T val) {
    Node<T> *new_link;
    new_link = new Node<T>(val);

    if (empty()) {
        head = new_link;
        tail = new_link;
    } else {
        new_link->previous = tail;
        tail->next= new_link;
        tail = new_link;
    }
    size++;
}

template <class T>
T Dequeue<T>::remove_front() {
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
    size--;
    return val;
}

template <class T>
string Dequeue<T>::toString() const {
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
#endif /* DEQUEUE_H */
