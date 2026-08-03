// =================================================================
//
// File: vector.h
// Author: Pedro Perez
// Description: This file contains the implementation of the
//				Vector class
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept> // Para manejar excepciones

typedef unsigned int uint;

/**
 * @brief A custom implementation of a dynamic array (vector).
 * 
 * @tparam T The type of elements stored in the vector.
 */
template <class T>
class Vector {
private:
    uint capacity; /**< The current capacity of the vector. */
    T *data;       /**< Pointer to the dynamically allocated array. */

    /**
     * @brief Helper function to check if memory allocation was successful.
     * 
     * @param ptr Pointer to the allocated memory.
     * @throw std::bad_alloc If the memory allocation failed.
     */
    void checkMemoryAllocation(T *ptr) const {
        if (!ptr) {
            throw std::bad_alloc();
        }
    }

public:
    // Constructors and Destructor
    Vector();
    Vector(uint elements);
    Vector(uint elements, T initialValue);
    Vector(const Vector<T> &source);
    ~Vector();

    // Member functions
    uint size() const;
    uint resize(uint newcapacity);
    std::string toString() const;

    // Operators
    T& operator[](uint index) const;
    Vector<T>& operator=(const Vector<T> &right);
    template <class U>
    friend std::ostream& operator<<(std::ostream &out, const Vector<U> &v);
};

// Constructor: Default
/**
 * @brief Default constructor. Initializes the vector with a capacity of 1.
 */
template <class T>
Vector<T>::Vector() {
    capacity = 1;
    data = new T[capacity];
    checkMemoryAllocation(data);
}

// Constructor: Size only
/**
 * @brief Constructs a vector with the specified number of elements.
 * 
 * @param elements The initial capacity of the vector.
 * @throw std::invalid_argument If `elements` is 0.
 */
template <class T>
Vector<T>::Vector(uint elements) {
    if (elements == 0) {
        throw std::invalid_argument("Vector size cannot be 0.");
    }
    capacity = elements;
    data = new T[capacity];
    checkMemoryAllocation(data);
}

// Constructor: Size and initial value
/**
 * @brief Constructs a vector with the specified number of elements, all initialized to a given value.
 * 
 * @param elements The initial capacity of the vector.
 * @param initialValue The value to initialize all elements with.
 * @throw std::invalid_argument If `elements` is 0.
 */
template <class T>
Vector<T>::Vector(uint elements, T initialValue) {
    if (elements == 0) {
        throw std::invalid_argument("Vector size cannot be 0.");
    }
    capacity = elements;
    data = new T[capacity];
    checkMemoryAllocation(data);
    for (uint i = 0; i < capacity; i++) {
        data[i] = initialValue;
    }
}

// Copy Constructor
/**
 * @brief Copy constructor. Creates a new vector as a copy of another.
 * 
 * @param source The vector to copy.
 */
template <class T>
Vector<T>::Vector(const Vector<T> &source) {
    capacity = source.capacity;
    data = new T[capacity];
    checkMemoryAllocation(data);
    for (uint i = 0; i < capacity; i++) {
        data[i] = source.data[i];
    }
}

// Destructor
/**
 * @brief Destructor. Frees the dynamically allocated memory.
 */
template <class T>
Vector<T>::~Vector() {
    delete[] data;
    data = nullptr; // Avoid dangling pointer
    capacity = 0;
}

// Member Function: size
/**
 * @brief Returns the current size (capacity) of the vector.
 * 
 * @return The size of the vector.
 */
template <class T>
uint Vector<T>::size() const {
    return capacity;
}

// Member Function: resize
/**
 * @brief Resizes the vector to a new capacity.
 * 
 * @param newcapacity The new capacity of the vector.
 * @return The updated capacity of the vector.
 * @throw std::invalid_argument If `newcapacity` is 0.
 */
template <class T>
uint Vector<T>::resize(uint newcapacity) {
    if (newcapacity == 0) {
        throw std::invalid_argument("Vector size cannot be resized to 0.");
    }
    if (capacity == newcapacity) {
        return capacity;
    }

    T *newData = new T[newcapacity];
    checkMemoryAllocation(newData);

    if (newcapacity < capacity) {
        for (uint i = 0; i < newcapacity; i++) {
            newData[i] = data[i];
        }
    } else {
        for (uint i = 0; i < capacity; i++) {
            newData[i] = data[i];
        }
    }

    delete[] data;
    data = newData;
    capacity = newcapacity;

    return capacity;
}

// Operator: []
/**
 * @brief Accesses an element at a given index.
 * 
 * @param index The index of the element to access.
 * @return A reference to the element at the specified index.
 * @throw std::out_of_range If the index is out of bounds.
 */
template <class T>
T& Vector<T>::operator[](uint index) const {
    if (index >= capacity) {
        throw std::out_of_range("Index is out of bounds.");
    }
    return data[index];
}

// Operator: =
/**
 * @brief Assignment operator. Copies the contents of another vector into this one.
 * 
 * @param right The vector to copy.
 * @return A reference to this vector.
 */
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T> &right) {
    if (this != &right) { // Avoid self-assignment
        if (capacity != right.capacity) {
            resize(right.capacity);
        }
        for (uint i = 0; i < right.capacity; i++) {
            data[i] = right.data[i];
        }
    }
    return *this;
}

// Friend Operator: <<
/**
 * @brief Outputs the vector's contents to a stream.
 * 
 * @tparam U The type of elements in the vector.
 * @param out The output stream.
 * @param v The vector to output.
 * @return A reference to the output stream.
 */
template <class U>
std::ostream& operator<<(std::ostream &out, const Vector<U> &v) {
    if (v.capacity == 0) {
        out << "[]";
        return out;
    }

    out << "[" << v.data[0];
    for (uint i = 1; i < v.capacity; i++) {
        out << ", " << v.data[i];
    }
    out << "]";
    return out;
}

#endif /* VECTOR_H */