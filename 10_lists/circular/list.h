// =================================================================
//
// File: CircularList.h
// Author:
// Description: This file contains the implementation of a TDA CircularList
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef CircularList_H
#define CircularList_H

#include <string>
#include <sstream>
#include "exception.h"
#include "header.h"

template <class T> class CircularList;

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class Node {
private:
	Node(T);
	Node(T, Node<T>*);

	T	    value;
	Node<T> *next;

	friend class CircularList<T>;
};

// =================================================================
// Constructor. Initializes the value of the node. The variable next
// is initialized to null.
//
// @param val, stored value in the node.
// =================================================================
template <class T>
Node<T>::Node(T val) : value(val), next(NULL) {
}

// =================================================================
// Constructor. Initializes both instance variables.
//
// @param val, stored value in the node.
// @param nxt, the next node.
// =================================================================
template <class T>
Node<T>::Node(T val, Node* nxt) : value(val), next(nxt) {
}

// =================================================================
// Definition of the CircularList class
// =================================================================
template <class T>
class CircularList {
private:
	Node<T> *head, *tail;
	Node<T> *previous, *current;
	bool 		traversing;

public:
	CircularList();
	~CircularList();

	bool empty() const;
	bool contains(T) const;
	void clear();
	std::string toString() const;

	void push_back(T);
	T 	 pop_front();
};

// =================================================================
// Constructor. Initializes both instance variables to zero.
// =================================================================
template <class T>
CircularList<T>::CircularList()
	: head(NULL), tail(NULL), previous(NULL), current(NULL), traversing(false) {
}

// =================================================================
// Destructor. Remove all items from the CircularList.
// =================================================================
template <class T>
CircularList<T>::~CircularList() {
	clear();
}

// =================================================================
// Returns if the CircularList is empty or not
//
// @returns true if the CircularList is empty, false otherwise.
// =================================================================
template <class T>
bool CircularList<T>::empty() const {
	return (head == NULL);
}

// =================================================================
// Determines if an item is in the CircularList.
//
// @param val, the searched element
// @returns true if val is in the CircularList, false otherwise
// =================================================================
template <class T>
bool CircularList<T>::contains(T val) const {
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

// =================================================================
// Remove all items from the CircularList.
// =================================================================
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
	head = NULL;
}

// =================================================================
// String representation of the elements in the CircularList.
//
// @returns a string containing all the elements of the CircularList.
// =================================================================
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

// =================================================================
// Add an item to the beginning of the CircularList. Increase the size of
// the CircularList.
//
// @param val, the elemento to be inserted.
// =================================================================
template <class T>
void CircularList<T>::push_back(T val) {
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

// =================================================================
// Delete the item at the beginning of the CircularList.
//
// @returns the element that was at the beginning of the CircularList.
// @throws NoSuchElement if the CircularList is empty
// =================================================================
template <class T>
T CircularList<T>::pop_front() {
	T val;
	Node<T> *p;

	if (empty()) {
		throw NoSuchElement();
	}

	p = head;
	if (head == tail) {
		head = NULL;
		tail = NULL;
	} else {
		head = p->next;
		tail->next = p->next;
	}
	val = p->value;

	delete p;

	return val;
}
#endif /* CircularList_H */
