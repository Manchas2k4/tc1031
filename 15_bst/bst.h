/*
 * bst.h
 *
 *  Created on: 30/10/2015
 *      Author: clase
 */

#ifndef BST_H
#define BST_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include "exception.h"

using namespace std;

typedef unsigned int uint;

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
	uint depth() const;

	void add(T);

	Node<T>* succesor();
	void remove(T);
	void removeChilds();

	void inOrder(stringstream&) const;
	void postOrder(stringstream&) const;
	void preOrder(stringstream&) const;

	uint leaves() const;
	bool isFull() const;
	T ancestor(T) const;

	friend class BST<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(NULL), right(NULL) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}

template <class T>
bool Node<T>::find(T val) {
	if (val == value) {
		return true;
	} else if (val < value) {
		return (left != NULL && left->find(val));
	} else {
		return (right != NULL && right->find(val));
	}
}

template <class T>
uint Node<T>::depth() const {
    int le = 0;
    int ri = 0;
    int de = 0;

    if (left == NULL && right == NULL) {
    	return 0;
    }

    if (left != NULL) {
        le = left->depth();
    }

    if (right != NULL) {
        ri = right->depth();
    }
		return (max(le, ri) + 1);
}

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

template <class T>
void Node<T>::remove(T val) {
	Node<T> * succ, *old;

	if (val < value) {
		if (left != NULL) {
			if (left->value == val) {
				old = left;
				succ = left->succesor();
				if (succ != NULL) {
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
				if (succ != NULL) {
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

template <class T>
void Node<T>::inOrder(stringstream &aux) const {
	if (left != NULL) {
		left->inOrder(aux);
	}
	aux << value << " ";
	if (right != NULL) {
		right->inOrder(aux);
	}
}

template <class T>
void Node<T>::postOrder(stringstream &aux) const {
	if (left != 0) {
		left->postOrder(aux);
	}
	if (right != 0) {
		right->postOrder(aux);
	}
	aux << value << " ";
}

template <class T>
void Node<T>::preOrder(stringstream &aux) const {
	aux << value << " ";
	if (left != NULL) {
		left->preOrder(aux);
	}
	if (right != NULL) {
		right->preOrder(aux);
	}
}

template <class T>
uint Node<T>::leaves() const {
	return 0;
}

template <class T>
bool Node<T>::isFull() const {
	return false;
}

template <class T>
T Node<T>::ancestor(T val) const {
	return T();
}

template <class T>
class BST {
private:
	Node<T> *root;

public:
	BST();
	~BST();
	bool empty() const;
	bool find(T) const;
	uint levels() const;

	void add(T);

	void remove(T);
	void removeAll();

	string inOrder() const;
	string postOrder() const;
	string preOrder() const;
	string byLevel() const;

	uint leaves() const;
	bool isFull() const;
	T ancestor(T) const;
};

template <class T>
BST<T>::BST() : root(NULL) {}

template <class T>
BST<T>::~BST() {
	removeAll();
}

template <class T>
bool BST<T>::empty() const {
	return (root == NULL);
}

template <class T>
bool BST<T>::find(T val) const {
	if (!empty()) {
		return root->find(val);
	} else {
		return false;
	}
}

template<class T>
uint BST<T>::levels() const {
	if (!empty()) {
		return root->depth();
	} else {
		return -1;
	}
}

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

template <class T>
void BST<T>::remove(T val) {
	if (!empty()) {
		if (val == root->value) {
			Node<T> *succ = root->succesor();
			if (succ != NULL) {
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

template <class T>
void BST<T>::removeAll() {
	if (!empty()) {
		root->removeChilds();
		delete root;
		root = NULL;
	}
}

template <class T>
string BST<T>::inOrder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inOrder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::preOrder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preOrder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::postOrder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->postOrder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::byLevel() const {
	stringstream aux;

	return aux.str();
}

template <class T>
uint BST<T>::leaves() const {
	return 0;
}

template <class T>
bool BST<T>::isFull() const {
	return false;
}

template <class T>
T BST<T>::ancestor(T val) const {
	return T();
}

#endif /* BST_H */
