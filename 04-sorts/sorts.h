// =================================================================
//
// File: sorts.h
// Author: Pedro Perez
// Description: This file implements various sorting algorithms: 
//              bubble, selection, insertion, shell, merge, and 
//              quicksort.
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <stdexcept> // For exception handling
#include <algorithm> // For std::copy
#include <utility>

/**
 * @brief Sorts a vector using the bubble sort algorithm.
 * 
 * @tparam T The type of elements in the vector.
 * @param v The vector to be sorted.
 */
template <class T>
void bubbleSort(std::vector<T> &v) {
    if (v.empty()) return;

    for (int i = v.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

/**
 * @brief Sorts a vector using the selection sort algorithm.
 * 
 * @tparam T The type of elements in the vector.
 * @param v The vector to be sorted.
 */
template <class T>
void selectionSort(std::vector<T> &v) {
    if (v.empty()) return;

    int pos;
    for (int i = v.size() - 1; i > 0; i--) {
        pos = 0;
        for (int j = 1; j <= i; j++) {
            if (v[j] > v[pos]) {
                pos = j;
            }
        }
        if (pos != i) {
            std::swap(v[i], v[pos]);
        }
    }
}

/**
 * @brief Sorts a vector using the insertion sort algorithm.
 * 
 * @tparam T The type of elements in the vector.
 * @param v The vector to be sorted.
 */
template <class T>
void insertionSort(std::vector<T> &v) {
    if (v.empty()) return;

    for (int i = 1; i < v.size(); i++) {
        for (int j = i; j > 0 && v[j] < v[j - 1]; j--) {
            std::swap(v[j], v[j - 1]);
        }
    }
}

/**
 * @brief Sorts a vector using the shell sort algorithm.
 * 
 * @tparam T The type of elements in the vector.
 * @param v The vector to be sorted.
 */
template <class T>
void shellSort(std::vector<T> &v) {
    if (v.empty()) return;

    for (int gap = v.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < v.size(); i++) {
            T temp = v[i];
            int j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            v[j] = temp;
        }
    }
}

/**
 * @brief Merges two subarrays of a vector.
 * 
 * @tparam T The type of elements in the vector.
 * @param A The original vector.
 * @param B A temporary vector used for merging.
 * @param low The starting index of the first subarray.
 * @param mid The ending index of the first subarray.
 * @param high The ending index of the second subarray.
 */
template <class T>
void merge(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    while (i <= mid) {
        B[k++] = A[i++];
    }

    while (j <= high) {
        B[k++] = A[j++];
    }
}

/**
 * @brief Recursively splits and merges subarrays of a vector.
 * 
 * @tparam T The type of elements in the vector.
 * @param A The original vector.
 * @param B A temporary vector used for merging.
 * @param low The starting index of the subarray.
 * @param high The ending index of the subarray.
 */
template <class T>
void split(std::vector<T> &A, std::vector<T> &B, int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    split(A, B, low, mid);
    split(A, B, mid + 1, high);
    merge(A, B, low, mid, high);

    std::copy(B.begin() + low, B.begin() + high + 1, A.begin() + low);
}

/**
 * @brief Sorts a vector using the merge sort algorithm.
 * 
 * @tparam T The type of elements in the vector.
 * @param v The vector to be sorted.
 */
template <class T>
void mergeSort(std::vector<T> &v) {
    if (v.empty()) return;

    std::vector<T> temp(v.size());
    split(v, temp, 0, v.size() - 1);
}


/**
 * @brief Selects the pivot position for the quicksort partition step.
 *
 * This implementation chooses the middle index of the current range as the
 * pivot position. The selected index is used to retrieve the pivot value
 * before partitioning the subarray.
 *
 * @param low Lower inclusive index of the current subarray.
 * @param high Upper inclusive index of the current subarray.
 *
 * @return Index of the selected pivot element.
 *
 * @note This function does not access or modify the container. It only
 *       calculates a valid index inside the provided range.
 */
int selectPivot(int low, int high) {
    return low + ((high - low) / 2);
}

/**
 * @brief Partitions a subarray using the Hoare partitioning scheme.
 *
 * The function rearranges the elements in the range [low, high] around the
 * specified pivot value. Elements smaller than the pivot are moved toward
 * the left side, while elements greater than the pivot are moved toward the
 * right side.
 *
 * Two indexes scan the range from opposite directions. When both indexes
 * identify elements that are on the wrong side of the pivot, they are swapped.
 * The process ends when the indexes cross.
 *
 * @tparam T Type of elements stored in the vector.
 *
 * @param v Vector containing the elements to partition.
 * @param low Lower inclusive index of the partition range.
 * @param high Upper inclusive index of the partition range.
 * @param pivot Value used as the reference for partitioning.
 *
 * @return Final index that separates the two resulting partitions.
 *
 * @complexity
 * - Time complexity: O(n), where n is the number of elements in the range.
 * - Auxiliary space complexity: O(1).
 */
template <class T>
int makePartition(std::vector<T> &v, int low, int high, T pivot) {
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (v[i] < pivot);
        
        do {
            j--;
        } while (v[j] > pivot);
            
        if (i >= j) {
            break;
        }

        std::swap(v[i], v[j]);
    }
    return j;
}

/**
 * @brief Recursively sorts a subarray using the quicksort algorithm.
 *
 * The function applies the divide-and-conquer strategy:
 * 1. Selects a pivot element.
 * 2. Partitions the current range around the pivot.
 * 3. Recursively sorts the left and right partitions.
 *
 * This implementation uses the Hoare partitioning scheme, where the returned
 * partition index indicates the boundary between the resulting subarrays and
 * does not necessarily represent the final position of the pivot element.
 *
 * @tparam T Type of elements stored in the vector.
 *
 * @param v Vector containing the elements to sort.
 * @param low Lower inclusive index of the current subarray.
 * @param high Upper inclusive index of the current subarray.
 *
 * @complexity
 * - Average time complexity: O(n log n).
 * - Worst-case time complexity: O(n²), depending on pivot selection and input distribution.
 * - Auxiliary space complexity: O(log n) average due to recursive calls.
 */
template <class T>
void quick(std::vector<T> &v, int low, int high) {
    if ((high - low) < 2) {
        return;
    }

    int pivot = selectPivot(low, high);

    int pos = makePartition(v, low, high, v[pivot]);

    quick(v, low, pos);
    quick(v, pos + 1, high);
}

/**
 * @brief Sorts a vector in ascending order using the quicksort algorithm.
 *
 * This function provides the public interface for the quicksort implementation.
 * It validates that the input vector contains elements and starts the recursive
 * sorting process over the complete vector range.
 *
 * @tparam T Type of elements stored in the vector.
 *
 * @param v Vector to sort.
 *
 * @complexity
 * - Average time complexity: O(n log n).
 * - Worst-case time complexity: O(n²).
 * - Auxiliary space complexity: O(log n) average due to recursion depth.
 */
template <class T>
void quickSort(std::vector<T> &v) {
    if (v.empty()) return;
    
    quick(v, 0, v.size() - 1);
}

#endif /* SORTS_H */