// =================================================================
//
// File: DoubleLinkedList.h
// Author: Pedro Perez
// Description: This file contains the implementation of a TDA
// DoubleLinkedList
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================


/**
 * @brief Implements a generic doubly linked list.
 *
 * This file defines the Node and DoubleLinkedList classes used to
 * represent and manipulate a doubly linked list of elements of type T.
 *
 * Each node maintains references to both its previous and next nodes.
 * The list stores a reference to its first node and the number of
 * elements currently contained in the list.
 */

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <string>
#include <sstream>
#include <stdexcept>
#include <utility>

typedef unsigned int uint;

/**
 * @brief Forward declaration of the DoubleLinkedList class template.
 *
 * @tparam T Type of elements stored in the list.
 */
template <class T> class DoubleLinkedList;

/**
 * @brief Represents a node in a doubly linked list.
 *
 * Each node stores a value and references to the previous and next
 * nodes in the list. The node constructors and data members are private
 * and are accessible to DoubleLinkedList through friendship.
 *
 * @tparam T Type of value stored in the node.
 */
template <class T>
class Node {
private:
	/**
	 * @brief Constructs a node containing a value with null links.
	 *
	 * @param val Value stored in the node.
	 */
	Node(T);

	/**
	 * @brief Constructs a node with a value and specified links.
	 *
	 * @param val Value stored in the node.
	 * @param prev Pointer to the previous node.
	 * @param nxt Pointer to the next node.
	 */
	Node(T, Node<T>*, Node<T>*);

	T	    value;
	Node<T> *previous, *next;

	friend class DoubleLinkedList<T>;
};

/**
 * @brief Constructs a node containing a value.
 *
 * Both neighboring-node pointers are initialized to nullptr.
 *
 * @tparam T Type of value stored in the node.
 * @param val Value stored in the node.
 */
template <class T>
Node<T>::Node(T val) : value(val), previous(nullptr), next(nullptr) {
}

/**
 * @brief Constructs a node with a value and neighboring nodes.
 *
 * @tparam T Type of value stored in the node.
 * @param val Value stored in the node.
 * @param prev Pointer to the previous node.
 * @param nxt Pointer to the next node.
 */
template <class T>
Node<T>::Node(T val, Node<T> *prev, Node<T> *nxt)
	: value(val), previous(prev), next(nxt) {
}

/**
 * @brief Implements a generic doubly linked list.
 *
 * The list stores elements of type T in dynamically allocated nodes.
 * Each node maintains links to both its previous and next nodes.
 *
 * The list provides operations for accessing, searching, inserting,
 * removing, and clearing elements.
 *
 * @tparam T Type of elements stored in the list.
 */
template <class T>
class DoubleLinkedList {
private:
	Node<T> *head;
	uint 	size;

public:
	/**
	 * @brief Constructs an empty doubly linked list.
	 *
	 * The list is initialized with no nodes and a length of zero.
	 */
	DoubleLinkedList();

	/**
	 * @brief Constructs a copy of another doubly linked list.
	 *
	 * @param other List to be copied.
	 */
	DoubleLinkedList(const DoubleLinkedList<T> &);

	/**
	 * @brief Destroys the list and releases its dynamically allocated nodes.
	 */
	~DoubleLinkedList();

	/**
	 * @brief Assigns another list to the current list.
	 *
	 * @param other List to copy.
	 *
	 * @return Reference to the current list.
	 */
	DoubleLinkedList<T>& operator=(const DoubleLinkedList<T>&);

	/**
	 * @brief Returns the number of elements in the list.
	 *
	 * @return Number of elements currently stored in the list.
	 *
	 * @complexity O(1)
	 */
	uint  length() const;

	/**
	 * @brief Determines whether the list is empty.
	 *
	 * @return true if the list contains no elements; false otherwise.
	 *
	 * @complexity O(1)
	 */
	bool empty() const;

	/**
	 * @brief Determines whether a value is contained in the list.
	 *
	 * The search is performed from the first node toward the last node.
	 *
	 * @param val Value to search for.
	 * @return true if the value is found; false otherwise.
	 *
	 * @complexity O(n)
	 */
	bool contains(const T&) const;

	/**
	 * @brief Removes all elements from the list.
	 *
	 * All dynamically allocated nodes are deleted. After this operation,
	 * the list is empty and its length is zero.
	 *
	 * @complexity O(n)
	 */
	void clear();

	/**
	 * @brief Returns a string representation of the list.
	 *
	 * Elements are represented between square brackets and separated
	 * by commas.
	 *
	 * @return String representation of the list.
	 *
	 * @complexity O(n)
	 */
	std::string toString() const;

	/**
	 * @brief Returns the first element in the list.
	 *
	 * @return Constant reference to the first element.
	 *
	 * @throws std::out_of_range if the list is empty.
	 *
	 * @complexity O(1)
	 */
	const T& front() const;

	/**
	 * @brief Returns the last element in the list.
	 *
	 * @return Constant reference to the last element.
	 *
	 * @throws std::out_of_range if the list is empty.
	 *
	 * @complexity O(n)
	 */
	const T& last() const;

	/**
	 * @brief Returns the element immediately before a specified value.
	 *
	 * The first occurrence of the specified value is considered.
	 *
	 * @param val Value whose preceding element is requested.
	 * @return Constant reference to the element immediately preceding val.
	 *
	 * @throws std::out_of_range if the list is empty, if val is not found,
	 * or if val is the first element in the list.
	 *
	 * @complexity O(n)
	 */
	const T& before(const T&) const;

	/**
	 * @brief Returns the element immediately after a specified value.
	 *
	 * The first occurrence of the specified value is considered.
	 *
	 * @param val Value whose following element is requested.
	 * @return Constant reference to the element immediately following val.
	 *
	 * @throws std::out_of_range if the list is empty, if val is not found,
	 * or if val is the last element in the list.
	 *
	 * @complexity O(n)
	 */
	const T& after(const T&) const;

	/**
	 * @brief Inserts an element at the beginning of the list.
	 *
	 * @param val Value to insert.
	 *
	 * @complexity O(1)
	 */
	void push_front(const T&);

	/**
	 * @brief Inserts an element at the end of the list.
	 *
	 * @param val Value to insert.
	 *
	 * @complexity O(n)
	 */
	void push_back(const T&);

	/**
	 * @brief Inserts a new element immediately before a specified value.
	 *
	 * The first occurrence of the specified value is considered.
	 *
	 * @param lookingFor Value before which the new element is inserted.
	 * @param newVal Value to insert.
	 *
	 * @throws std::out_of_range if lookingFor is not found.
	 *
	 * @complexity O(n)
	 */
	void insert_before(const T&, const T&);

	/**
	 * @brief Inserts a new element immediately after a specified value.
	 *
	 * The first occurrence of the specified value is considered.
	 *
	 * @param lookingFor Value after which the new element is inserted.
	 * @param newVal Value to insert.
	 *
	 * @throws std::out_of_range if lookingFor is not found.
	 *
	 * @complexity O(n)
	 */
	void insert_after(const T&, const T&);

	/**
	 * @brief Removes the first element from the list.
	 *
	 * @throws std::out_of_range if the list is empty.
	 *
	 * @complexity O(1)
	 */
	void pop_front();

	/**
	 * @brief Removes the last element from the list.
	 *
	 * @throws std::out_of_range if the list is empty.
	 *
	 * @complexity O(n)
	 */
	void pop_back();
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList() :head(nullptr), size(0) {
}

/**
 * @brief Constructs a copy of another list.
 *
 * @param other List to be copied.
 *
 * @note This operation is pending implementation.
 */
template <class T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T> &other) 
	: head(nullptr), size(0) {
	if (other.head == nullptr) {
        return;
    }

    Node<T> *p = other.head;
    head = new Node<T>(p->value);
    Node<T> *current = head;
    p = p->next;

    while (p != nullptr) {
        Node<T> *newNode = new Node<T>(p->value, current, nullptr);
        current->next = newNode;
        current = newNode;
        p = p->next;
    }

    size = other.size;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
	clear();
}

template <class T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<T> &other) {
	if (this != &other) {
        DoubleLinkedList<T> temp(other);

        std::swap(this->head, temp.head);
        std::swap(this->size, temp.size);
    }
    
	return *this;
}

template <class T>
bool DoubleLinkedList<T>::empty() const {
	return (head == nullptr);
}

template <class T>
uint DoubleLinkedList<T>::length() const {
	return size;
}

template <class T>
bool DoubleLinkedList<T>::contains(const T& val) const {
	Node<T> *p;

	p = head;
	while (p != nullptr) {
		if(p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}

template <class T>
void DoubleLinkedList<T>::clear() {
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
std::string DoubleLinkedList<T>::toString() const {
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
const T& DoubleLinkedList<T>::front() const {
	if (empty()) {
		throw std::out_of_range("No Such Element");
	}

	return head->value;
}

template <class T>
const T& DoubleLinkedList<T>::last() const {
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
const T& DoubleLinkedList<T>::before(const T& val) const {
	// TO DO
	throw std::logic_error("Not implemented");
}

template <class T>
const T& DoubleLinkedList<T>::after(const T& val) const {
	// TO DO
	throw std::logic_error("Not implemented");
}

template <class T>
void DoubleLinkedList<T>::push_front(const T& val) {
	Node<T> *q, *p;

	q = new Node<T>(val);
	if (empty()) {
		q->next = nullptr;
		q->previous = nullptr;
	} else {
		p = head;

		q->next = p; // q->next = head;
		q->previous = nullptr;

		p->previous = q; //head->previous = q;
	}
	head = q;
	size++;
}

template <class T>
void DoubleLinkedList<T>::push_back(const T& val) {
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
	q->previous = p;

	p->next = q;
	size++;
}

template <class T>
void DoubleLinkedList<T>::insert_before(const T& lookingFor, const T& newVal) {
	// TO DO
}

template <class T>
void DoubleLinkedList<T>::insert_after(const T& lookingFor, const T& newVal) {
	// TO DO
}

template <class T>
void DoubleLinkedList<T>::pop_front() {
	Node<T> *p, *q;

	if (empty()) {
		throw std::out_of_range("No Such Element");
	}

	p = head;

	if (size == 1) {
		head = p->next;
	} else {
		q = p->next;

		q->previous = nullptr;
		head = q;
	}

	delete p;
	size--;
}

template <class T>
void DoubleLinkedList<T>::pop_back() {
	Node<T> *p, *q;
	
	if (empty()) {
		throw std::out_of_range("No Such Element");
	}

	if (size == 1) {
		return pop_front();
	}

	p = head;
	while (p->next != nullptr) {
		p = p->next;
	}
	q = p->previous;

	q->next = p->next;

	delete p;
	size--;
}

#endif /* DoubleLinkedList_H */
