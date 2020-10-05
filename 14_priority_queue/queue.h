// =================================================================
//
// File: queue.h
// Author:
// Description: This file contains the implementation of a TDA Queue
// implementation, using both arrays (QueueVector) and lists
// (QueueList).
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include "exception.h"

using namespace std;

typedef unsigned int uint;

// =================================================================
// Definition of the Queue interface.
// =================================================================
template <class T>
class Queue {
public:
    virtual void enqueue(T) = 0;
    virtual T front() const = 0;
    virtual void dequeue() = 0;
    virtual bool empty() const = 0;
    virtual void clear() = 0;
    virtual string toString() const = 0;
};

// =================================================================
// Definition of the QueueVector class
// =================================================================
template <class T>
class QueueVector : public Queue<T> {
private:
    uint head, tail, size, counter;
    T *data;

public:
  QueueVector(uint);
  ~QueueVector();
  void enqueue(T);
  T front() const;
  void dequeue();
  bool empty() const;
  void clear();
  bool full() const;
  string toString() const;
};

// =================================================================
// Constructor. Initializes the instance variables and creates the
// dynamic array.
//
// @param s, queue size
// =================================================================
template <class T>
QueueVector<T>::QueueVector(uint s) {
  size = s;
  data = new T[size];
  head = 0;
  tail = 0;
  counter = 0;
}

// =================================================================
// Destructor.
// =================================================================
template <class T>
QueueVector<T>::~QueueVector() {
  delete [] data;
  data = NULL;
  head = 0;
  tail = 0;
  size = 0;
  counter = 0;
}

// =================================================================
// Returns whether the queue is empty or not.
//
// @return true if next is equal to zero, false otherwise.
// =================================================================
template <class T>
bool QueueVector<T>::empty() const {
  return (counter == 0);
}

// =================================================================
// Returns whether the queue is empty or not.
//
// @return true if counter is equal to size, false otherwise.
// =================================================================
template <class T>
bool QueueVector<T>::full() const {
  return (counter == size);
}

// =================================================================
// Add an item at the end to the queue.
//
// @param val, the value to put in the position indicated by tail.
// =================================================================
template <class T>
void QueueVector<T>::enqueue(T val) {
  if (full()) {
    throw Overflow();
  }
  data[tail] = val;
  tail = (tail + 1) % size;
  counter++;
}

// =================================================================
// Returns the item at the front of the queue.
//
// @return the item at the position indicated by head.
// @throw NoSuchElement, when the queue is empty
// =================================================================
template <class T>
T QueueVector<T>::front() const {
  if (empty()) {
    throw NoSuchElement();
  }
  return data[head];
}


// =================================================================
// Removes the item at the front of the queue.
//
// @throw NoSuchElement, when the queue is empty
// =================================================================
template <class T>
void QueueVector<T>::dequeue() {
  if (empty()) {
    throw NoSuchElement();
  }
  head = (head + 1) % size;
  counter--;
}

// =================================================================
// Removes all items from the queue.
// =================================================================
template <class T>
void QueueVector<T>::clear() {
  head = 0;
  tail = 0;
  counter = 0;
}

// =================================================================
// Returns the string representation of the elements on the queue.
//
// @return an string with the representation of the queue.
// =================================================================
template <class T>
string QueueVector<T>::toString() const {
  stringstream aux;
  int i;

  aux << "[";
  if (!empty()) {
    i = head;
    aux << data[i];
    i = (i + 1) % size;
    while(i != tail) {
      aux << ", " << data[i];
      i = (i + 1) % size;
    }
  }
  aux << "]";
  return aux.str();
}

// =================================================================
// Definition of the QueueList class
// =================================================================
template <class T>
class QueueList : public Queue<T> {
private:
	list<T> data;

public:
	void enqueue(T);
	void dequeue();
	T front() const;
	bool empty() const;
	void clear();
	string toString() const;
};


// =================================================================
// Returns whether the queue is empty or not.
//
// @return true if list is empty, false otherwise.
// =================================================================
template <class T>
bool QueueList<T>::empty() const {
  return (data.empty());
}

// =================================================================
// Add an item at the end to the queue.
//
// @param val, the value to be put on at the end od the list.
// =================================================================
template <class T>
void QueueList<T>::enqueue(T val) {
  data.push_back(val);
}

// =================================================================
// Returns the item at the front of the queue.
//
// @return the item at the front of the list.
// @throw NoSuchElement, when the queue is empty
// =================================================================
template <class T>
T QueueList<T>::front() const {
  if (empty()) {
    throw NoSuchElement();
  }
  return data.front();
}

// =================================================================
// Removes the item at the front of the queue.
//
// @throw NoSuchElement, when the queue is empty
// =================================================================
template <class T>
void QueueList<T>::dequeue() {
  if (empty()) {
    throw NoSuchElement();
  }
  data.pop_front();
}

// =================================================================
// Removes all items from the queue.
// =================================================================
template <class T>
void QueueList<T>::clear() {
  data.clear();
}

// =================================================================
// Returns the string representation of the elements on the queue.
//
// @return an string with the representation of the queue.
// =================================================================
template <class T>
string QueueList<T>::toString() const {
	stringstream aux;
	typename list<T>::const_iterator itr = data.begin();

	aux << "[";
	if (!data.empty()) {
		aux << (*itr);
		itr++;
		while (itr != data.end()) {
			aux << ", " << (*itr);
			itr++;
		}
	}
	aux << "]";
	return aux.str();
}

#endif /* QUEUE_H */
