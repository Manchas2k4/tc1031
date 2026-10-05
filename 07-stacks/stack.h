// =================================================================
//
// File: stack.h
// Author: Pedro Pérez
// Description: This file contains the implementation of a TDA Stack
// implementation, using both arrays (StackVector) and lists
// (StackList).
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

/**
 * @file stack.h
 * @brief Generic Stack (LIFO) abstract data type with two concrete
 *        implementations: an array-backed version (StackVector) and a
 *        linked-list-backed version (StackList).
 *
 * @author Pedro Pérez
 * @copyright 2026 Tecnologico de Monterrey. All Rights Reserved. May be
 *            reproduced for any non-commercial purpose.
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <stdexcept>
#include <utility>

typedef unsigned int uint;

/**
 * @class Stack
 * @brief Abstract interface (TDA) for a generic LIFO stack of elements of
 *        type @c T.
 *
 * @tparam T Type of the elements stored in the stack.
 *
 * Defines the public contract that any concrete stack implementation
 * (e.g. StackVector, StackList) must satisfy. All members are pure
 * virtual, so this class cannot be instantiated directly.
 */
template <class T>
class Stack {
public:
  /**
   * @brief Pushes a new element onto the top of the stack.
   * @param val Value to be inserted.
   * @note Concrete implementations may throw an exception if the
   *       element cannot be inserted (e.g. the stack is full).
   */
  virtual void push(T) = 0;

  /**
   * @brief Returns the element currently at the top of the stack without
   *        removing it.
   * @return The top element.
   * @note Concrete implementations are expected to signal an error if the
   *       stack is empty.
   */
  virtual T top() const = 0;

  /**
   * @brief Removes the element at the top of the stack.
   * @note Concrete implementations are expected to signal an error if the
   *       stack is empty.
   */
  virtual void pop() = 0;

  /**
   * @brief Indicates whether the stack contains no elements.
   * @return @c true if the stack is empty, @c false otherwise.
   */
  virtual bool empty() const = 0;

  /**
   * @brief Removes all elements from the stack, leaving it empty.
   */
  virtual void clear() = 0;

  /**
   * @brief Builds a textual representation of the stack contents.
   * @return A string with the elements formatted as a bracketed,
   *         comma-separated list.
   */
  virtual std::string toString() const = 0;
};

/**
 * @class StackVector
 * @brief Array-based implementation of Stack, backed by a fixed-capacity
 *        dynamically allocated array.
 *
 * @tparam T Type of the elements stored in the stack.
 *
 * The capacity of the underlying array is fixed at construction time and
 * does not grow automatically; pushing beyond that capacity raises an
 * overflow condition.
 */
template <class T>
class StackVector : public Stack<T> {
private:
  uint next, size; ///< @c next: index of the first free slot (also the
                    ///< current element count). @c size: total capacity
                    ///< of the underlying array.
  T *data;          ///< Dynamically allocated backing array of capacity
                    ///< @c size.

public:
  /**
   * @brief Constructs an empty stack with a fixed capacity.
   * @param s Capacity of the underlying array (maximum number of
   *          elements the stack can hold).
   * @post The stack is empty and able to hold up to @p s elements.
   */
  StackVector(uint);

  /**
   * @brief Destroys the stack and releases the underlying array.
   * @post The internal buffer is freed and the stack is left in a
   *       zeroed, unusable state.
   */
  ~StackVector();

  /**
   * @brief Pushes a new element onto the top of the stack.
   * @param val Value to be inserted.
   * @throws std::overflow_error If the stack has already reached its
   *         capacity (@c next @c >= @c size).
   * @post On success, the element count increases by one.
   */
  void push(T);

  /**
   * @brief Returns the element at the top of the stack without removing
   *        it.
   * @return The top element.
   * @throws std::out_of_range If the stack is empty.
   */
  T top() const;

  /**
   * @brief Removes the element at the top of the stack.
   * @throws std::out_of_range If the stack is empty.
   * @post The element count decreases by one.
   */
  void pop();

  /**
   * @brief Indicates whether the stack contains no elements.
   * @return @c true if no elements have been pushed (or all have been
   *         popped), @c false otherwise.
   */
  bool empty() const;

  /**
   * @brief Resets the stack to the empty state.
   * @post The element count is zero; the underlying array capacity is
   *       unchanged.
   * @note The existing elements are not individually destroyed beyond
   *       being logically discarded (the slot index is simply reset).
   */
  void clear();

  /**
   * @brief Builds a textual representation of the stack contents.
   * @return A string of the form "[e0, e1, ..., eN]" listing elements in
   *         the order they are stored internally (bottom to top).
   */
  std::string toString() const;
};

template <class T>
StackVector<T>::StackVector(uint s) {
  size = s;
  data = new T[size];
  next = 0;
}

template <class T>
StackVector<T>::~StackVector() {
  delete [] data;
  data = NULL;
  size = 0;
  next = 0;
}

template <class T>
void StackVector<T>::push(T val) {
  if (next >= size) {
    throw std::overflow_error("StackVector::push: stack is full");
  }

  data[next++] = val;
}

template <class T>
T StackVector<T>::top() const {
  if (empty()) {
    throw std::out_of_range("StackVector::top: stack is empty");
  }
  return data[next - 1];
}

template <class T>
void StackVector<T>::pop() {
  if (empty()) {
    throw std::out_of_range("StackVector::pop: stack is empty");
  }
  next--;
}

template <class T>
bool StackVector<T>::empty() const {
  return (next == 0);
}

template <class T>
void StackVector<T>::clear() {
  next = 0;
}

template <class T>
std::string StackVector<T>::toString() const {
  std::stringstream aux;

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

/**
 * @class StackList
 * @brief Linked-list-based implementation of Stack, backed by
 *        @c std::list.
 *
 * @tparam T Type of the elements stored in the stack.
 *
 * LIFO order is achieved by always inserting and removing at the front
 * of the underlying list. Unlike StackVector, capacity is not fixed and
 * grows dynamically with the number of elements.
 *
 * @note As given, this class declaration does not carry its own
 *       `template <class T>` header before `class StackList`, so `T` is
 *       not a declared template parameter of the class itself; see
 *       "Sugerencias de mejora" for details. Documentation below assumes
 *       the intended generic-class contract.
 */
template <class T>
 class StackList : public Stack<T> {
private:
  std::list<T> data; ///< Underlying container holding the stack
                      ///< elements, with the top of the stack at the
                      ///< front of the list.

public:
  /**
   * @brief Pushes a new element onto the top of the stack.
   * @param val Value to be inserted.
   * @post The element becomes the new front of the underlying list.
   */
  void push(T);

  /**
   * @brief Returns the element at the top of the stack without removing
   *        it.
   * @return The top element.
   * @throws std::out_of_range If the stack is empty.
   */
  T top() const;

  /**
   * @brief Removes the element at the top of the stack.
   * @throws std::out_of_range If the stack is empty.
   */
  void pop();

  /**
   * @brief Indicates whether the stack contains no elements.
   * @return @c true if the underlying list is empty, @c false otherwise.
   */
  bool empty() const;

  /**
   * @brief Removes all elements from the stack.
   * @post The underlying list is empty.
   */
  void clear();

  /**
   * @brief Builds a textual representation of the stack contents.
   * @return A string of the form "[e0, e1, ..., eN]" listing elements in
   *         front-to-back order of the underlying list (i.e. top of the
   *         stack first).
   */
  std::string toString() const;
};

template <class T>
void StackList<T>::push(T val) {
  data.push_front(val);
}

template <class T>
T StackList<T>::top() const {
  if (data.empty()) {
    throw std::out_of_range("StackList::top: stack is empty");
  }
  return data.front();
}

template <class T>
void StackList<T>::pop() {
  if (data.empty()) {
    throw std::out_of_range("StackList::pop: stack is empty");
  }
  data.pop_front();
}

template <class T>
bool StackList<T>::empty() const {
  return (data.empty());
}

template <class T>
void StackList<T>::clear() {
  data.clear();
}

template <class T>
std::string StackList<T>::toString() const {
  std::stringstream aux;
  typename std::list<T>::const_iterator itr = data.begin();

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