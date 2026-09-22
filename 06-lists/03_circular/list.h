// =================================================================
//
// File: CircularList.h
// Author: Pedro Perez
// Description: This file contains the implementation of a TDA CircularList
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef CircularList_H
#define CircularList_H

#include <string>
#include <sstream>
#include <stdexcept>
#include <utility>

typedef unsigned int uint;

template <class T> class CircularList;

template <class T>
class Node {
private:
	Node(T);
	Node(T, Node<T>*);

	T	    value;
	Node<T> *next;

	friend class CircularList<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), next(nullptr) {
}

template <class T>
Node<T>::Node(T val, Node* nxt) : value(val), next(nxt) {
}

template <class T>
class CircularList {
private:
	Node<T> *head, *tail;

public:
	CircularList();
	~CircularList();

	bool empty() const;
	bool contains(const T&) const;
	void clear();
	std::string toString() const;

	void push_back(const T&);
	T 	 pop_front();
};

template <class T>
CircularList<T>::CircularList()
	: head(nullptr), tail(nullptr) {
}

template <class T>
CircularList<T>::~CircularList() {
	clear();
}

template <class T>
bool CircularList<T>::empty() const {
	return (head == nullptr);
}

template <class T>
bool CircularList<T>::contains(const T& val) const {
	Node<T> *p;

	if (empty()) {
		return false;
	}

	p = head;
	do {
		if (p->value == val) {
			return true;
		}
		p = p->next;
	} while (p != head);
	return false;
}

template <class T>
void CircularList<T>::clear() {
	Node<T> *q, *p;

	if (empty()) {
		return;
	}

	p = head->next;
	while (p != head) {
		q = p->next;
		delete(p);
		p = q;
	}
	delete head;
	head = nullptr;
	tail = nullptr;
}

template <class T>
std::string CircularList<T>::toString() const {
	std::stringstream aux;
	Node<T> *p;

	if (empty()) {
		aux << "[]";
	} else {
		aux << "[";
		p = head;
		do {
			aux << p->value;
			if (p->next != head) {
				aux << ", ";
			}
			p = p->next;
		} while (p != head);
		aux << "]";
	}
	return aux.str();
}

template <class T>
void CircularList<T>::push_back(const T& val) {
	Node<T> *p;

	p = new Node<T>(val);
	if (empty()) {
		head = p;
	} else {
		tail->next = p;
	}
	tail = p;
	tail->next = head;
}

template <class T>
T CircularList<T>::pop_front() {
	if (empty()) {
		throw std::out_of_range("No Such Element");
	}

	Node<T> *p = head;
	T val = p->value;
	
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
	} else {
		head = p->next;
		tail->next = p->next;
	}
	val = p->value;

	delete p;

	return val;
}
#endif /* CircularList_H */
