#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include "exception.h"

using namespace std;

typedef unsigned int uint;

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

template <class T>
QueueVector<T>::QueueVector(uint s) {
  size = s;
  data = new T[size];
  head = 0;
  tail = 0;
  counter = 0;
}

template <class T>
QueueVector<T>::~QueueVector() {
  delete [] data;
  data = NULL;
  head = 0;
  tail = 0;
  size = 0;
  counter = 0;
}

template <class T>
bool QueueVector<T>::empty() const {
  return (counter == 0);
}

template <class T>
bool QueueVector<T>::full() const {
  return (counter == size);
}

template <class T>
void QueueVector<T>::enqueue(T val) {
  if (full()) {
    throw Overflow();
  }
  data[tail] = val;
  tail = (tail + 1) % size;
  counter++;
}

template <class T>
T QueueVector<T>::front() const {
  if (empty()) {
    throw NoSuchElement();
  }
  return data[head];
}

template <class T>
void QueueVector<T>::dequeue() {
  if (empty()) {
    throw NoSuchElement();
  }
  head = (head + 1) % size;
  counter--;
}

template <class T>
void QueueVector<T>::clear() {
  head = 0;
  tail = 0;
  counter = 0;
}

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

template <class T>
bool QueueList<T>::empty() const {
  return (data.empty());
}

template <class T>
void QueueList<T>::enqueue(T val) {
  data.push_back(val);
}

template <class T>
T QueueList<T>::front() const {
  if (empty()) {
    throw NoSuchElement();
  }
  return data.front();
}

template <class T>
void QueueList<T>::dequeue() {
  if (empty()) {
    throw NoSuchElement();
  }
  data.pop_front();
}

template <class T>
void QueueList<T>::clear() {
  data.clear();
}

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
