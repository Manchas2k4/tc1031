#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include "exception.h"

using namespace std;

typedef unsigned int uint;

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
    throw Overflow();
  }

  data[next++] = val;
}

template <class T>
T StackVector<T>::top() const {
  if (empty()) {
    throw NoSuchElement();
  }
  return data[next - 1];
}

template <class T>
void StackVector<T>::pop() {
  if (empty()) {
    throw NoSuchElement();
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

template <class T>
void StackList<T>::push(T val) {
  data.push_front(val);
}

template <class T>
T StackList<T>::top() const {
  if (data.empty()) {
    throw NoSuchElement();
  }
  return data.front();
}

template <class T>
void StackList<T>::pop() {
  if (data.empty()) {
    throw NoSuchElement();
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
