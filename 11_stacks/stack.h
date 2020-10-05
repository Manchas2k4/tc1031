// =================================================================
//
// File: stack.h
// Author:
// Description: This file contains the implementation of a TDA Stack
// implementation, using both arrays (StackVector) and lists
// (StackList).
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include "exception.h"

using namespace std;

typedef unsigned int uint;

// =================================================================
// Definition of the Stack interface.
// =================================================================
template <class T>
class Stack {
public:
    virtual void push(T) = 0;
    virtual T top() const = 0;
    virtual void pop() = 0;
    virtual bool empty() const = 0;
    virtual void clear() = 0;
    virtual string toString() const = 0;
};

// =================================================================
// Definition of the StackVector class
// =================================================================
template <class T>
class StackVector : public Stack<T> {
private:
  uint next, size;
  T *data;

public:
  StackVector(uint);
  ~StackVector();
  void push(T);
  T top() const;
  void pop();
  bool empty() const;
  void clear();
  string toString() const;
};

// =================================================================
// Constructor. Initializes the instance variables and creates the
// dynamic array.
//
// @param s, stack size
// =================================================================
template <class T>
StackVector<T>::StackVector(uint s) {
  size = s;
  data = new T[size];
  next = 0;
}


// =================================================================
// Destructor.
// =================================================================
template <class T>
StackVector<T>::~StackVector() {
  delete [] data;
  data = NULL;
  size = 0;
  next = 0;
}


// =================================================================
// Add an item to the stack.
//
// @param val, the value to be put in the position indicated by next
// =================================================================
template <class T>
void StackVector<T>::push(T val) {
  if (next >= size) {
    throw Overflow();
  }

  data[next++] = val;
}

// =================================================================
// Returns the item at the top of the stack.
//
// @return the item at the position indicated by next
// @throw NoSuchElement, when the stack is empty
// =================================================================
template <class T>
T StackVector<T>::top() const {
  if (empty()) {
    throw NoSuchElement();
  }
  return data[next - 1];
}

// =================================================================
// Removes the item at the top of the stack.
//
// @throw NoSuchElement, when the stack is empty
// =================================================================
template <class T>
void StackVector<T>::pop() {
  if (empty()) {
    throw NoSuchElement();
  }
  next--;
}

// =================================================================
// Returns whether the stack is empty or not.
//
// @return true if next is equal to zero, false otherwise.
// =================================================================
template <class T>
bool StackVector<T>::empty() const {
  return (next == 0);
}

// =================================================================
// Removes all items from the stack.
// =================================================================
template <class T>
void StackVector<T>::clear() {
  next = 0;
}

// =================================================================
// Returns the string representation of the elements on the stack.
//
// @return an string with the representation of the stack.
// =================================================================
template <class T>
string StackVector<T>::toString() const {
  stringstream aux;

  aux << "[";
  if (next > 0) {
    aux << data[0];
    for (int i = 1; i < next; i++) {
      aux << ", " << data[i];
    }
  }
  aux << "]";
  return aux.str();
}

// =================================================================
// Definition of the StackList class
// =================================================================
template <class T>
class StackList : public Stack<T> {
private:
  list<T> data;

public:
  void push(T);
  T top() const;
  void pop();
  bool empty() const;
  void clear();
  string toString() const;
};

// =================================================================
// Add an item to the stack.
//
// @param val, the value to be put on the stack
// =================================================================
template <class T>
void StackList<T>::push(T val) {
  data.push_front(val);
}

// =================================================================
// Returns the item at the top of the stack.
//
// @return the item at the front of the list.
// @throw NoSuchElement, when the stack is empty
// =================================================================
template <class T>
T StackList<T>::top() const {
  if (data.empty()) {
    throw NoSuchElement();
  }
  return data.front();
}

// =================================================================
// Removes the item at the top of the stack.
//
// @throw NoSuchElement, when the stack is empty
// =================================================================
template <class T>
void StackList<T>::pop() {
  if (data.empty()) {
    throw NoSuchElement();
  }
  data.pop_front();
}

// =================================================================
// Returns whether the stack is empty or not.
//
// @return true if the list is empty
// =================================================================
template <class T>
bool StackList<T>::empty() const {
  return (data.empty());
}

// =================================================================
// Removes all items from the stack.
// =================================================================
template <class T>
void StackList<T>::clear() {
  data.clear();
}

// =================================================================
// Returns the string representation of the elements on the stack.
//
// @return an string with the representation of the stack.
// =================================================================
template <class T>
string StackList<T>::toString() const {
  stringstream aux;
  typename list<T>::const_iterator itr = data.begin();

  aux << "[";
  if (!data.empty()) {
    aux << (*itr);
    itr++;
    while(itr != data.end()) {
      aux << ", " << (*itr);
      itr++;
    }
  }
  aux << "]";
  return aux.str();
}
#endif /* STACK_H */
