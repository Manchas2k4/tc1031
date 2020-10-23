// =================================================================
//
// File: splay.h
// Author: Pedro Perez
// Description: This file contains the implementation of TDA
//							Splay Tree.
// Modified from:
// 	https://www.geeksforgeeks.org/splay-tree-set-1-insert/
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

template <class T> class SplayTree;

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

	Node<T>* rightRotate();
	Node<T>* leftRotate();
	Node<T>* splay(T, bool&);

	void add(T);

	Node<T>* succesor();
	void remove(T);
	void removeChilds();

	void inOrder(stringstream&) const;
	void postOrder(stringstream&) const;
	void preOrder(stringstream&) const;

	friend class SplayTree<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(NULL), right(NULL) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}

template <class T>
Node<T>* Node<T>::rightRotate() {
	Node<T> *y;

	y = this->left;
	this->left = y->right;
	y->right = this;
	return y;
}

template <class T>
Node<T>* Node<T>::leftRotate() {
	Node<T> *y;

	y = this->right;
	this->right = y->left;
	y->left = this;
	return y;
}

template <class T>
Node<T>* Node<T>::splay(T val, bool& found) {
	if (this->value == val) {
		found = true;
		return this;
	} else // Key lies in left subtree
	if (val < this->value) {
	  // Key is not in tree, we are done
	  if (this->left == NULL) {
	    found = false;
			return this;
	  }
		// Zig-Zig (Left Left)
    if (val < this->left->value) {
			if (this->left->left == NULL) {
				found = false;
			} else {
	      // First recursively bring the key as this of left-left
	      this->left->left = this->left->left->splay(val, found);
			}
			// Do first rotation for this, second rotation is done after else
			this = this->rightRotate();
    } else if (val > this->left->value) { // Zig-Zag (Left Right)
			if (this->left->right == NULL) {
				found = false;
			} else {
	      // First recursively bring the key as this of left-left
	      this->left->right = this->left->right->splay(val, found);
			}
			// Do first rotation for this->left
			if (this->left->right != NULL) {
				this->left = this->leftRotate();
			}
		}
		// Do second rotation for this
		return (this->left == NULL)? this : this->rightRotate();
	} else { // Key lies in right subtree
		if (this->right == NULL) {
	    found = false;
			return this;
	  }
		// Zag-Zig (Right Left)
		if (val < this->right->value) {
			// Bring the key as root of right-left
			if (this->right->left == NULL) {
				found = false;
			} else {
	      // First recursively bring the key as this of left-left
	      this->right->left = this->right->left->splay(val, found);
			}
			// Do first rotation for this->right
			if (this->right->left != NULL) {
				this->right = this->right->rightRotate();
			}
		} else if (val > this->right->value) {
			// Bring the key as this of right-right and do first rotation
			if (this->right->right == NULL) {
				found = false;
			} else {
	      // First recursively bring the key as this of left-left
	      this->right->right = this->right->right->splay(val, found);
			}
			this = this->leftRotate();
		}
		// Do second rotation for root
		return (this->right == NULL)? this : this->leftRotate();
	}
}

template <class T>
void Node<T>::add(T val) {
	if (val < this->value) {
		if (this->left != NULL) {
			this->left->add(val);
		} else {
			this->left = new Node<T>(val);
		}
	} else if (val > this->value) {
		if (this->right != NULL) {
			this->right->add(val);
		} else {
			this->right = new Node<T>(val);
		}
	}
}

template <class T>
Node<T>* Node<T>::succesor() {
	Node<T> *le, *ri;

	le = this->left;
	ri = this->right;

	if (this->left == NULL && this->right == NULL) {
		return NULL;
	}

	if (this->left == NULL && this->right != NULL) {
		this->right = NULL;
		return ri;
	}

	if (this->left != NULL && this->left->right == NULL) {
			this->left = le->left;
			le->left = NULL;
			return le;
	}

	if (this->left != NULL && this->left->right != NULL) {
		Node<T> *parent, *child;
		parent = this->left;
		child = this->left->right;

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

	if (val < this->value) {
		if (this->left != NULL) {
			if (this->left->value == val) {
				old = this->left;
				succ = this->left->succesor();
				if (succ != NULL) {
					succ->left = old->left;
					succ->right = old->right;
				}
				this->left = succ;
				delete old;
			} else {
				this->left->remove(val);
			}
		}
	} else if (val > this->value) {
		if (this->right != NULL) {
			if (this->right->value == val) {
				old = this->right;
				succ = this->right->succesor();
				if (succ != NULL) {
					succ->left = old->left;
					succ->right = old->right;
				}
				this->right = succ;
				delete old;
			} else {
				this->right->remove(val);
			}
		}
	}
}

template <class T>
void Node<T>::removeChilds() {
	if (this->left != NULL) {
		this->left->removeChilds();
		delete this->left;
		this->left = NULL;
	}
	if (this->right != NULL) {
		this->right->removeChilds();
		delete this->right;
		this->right = NULL;
	}
}

template <class T>
void Node<T>::inOrder(stringstream &aux) const {
	if (this->left != NULL) {
		this->left->inOrder(aux);
	}
	aux << this->value << " ";
	if (this->right != NULL) {
		this->right->inOrder(aux);
	}
}

template <class T>
void Node<T>::postOrder(stringstream &aux) const {
	if (this->left != 0) {
		this->left->postOrder(aux);
	}
	if (this->right != 0) {
		this->right->postOrder(aux);
	}
	aux << this->value << " ";
}

template <class T>
void Node<T>::preOrder(stringstream &aux) const {
	aux << this->value << " ";
	if (this->left != NULL) {
		this->left->preOrder(aux);
	}
	if (this->right != NULL) {
		this->right->preOrder(aux);
	}
}

template <class T>
class SplayTree {
private:
	Node<T> *root;

public:
	SplayTree();
	~SplayTree();
	bool empty() const;
	bool find(T);

	void add(T);

	void remove(T);
	void removeAll();

	string inOrder() const;
	string postOrder() const;
	string preOrder() const;
};

template <class T>
SplayTree<T>::SplayTree() : root(NULL) {}

template <class T>
SplayTree<T>::~SplayTree() {
	removeAll();
}

template <class T>
bool SplayTree<T>::empty() const {
	return (root == NULL);
}

template <class T>
bool SplayTree<T>::find(T val) {
	bool found;

	if (empty()) {
		return false;
	}

	if (root->value == val) {
		return true;
	}

	root = root->splay(val, found);
	return found;
}

template<class T>
void SplayTree<T>::add(T val) {
	if (!empty()) {
		root->add(val);
	} else {
		root = new Node<T>(val);
	}
}

template <class T>
void SplayTree<T>::remove(T val) {
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
void SplayTree<T>::removeAll() {
	if (!empty()) {
		root->removeChilds();
		delete root;
		root = NULL;
	}
}

template <class T>
string SplayTree<T>::inOrder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inOrder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string SplayTree<T>::preOrder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preOrder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string SplayTree<T>::postOrder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->postOrder(aux);
	}
	aux << "]";
	return aux.str();
}

#endif /* SPLAYTREE_H */
