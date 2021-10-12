// =================================================================
//
// File: bst.h
// Author: Pedro Perez
// Description: This file contains the implementation of TDA
//							Binary Search Tree.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef BST_H
#define BST_H

#include <iostream>
#include <sstream>
#include <string>
#include "exception.h"
#include "header.h"

template <class T> class BST;

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class Node {
private:
	T value;
	Node *left, *right;

	Node(T);
	Node(T, Node<T>*, Node<T>*);

	bool find(T) const;

	void add(T);

	Node<T>* succesor();
	void remove(T);

	void removeChilds();

	void inOrder(std::stringstream&) const;
	void postOrder(std::stringstream&) const;
	void preOrder(std::stringstream&) const;

	friend class BST<T>;
};

// =================================================================
// Constructor. Initializes the value of the node. The variables
// left and right a initialized to null.
//
// @param val, stored value in the node.
// =================================================================
template <class T>
Node<T>::Node(T val) : value(val), left(NULL), right(NULL) {}

// =================================================================
// Constructor. Initializes all instances variables.
//
// @param val, stored value in the node.
// =================================================================
template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}

// =================================================================
// Search for an element within the bst.
//
// @param val, the searched element.
// returns True, if the element is in the bst. False, otherwise.
// =================================================================
template <class T>
bool Node<T>::find(T val) const {
	if (val == value) {
		return true;
	} else if (val < value) {
		return (left != NULL && left->find(val));
	} else {
		return (right != NULL && right->find(val));
	}
}

// =================================================================
// Add an element within the bst.
//
// @param val, the element to be inserted.
// =================================================================
template <class T>
void Node<T>::add(T val) {
	if (val < value) {
		if (left != NULL) {
			left->add(val);
		} else {
			left = new Node<T>(val);
		}
	} else {
		if (right != NULL) {
			right->add(val);
		} else {
			right = new Node<T>(val);
		}
	}
}

// =================================================================
// Finds the correct successor for a parent node.
//
// returns the successor node of a node or NULL, if it a leaf node.
// =================================================================
template <class T>
Node<T>* Node<T>::succesor() {
	Node<T> *le, *ri;

	le = left;
	ri = right;

	if (left == NULL && right == NULL) {
		return NULL;
	}

	if (left == NULL && right != NULL) {
		right = NULL;
		return ri;
	}

	if (left != NULL && left->right == NULL) {
		left = le->left;
		le->left = NULL;
		return le;
	}

	if (left != NULL && left->right != NULL) {
		Node<T> *parent, *child;
		parent = left;
		child = left->right;

		while (child->right != NULL) {
			parent = child;
			child = child->right;
		}
		parent->right = child->left;
		child->left = NULL;
		return child;
	}

	return NULL;
}

// =================================================================
// Remove an elemento, putting a suc node in its place.
//
// param @val, the element to be removed.
// =================================================================

template <class T>
void Node<T>::remove(T val) {
	Node<T> * succ, *old;

	if (val < value) {
		if (left != NULL) {
			if (left->value == val) {
				old = left;
				succ = left->succesor();
				if (succ != NULL && (old->left != NULL || old->right != NULL)) {
					succ->left = old->left;
					succ->right = old->right;
				}
				left = succ;
				delete old;
			} else {
				left->remove(val);
			}
		}
	} else if (val > value) {
		if (right != NULL) {
			if (right->value == val) {
				old = right;
				succ = right->succesor();
				if (succ != NULL && (old->left != NULL || old->right != NULL)) {
					succ->left = old->left;
					succ->right = old->right;
				}
				right = succ;
				delete old;
			} else {
				right->remove(val);
			}
		}
	}
}

// =================================================================
// Removes, recursively, the childs of a parent node.
//
// =================================================================
template <class T>
void Node<T>::removeChilds() {
	if (left != NULL) {
		left->removeChilds();
		delete left;
		left = NULL;
	}

	if (right != NULL) {
		right->removeChilds();
		delete right;
		right = NULL;
	}
}

// =================================================================
// Go through the tree in inorder.
//
// @param aux, a stringstream used to create the string to display.
// =================================================================
template <class T>
void Node<T>::inOrder(std::stringstream &aux) const {
	if (left != NULL) {
		left->inOrder(aux);
	}
	aux << value << " ";
	if (right != NULL) {
		right->inOrder(aux);
	}
}

// =================================================================
// Go through the tree in postorder.
//
// @param aux, a stringstream used to create the string to display.
// =================================================================
template <class T>
void Node<T>::postOrder(std::stringstream &aux) const {
	if (left != 0) {
		left->postOrder(aux);
	}
	if (right != 0) {
		right->postOrder(aux);
	}
	aux << value << " ";
}

// =================================================================
// Go through the tree in preorder.
//
// @param aux, a stringstream used to create the string to display.
// =================================================================
template <class T>
void Node<T>::preOrder(std::stringstream &aux) const {
	aux << value << " ";
	if (left != NULL) {
		left->preOrder(aux);
	}
	if (right != NULL) {
		right->preOrder(aux);
	}
}

// =================================================================
// Definition of the Binary Search Tree class
// =================================================================
template <class T>
class BST {
private:
	Node<T> *root;

public:
	BST();
	~BST();
	bool empty() const;
	bool find(T) const;

	void add(T);

	void remove(T);
	void removeAll();

	std::string inOrder() const;
	std::string postOrder() const;
	std::string preOrder() const;
};

template <class T>
BST<T>::BST() : root(NULL) {}

template <class T>
BST<T>::~BST() {
	removeAll();
}

// =================================================================
// Returns if the bst is empty or not.
//
// returns True is the root node is NULL. False, if the bst is
//				 empty.
// =================================================================
template <class T>
bool BST<T>::empty() const {
	return (root == NULL);
}

// =================================================================
// Search for an element within the bst.
//
// @param val, the searched element.
// returns the result of searching for an element within the tree.
//				 False, if the bst is empty.
// =================================================================
template <class T>
bool BST<T>::find(T val) const {
	if (!empty()) {
		return root->find(val);
	} else {
		return false;
	}
}

// =================================================================
// Add an element within the bst.
//
// @param val, the element to be inserted.
// =================================================================
template<class T>
void BST<T>::add(T val) {
	if (!empty()) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}

// =================================================================
// Removes an element from the bst.
//
// @param val, the element to be removed.
// =================================================================
template <class T>
void BST<T>::remove(T val) {
	if (!empty()) {
		if (val == root->value) {
			Node<T> *succ = root->succesor();
			if (succ != NULL && (root->left != NULL || root->right != NULL)) {
				succ->left = root->left;
				succ->right = root->right;
			}
			delete root;
			root = succ;
		} else {
			root->remove(val);
		}
	}
}

// =================================================================
// Removes all the elements from the bst.
//
// =================================================================
template <class T>
void BST<T>::removeAll() {
	if (!empty()) {
		root->removeChilds();
		delete root;
		root = NULL;
	}
}

// =================================================================
// Go through the tree in inorder.
//
// returns a string with the result of the inorder traverse of the
//				 bst.
// =================================================================
template <class T>
std::string BST<T>::inOrder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inOrder(aux);
	}
	aux << "]";
	return aux.str();
}

// =================================================================
// Go through the tree in preorder.
//
// returns a string with the result of the preorder traverse of the
//				 bst.
// =================================================================
template <class T>
std::string BST<T>::preOrder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preOrder(aux);
	}
	aux << "]";
	return aux.str();
}

// =================================================================
// Go through the tree in posrorder.
//
// returns a string with the result of the posrorder traverse of the
//				 bst.
// =================================================================
template <class T>
std::string BST<T>::postOrder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->postOrder(aux);
	}
	aux << "]";
	return aux.str();
}
#endif /* BST_H */
