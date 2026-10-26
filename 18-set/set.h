#ifndef SET_H
#define SET_H

#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include "exception.h"

template <class T>
class Set {
private:
    std::list<T> data;

public:
    Set();
    Set(const Set<T>&);
    void add(T);
    void remove(T);
    bool contains(T) const;
    void clear();
    std::string toString() const;
    Set<T> join(const Set<T>&) const;
    Set<T> intersection(const Set<T>&) const;
    Set<T> difference(const  Set<T>&) const;
};

template <class T>
Set<T>::Set() {}

template <class T>
Set<T>::Set(const Set<T> &B)
  : data(B.data) {}

template <class T>
void Set<T>::add(T val) {
  typename std::list<T>::const_iterator itr;

  itr = std::find(data.begin(), data.end(), val);
  if (itr == data.end()) {
    data.push_back(val);
    data.sort();
  }
}

template <class T>
void Set<T>::remove(T val) {
  typename std::list<T>::iterator itr;

  itr = std::find(data.begin(), data.end(), val);
  if (itr == data.end()) {
    throw NoSuchElement();
  }

  data.erase(itr);
}

template <class T>
bool Set<T>::contains(T val) const {
  typename std::list<T>::const_iterator itr;

  itr = std::find(data.begin(), data.end(), val);
  return(itr != data.end());
}

template <class T>
void Set<T>::clear() {
  data.clear();
}

template <class T>
std::string Set<T>::toString() const {
  typename std::list<T>::const_iterator itr;
  std::stringstream aux;

  aux << "[";
  if (!data.empty()) {
    itr = data.begin();
    aux << (*itr);
    itr++;
    while (itr != data.end()) {
      aux << " " << (*itr);
      itr++;
    }
  }
  aux << "]";
  return aux.str();
}

template <class T>
Set<T> Set<T>::join(const Set<T> &B) const {
  typename std::list<T>::const_iterator itr;
  Set<T> result(B);

  for(itr = data.begin(); itr != data.end(); itr++) {
    if (!result.contains((*itr))) {
      result.data.push_back((*itr));
    }
  }
  result.data.sort();
  return result;
}

template <class T>
Set<T> Set<T>::intersection(const Set<T> &B) const {
  typename std::list<T>::const_iterator itr;
  Set<T> result;

  for(itr = data.begin(); itr != data.end(); itr++) {
    if (B.contains((*itr))) {
      result.data.push_back((*itr));
    }
  }
  result.data.sort();
  return result;
}

template <class T>
Set<T> Set<T>::difference(const Set<T> &B) const {
  typename std::list<T>::const_iterator itr;
  Set<T> result;

  for(itr = data.begin(); itr != data.end(); itr++) {
    if (!B.contains((*itr))) {
      result.data.push_back((*itr));
    }
  }
  result.data.sort();
  return result;
}

#endif /* SET_H */
