// =================================================================
//
// File: dequeue.h
// Author: Pedro Perez
// Description: This file contains the implementation of TDA
//							Dequeue (a double ended queue).
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
#include "header.h"

template <class T> class Dequeue;

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class Node {
private:
	Node(T);
	Node(T, Node<T>*, Node<T>*);

	T	    	value;
	Node<T> *previous;
	Node<T> *next;

	friend class Dequeue<T>;
};

// =================================================================
// Constructor. Initializes the value of the node. The variables
// previous and next a initialized to null.
//
// @param val, stored value in the node.
// =================================================================
template <class T>
Node<T>::Node(T val)
	: value(val), previous(0), next(0) {}

// =================================================================
// Constructor. Initializes both instance variables.
//
// @param val, stored value in the node.
// @param nxt, the next node.
// =================================================================
template <class T>
Node<T>::Node(T val, Node *prev, Node* nxt)
	: value(val), previous(prev), next(nxt) {}

// =================================================================
// Definition of the Dequeue class
// =================================================================
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

	T    front() const;
	T		 last() const;

	void push_front(T);
	void push_back(T);

	void pop_front();
	void pop_back();

	std::string toString() const;
};

// =================================================================
// Constructor. Initializes both instance variables to zero.
// =================================================================
template <class T>
Dequeue<T>::Dequeue()
	: head(NULL), tail(NULL), size(0) {}

// =================================================================
// Destructor. Remove all items from the DoubleLinkedList.
// =================================================================
template <class T>
Dequeue<T>::~Dequeue() {
	clear();
}

// =================================================================
// Returns if the Dequeue is empty or not
//
// @returns true if the head and tail are NULL, false otherwise.
// =================================================================
template <class T>
bool Dequeue<T>::empty() const {
	return (head == NULL && tail == NULL);
}

// =================================================================
// Returns the number of items in the Dequeue.
//
// @returns size, the number of items in the Dequeue.
// =================================================================
template <class T>
uint Dequeue<T>::length() const {
	return size;
}

// =================================================================
// Determines if an item is in the Dequeue.
//
// @returns true if val is in the Dequeue, false otherwise
// =================================================================
template <class T>
bool Dequeue<T>::contains(T val) const {
	Node<T> *p;

	p = head;
	while (p != NULL) {
		if (p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}

// =================================================================
// Remove all items from the DoubleLinkedList.
// =================================================================
template <class T>
void Dequeue<T>::clear() {
	Node<T> *p, *q;

	p = head;
	while (p != NULL) {
		q = p->next;
		delete p;
		p = q;
	}
	head = NULL;
	tail = NULL;
	size = 0;
}

// =================================================================
// Returns the first item in the list.
//
// @returns the object T referenced by head.
// @throws NoSuchElement, if the list is empty.
// =================================================================
template <class T>
T Dequeue<T>::front() const {
	if (empty()) {
		throw NoSuchElement();
	}
	return head->value;
}


// =================================================================
// Returns the last item in the list.
//
// @returns the object T referenced by tail.
// @throws NoSuchElement, if the list is empty.
// =================================================================
template <class T>
T Dequeue<T>::last() const {
	if (empty()) {
		throw NoSuchElement();
	}
	return tail->value;
}

// =================================================================
// Add an item to the beginning of the list. Increase the size of
// the list.
// =================================================================
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

// =================================================================
// Add an item to the end of the list. Increase the size of
// the list.
// =================================================================
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

// =================================================================
// Delete the item at the beginning of the list.
//
// @returns the element referenced by head.
// @throws NoSuchElement if the list is empty
// =================================================================
template <class T>
void Dequeue<T>::pop_front() {
	Node<T> *p;
	T val;

	if (empty()) {
		throw NoSuchElement();
	}

	p = head;
	val = p->value;
	if (head == tail) {
		head = NULL;
		tail = NULL;
	} else {
		head = p->next;
		p->next->previous = NULL;
	}
	delete p;
	size--;
}

// =================================================================
// Delete the item at the beginning of the list.
//
// @returns the element referenced by tail.
// @throws NoSuchElement if the list is empty
// =================================================================
template <class T>
void Dequeue<T>::pop_back() {
	T val;
	Node<T> *p;

	if (empty()) {
		throw NoSuchElement();
	}

	p = tail;
	val = p->value;
	if (head == tail) {
		head = NULL;
		tail = NULL;
	} else {
		tail = p->previous;
		p->previous->next = NULL;
	}
	delete p;
	size--;
}

// =================================================================
// String representation of the elements in the list.
//
// @returns a string containing all the elements of the list.
// =================================================================
template <class T>
std::string Dequeue<T>::toString() const {
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
