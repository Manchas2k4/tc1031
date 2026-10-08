/**
 * @file queue.h
 * @brief Generic Queue (FIFO) abstract data type with two concrete
 *        implementations: an array-backed circular buffer (QueueVector)
 *        and a linked-list-backed version (QueueList).
 *
 * @author Pedro Perez
 * @copyright 2020 Tecnologico de Monterrey. All Rights Reserved. May be
 *            reproduced for any non-commercial purpose.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>

typedef unsigned int uint;

/**
 * @class Queue
 * @brief Abstract interface (TDA) for a generic FIFO queue of elements
 *        of type @c T.
 *
 * @tparam T Type of the elements stored in the queue.
 *
 * Defines the public contract that any concrete queue implementation
 * (e.g. QueueVector, QueueList) must satisfy. All members are pure
 * virtual, so this class cannot be instantiated directly.
 */
template <class T>
class Queue {
public:
    /**
     * @brief Virtual destructor, ensuring correct cleanup through a
     *        pointer to the base class.
     */
    virtual ~Queue() {}

    /**
     * @brief Inserts a new element at the back of the queue.
     * @param val Value to be inserted.
     * @note Concrete implementations may throw an exception if the
     *       element cannot be inserted (e.g. the queue is full).
     */
    virtual void enqueue(const T&) = 0;

    /**
     * @brief Returns the element currently at the front of the queue
     *        without removing it.
     * @return The front element.
     * @note Concrete implementations are expected to signal an error if
     *       the queue is empty.
     */
    virtual T front() const = 0;

    /**
     * @brief Removes the element at the front of the queue.
     * @note Concrete implementations are expected to signal an error if
     *       the queue is empty.
     */
    virtual void dequeue() = 0;

    /**
     * @brief Indicates whether the queue contains no elements.
     * @return @c true if the queue is empty, @c false otherwise.
     */
    virtual bool empty() const = 0;

    /**
     * @brief Removes all elements from the queue, leaving it empty.
     */
    virtual void clear() = 0;

    /**
     * @brief Builds a textual representation of the queue contents.
     * @return A string with the elements formatted as a bracketed,
     *         comma-separated list, in front-to-back order.
     */
    virtual std::string toString() const = 0;
};

/**
 * @class QueueVector
 * @brief Array-based implementation of Queue, backed by a fixed-capacity
 *        dynamically allocated circular buffer.
 *
 * @tparam T Type of the elements stored in the queue.
 *
 * The capacity of the underlying array is fixed at construction time
 * and does not grow automatically; the @c head and @c tail indices wrap
 * around the array (modulo @c size) to reuse freed slots after
 * dequeuing, and @c counter tracks the current number of elements.
 */
template <class T>
class QueueVector : public Queue<T> {
private:
    T *data;                           ///< Dynamically allocated circular
                                        ///< backing array of capacity
                                        ///< @c size.
    uint size, head, tail, counter;    ///< @c size: total capacity of the
                                        ///< underlying array. @c head:
                                        ///< index of the front element.
                                        ///< @c tail: index where the next
                                        ///< enqueued element will be
                                        ///< written. @c counter: current
                                        ///< number of stored elements.

public:
    /**
     * @brief Constructs an empty queue with a fixed capacity.
     * @param s Capacity of the underlying array (maximum number of
     *          elements the queue can hold).
     * @throws std::invalid_argument If @p s is 0.
     * @post The queue is empty and able to hold up to @p s elements.
     */
    QueueVector(uint);

    /**
     * @brief Copy constructor. Performs a deep copy of @p other,
     *        including its backing array.
     * @param other Queue to copy from.
     * @post This queue has the same capacity, contents and internal
     *       indices as @p other, stored in an independently allocated
     *       array.
     */
    QueueVector(const QueueVector<T>&);

    /**
     * @brief Copy-assignment operator, implemented via the
     *        copy-and-swap idiom.
     * @param other Queue to assign from, taken by value so the caller's
     *              copy (made by QueueVector(const QueueVector<T>&))
     *              can be swapped into @c *this.
     * @return A reference to @c *this.
     * @post This queue's previous contents are released (when @p other
     *       goes out of scope) and replaced with a copy of the
     *       right-hand side's state.
     */
    QueueVector<T>& operator=(QueueVector<T>);

    /**
     * @brief Destroys the queue and releases the underlying array.
     * @post The internal buffer is freed and the queue is left in a
     *       zeroed, unusable state.
     */
    ~QueueVector();

    /**
     * @brief Inserts a new element at the back of the queue.
     * @param val Value to be inserted.
     * @throws std::overflow_error If the queue has already reached its
     *         capacity (i.e. full() is @c true).
     * @post On success, the element count increases by one and @c tail
     *       advances (circularly) by one position.
     */
    void enqueue(const T&) override;

    /**
     * @brief Returns the element at the front of the queue without
     *        removing it.
     * @return The front element.
     * @throws std::underflow_error If the queue is empty.
     */
    T front() const override;

    /**
     * @brief Removes the element at the front of the queue.
     * @throws std::underflow_error If the queue is empty.
     * @post The element count decreases by one and @c head advances
     *       (circularly) by one position.
     */
    void dequeue() override;

    /**
     * @brief Indicates whether the queue contains no elements.
     * @return @c true if no elements are currently stored, @c false
     *         otherwise.
     */
    bool empty() const override;

    /**
     * @brief Resets the queue to the empty state.
     * @post The element count is zero and @c head/@c tail are reset to
     *       the start of the buffer; the underlying array capacity is
     *       unchanged.
     */
    void clear() override;

    /**
     * @brief Builds a textual representation of the queue contents.
     * @return A string of the form "[e0, e1, ..., eN]" listing elements
     *         in front-to-back order, walking the circular buffer
     *         starting at @c head.
     */
    std::string toString() const override;

    /**
     * @brief Indicates whether the queue has reached its capacity.
     * @return @c true if the element count equals the array's capacity,
     *         @c false otherwise.
     */
    bool full() const;
};

template <class T>
QueueVector<T>::QueueVector(uint s)
    : data(nullptr), size(s), head(0), tail(0), counter(0) {
    if (size == 0) {
        throw std::invalid_argument("QueueVector: the size must be greater than 0");
    }

    data = new T[size];
}

template <class T>
QueueVector<T>::QueueVector(const QueueVector<T> &other)
    : data(new T[other.size]), size(other.size), head(other.head),
      tail(other.tail), counter(other.counter) {

    std::copy(other.data, other.data + other.size, data);
}

template <class T>
QueueVector<T>& QueueVector<T>::operator=(QueueVector<T> other) {
    std::swap(data, other.data);
    std::swap(size, other.size);
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(counter, other.counter);
    return *this;
}

template <class T>
QueueVector<T>::~QueueVector() {
    delete [] data;
    data = nullptr;
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
void QueueVector<T>::enqueue(const T &val) {
    if (full()) {
        throw std::overflow_error("QueueVector::enqueue(): the queue is full");
    }

    data[tail] = val;
    tail = (tail + 1) % size;
    counter++;
}

template <class T>
T QueueVector<T>::front() const {
    if (empty()) {
        throw std::underflow_error("QueueVector::front(): the queue is empty");
    }

    return data[head];
}

template <class T>
void QueueVector<T>::dequeue() {
    if (empty()) {
        throw std::underflow_error("QueueVector::dequeue(): the queue is empty");
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
std::string QueueVector<T>::toString() const {
    std::stringstream aux;

    aux << "[";
    for (uint n = 0; n < counter; n++) {
        if (n > 0) {
            aux << ", ";
        }
        aux << data[(head + n) % size];
    }
    aux << "]";
    return aux.str();
}

/**
 * @class QueueList
 * @brief Linked-list-based implementation of Queue, backed by
 *        @c std::list.
 *
 * @tparam T Type of the elements stored in the queue.
 *
 * FIFO order is achieved by always inserting at the back and removing
 * from the front of the underlying list. Unlike QueueVector, capacity
 * is not fixed and grows dynamically with the number of elements.
 */
template <class T>
class QueueList : public Queue<T> {
private:
    std::list<T> data; ///< Underlying container holding the queue
                        ///< elements, with the front of the queue at the
                        ///< front of the list.

public:
    /**
     * @brief Inserts a new element at the back of the queue.
     * @param val Value to be inserted.
     * @post The element becomes the new back of the underlying list.
     */
    void enqueue(const T&) override;

    /**
     * @brief Removes the element at the front of the queue.
     * @throws std::underflow_error If the queue is empty.
     */
    void dequeue() override;

    /**
     * @brief Returns the element at the front of the queue without
     *        removing it.
     * @return The front element.
     * @throws std::underflow_error If the queue is empty.
     */
    T front() const override;

    /**
     * @brief Indicates whether the queue contains no elements.
     * @return @c true if the underlying list is empty, @c false
     *         otherwise.
     */
    bool empty() const override;

    /**
     * @brief Removes all elements from the queue.
     * @post The underlying list is empty.
     */
    void clear() override;

    /**
     * @brief Builds a textual representation of the queue contents.
     * @return A string of the form "[e0, e1, ..., eN]" listing elements
     *         in front-to-back order of the underlying list.
     */
    std::string toString() const override;
};

template <class T>
bool QueueList<T>::empty() const {
    return (data.empty());
}

template <class T>
void QueueList<T>::enqueue(const T &val) {
    data.push_back(val);
}

template <class T>
T QueueList<T>::front() const {
    if (empty()) {
        throw std::underflow_error("QueueList::front(): the queue is empty");
    }
    return data.front();
}

template <class T>
void QueueList<T>::dequeue() {
    if (empty()) {
        throw std::underflow_error("QueueList::dequeue(): the queue is empty");
    }
    data.pop_front();
}

template <class T>
void QueueList<T>::clear() {
    data.clear();
}

template <class T>
std::string QueueList<T>::toString() const {
    std::stringstream aux;
    typename std::list<T>::const_iterator itr = data.begin();

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