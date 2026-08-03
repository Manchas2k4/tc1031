// =================================================================
//
// File: list.h
// Author:
// Description: This file contains the implementation of a TDA List.
//              This code was developed solely for educational 
//              purposes.
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

/**
 * @file list.h
 * @brief Defines a generic singly linked list abstract data type.
 *
 * This file contains the declaration and implementation of a templated
 * linked list structure. The list stores elements dynamically using nodes
 * connected through pointers.
 *
 * The implementation provides operations for inserting, removing, searching,
 * accessing elements, copying lists, and generating a string representation.
 *
 * @note This implementation was developed for educational purposes.
 */

#ifndef LIST_H
#define LIST_H

#include <string>
#include <sstream>
#include <stdexcept>

/**
 * @brief Alias used for unsigned integer values.
 */
typedef unsigned int uint;

template <class T> class List;

/**
 * @class Node
 * @brief Represents an internal node of the linked list.
 *
 * Each node stores a value and a pointer to the next node in the list.
 * Nodes are managed internally by the List class.
 *
 * @tparam T Data type stored by the node.
 */
template <class T>
class Node {
private:
	/**
	 * @brief Creates a node containing a value without a next node.
	 *
	 * @param val Value stored in the node.
	 */
	Node(T);

	/**
	 * @brief Creates a node containing a value and a next node reference.
	 *
	 * @param val Value stored in the node.
	 * @param nxt Pointer to the next node.
	 */
	Node(T, Node<T>*);

	/**
	 * @brief Value stored in the node.
	 */
	T	    value;

	/**
	 * @brief Pointer to the next node in the list.
	 */
	Node<T> *next;

	friend class List<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), next(nullptr) {
}


template <class T>
Node<T>::Node(T val, Node* nxt) : value(val), next(nxt) {
}


/**
 * @class List
 * @brief Implements a generic singly linked list.
 *
 * The List class provides a collection of elements stored sequentially using
 * dynamically allocated nodes. The first node is referenced by head and the
 * number of stored elements is tracked by size.
 *
 * @tparam T Type of elements stored in the list.
 *
 * @note The type T must support the operations required by the implemented
 * methods, such as comparison and stream insertion.
 */
template <class T>
class List {
private:
	/**
	 * @brief Pointer to the first node in the list.
	 */
	Node<T> *head;

	/**
	 * @brief Number of elements currently stored.
	 */
	uint size;

public:

	/**
	 * @brief Creates an empty list.
	 */
	List();

	/**
	 * @brief Creates a copy of an existing list.
	 *
	 * @param other List used as source for the copy.
	 */
	List(const List<T>&);

	/**
	 * @brief Releases all resources used by the list.
	 */
	~List();

	/**
	 * @brief Assigns another list to the current list.
	 *
	 * @param other List to copy.
	 *
	 * @return Reference to the current list.
	 */
	List<T>& operator=(const List<T>&);

	/**
	 * @brief Returns the number of elements stored in the list.
	 *
	 * @return Current list length.
	 */
	uint length() const;

	/**
	 * @brief Checks whether the list is empty.
	 *
	 * @return true if the list contains no elements, false otherwise.
	 */
	bool empty() const;

	/**
	 * @brief Checks whether a value exists in the list.
	 *
	 * @param val Value to search.
	 *
	 * @return true if the value exists, false otherwise.
	 */
	bool contains(const T&) const;

	/**
	 * @brief Removes all elements from the list.
	 *
	 * Releases all allocated nodes and resets the list to an empty state.
	 */
	void clear();

	/**
	 * @brief Creates a string representation of the list.
	 *
	 * @return String containing all elements in list order.
	 */
	std::string toString() const;

	/**
	 * @brief Returns the first element in the list.
	 *
	 * @return Constant reference to the first stored value.
	 *
	 * @throws std::out_of_range If the list is empty.
	 */
	const T& front() const;

	/**
	 * @brief Returns the last element in the list.
	 *
	 * @return Constant reference to the last stored value.
	 *
	 * @throws std::out_of_range If the list is empty.
	 */
	const T& last() const;

	/**
	 * @brief Returns the element located at a specific index.
	 *
	 * @param index Position of the element.
	 *
	 * @return Constant reference to the requested element.
	 *
	 * @note The current implementation is incomplete.
	 */
	const T& get(uint) const;

	/**
	 * @brief Inserts an element at the beginning of the list.
	 *
	 * @param val Value to insert.
	 */
	void push_front(const T&);

	/**
	 * @brief Inserts an element at the end of the list.
	 *
	 * @param val Value to insert.
	 */
	void push_back(const T&);

	/**
	 * @brief Inserts an element at a specific index.
	 *
	 * @param val Value to insert.
	 * @param index Position where the element will be inserted.
	 *
	 * @note The current implementation is incomplete.
	 */
	void insert_at(const T&, uint);

	/**
	 * @brief Removes the first element of the list.
	 *
	 * @throws std::out_of_range If the list is empty.
	 */
	void pop_front();

	/**
	 * @brief Removes the last element of the list.
	 *
	 * @throws std::out_of_range If the list is empty.
	 */
	void pop_back();

	/**
	 * @brief Removes an element at a specific index.
	 *
	 * @param index Position of the element to remove.
	 *
	 * @note The current implementation is incomplete.
	 */
	void remove_at(uint);

	/**
	 * @brief Finds the index of the first occurrence of a value.
	 *
	 * @param val Value to search.
	 *
	 * @return Index of the first occurrence, or -1 if not found.
	 *
	 * @note The current implementation is incomplete.
	 */
	long int indexOf(const T&) const;
};

template <class T>
List<T>::List() :head(nullptr), size(0) {
}

template <class T>
List<T>::List(const List<T> &other) : head(nullptr), size(0) {
	if (!other.empty()) {
		Node<T> *p = other.head;

		Node<T> *q;
		head = q = new Node<T>(p->value);
		p = p->next;

		while (p != nullptr) {
			q->next = new Node<T>(p->value);
			q = q->next;

			p = p->next;
		}

		size = other.size;
	}
}

template <class T>
List<T>::~List() {
	clear();
}

template <class T>
bool List<T>::empty() const {
	return (head == nullptr);
}

template <class T>
List<T>& List<T>::operator=(const List<T> &other) {
	if (this == &other) {
		return *this;
	}

	clear(); 

	if (other.empty()) {
		return *this;
	}

	Node<T> *p = other.head;

	Node<T> *q;
	head = q = new Node<T>(p->value);
	p = p->next;

	while (p != nullptr) {
		q->next = new Node<T>(p->value);
		q = q->next;

		p = p->next;
	}

	size = other.size;
	return *this;
}

template <class T>
uint List<T>::length() const {
	return size;
}

template <class T>
bool List<T>::contains(const T& val) const {
	Node<T> *p;

	p = head;
	while (p != nullptr) {
		if (p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}

template <class T>
void List<T>::clear() {
	Node<T> *p, *q;

	p = head;
	while (p != nullptr){
		q = p->next;
		delete p;
		p = q;
	}

	head = nullptr;
	size = 0;
}

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Node<T> *p;

	p = head;
	aux << "[";
	while (p != nullptr) {
		aux << p->value;
		if (p->next != nullptr) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
const T& List<T>::front() const {
	if (empty()) {
		throw std::out_of_range();
	}

	return head->value;
}

template <class T>
const T& List<T>::last() const {
	Node<T> *p;

	if (empty()) {
		throw std::out_of_range("No Such Element");
	}

	p = head;
	while (p->next != nullptr) {
		p = p->next;
	}
	return p->value;
}

template <class T>
const T& List<T>::get(uint index) const {
	T aux;

	// TO DO
	return aux;
}

template <class T>
void List<T>::push_front(const T& val) {
	Node<T> *q;

	q = new Node<T>(val);
	q->next = head;
	head = q;
	// head = new Node<T>(val, head);
	size++;
}

template <class T>
void List<T>::push_back(const T& val) {
	Node<T> *p, *q;

	if (empty()) {
		push_front(val);
		return;
	}

	p = head;
	while (p->next != nullptr) {
		p = p->next;
	}

	q = new Node<T>(val);
	q->next = p->next;
	p->next = q;
	size++;
}

template <class T>
void List<T>::insert_at(const T& val, uint index) {
	// TO DO
}

template <class T>
void List<T>::pop_front() {
	T val;
	Node<T> *p;

	if (empty()) {
		throw std::out_of_range("No Such Element");
	}

	p = head;
	val = p->value;

	head = p->next;
	p->next = nullptr;
	delete p;

	size--;
}

template <class T>
void List<T>::pop_back() {
	Node<T> *p, *q;
	T val;

	if (empty()) {
		throw std::out_of_range("No Such Element");
	}

	if (size == 1) {
		return pop_front();
	}

	q = nullptr;
	p = head;
	while (p->next != nullptr) {
		q = p;
		p = p->next;
	}

	val = p->value;

	q->next = p->next;
	p->next = nullptr;
	delete p;

	size--;
}

template <class T>
void List<T>::remove_at(uint index) {
	// TO DO
}

template <class T>
long int List<T>::indexOf(const T& val) const {
	// TO DO
	return -1;
}

#endif /* LIST_H */
