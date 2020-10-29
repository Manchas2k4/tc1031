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

using namespace std;

template <class T> class SplayTree;

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class Node {
private:
	T value;
	Node *left, *right, *parent;

	Node(T);

	void inOrder(stringstream&) const;
	void postOrder(stringstream&) const;
	void preOrder(stringstream&) const;

	friend class SplayTree<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(NULL), right(NULL), parent(NULL) {}

template <class T>
void Node<T>::inOrder(stringstream &aux) const {
	if (left != NULL) {
		left->inOrder(aux);
	}
	aux << "." << value << ".";
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
class SplayTree {
private:
	Node<T> *root;

	void zig(Node<T>*);
	void zigZig(Node<T>*);
	void zigZag(Node<T>*);
	void splay(Node<T>*);

	Node<T>* subtreeMax(Node<T> *);
	Node<T>* subtreeMin(Node<T> *);

public:
	SplayTree();
	bool empty() const;
	Node<T>* find(T);
	void insert(T);
	void remove(T);

	string inOrder() const;
	string postOrder() const;
	string preOrder() const;
};

template <class T>
SplayTree<T>::SplayTree()
	: root(NULL) {}

template <class T>
bool SplayTree<T>::empty() const {
	return (root == NULL);
}

template <class T>
void SplayTree<T>::zig(Node<T> *x) {
	Node<T> *p = x->parent;

	if (p->left == x) {
		Node<T> *A = x->left;
		Node<T> *B = x->right;
		Node<T> *C = p->right;

		x->parent = NULL;
		x->right = p;

		p->parent = x;
		p->left = B;

		if (B != NULL) {
			B->parent = p;
		}
	} else {
		Node<T> *A = p -> left;
    Node<T> *B = x -> left;
    Node<T> *C = x -> right;

    x->parent = NULL;
    x->left = p;

    p->parent = x;
    p->right = B;

    if (B != NULL) {
			B->parent = p;
		}
	}
}

template <class T>
void SplayTree<T>::zigZig(Node<T> *x) {
    Node<T> *p = x->parent;
    Node<T> *g = p->parent;

    if (p->left == x) {
			Node<T> *A = x->left;
			Node<T> *B = x->right;
			Node<T> *C = p->right;
			Node<T> *D = g->right;

			x->parent = g->parent;
			x->right = p;

			p->parent = x;
			p->left = B;
			p->right = g;

			g->parent = p;
			g->left = C;

			if (x->parent != NULL) {
				if (x->parent->left == g) {
					x->parent->left = x;
				} else {
					x->parent->right = x;
				}
			}

			if (B != NULL) {
				B->parent = p;
			}

			if (C != NULL) {
				C->parent = g;
			}
    } else {
			Node<T> *A = g->left;
			Node<T> *B = p->left;
			Node<T> *C = x->left;
			Node<T> *D = x->right;

			x->parent = g->parent;
			x->left = p;

			p->parent = x;
			p->left = g;
			p->right = C;

			g->parent = p;
			g->right = B;

			if (x->parent != NULL) {
				if (x->parent->left == g) {
					x->parent->left = x;
				} else {
					x->parent->right = x;
				}
			}

			if (B != NULL) {
				B->parent = g;
			}

			if (C != NULL) {
				C->parent = p;
			}
    }
}

template <class T>
void SplayTree<T>::zigZag(Node<T> *x) {
	Node<T> *p = x->parent;
	Node<T> *g = p->parent;

	if (p->right == x) {
		Node<T> *A = p->left;
		Node<T> *B = x->left;
		Node<T> *C = x->right;
		Node<T> *D = g->right;

		x->parent = g->parent;
		x->left = p;
		x->right = g;

		p->parent = x;
		p->right = B;

		g->parent = x;
		g->left = C;

		if (x->parent != NULL) {
			if (x->parent->left == g) {
				x->parent->left = x;
			}
			else {
				x->parent->right = x;
			}
		}

		if (B != NULL) {
			B->parent = p;
		}

		if (C != NULL) {
			C->parent = g;
		}
	}
	else {
		Node<T> *A = g->left;
		Node<T> *B = x->left;
		Node<T> *C = x->right;
		Node<T> *D = p->right;

		x->parent = g->parent;
		x->left = g;
		x->right = p;

		p->parent = x;
		p->left = C;

		g->parent = x;
		g->right = B;

		if (x->parent != NULL) {
			if (x->parent->left == g) {
				x->parent->left = x;
			} else {
				x->parent->right = x;
			}
		}

		if (B != NULL) {
			B->parent = g;
		}

		if (C != NULL) {
			C->parent = p;
		}
	}
}

template <class T>
void SplayTree<T>::splay(Node<T> *x) {
	while (x->parent != NULL) {
		Node<T> *p = x->parent;
		Node<T> *g = p->parent;
		if (g == NULL) {
			zig(x);
		} else if (g->left == p && p->left == x) {
			zigZig(x);
		}	else if (g->right == p && p->right == x) {
			zigZig(x);
		} else {
			zigZag(x);
		}
	}
	this -> root = x;
}

template <class T>
Node<T>* SplayTree<T>::find(T x) {
	Node<T> *ret = NULL;
	Node<T> *curr = this -> root;
	Node<T> *prev = NULL;

	while (curr != NULL) {
		prev = curr;
		if (x < curr->value) {
			curr = curr -> left;
		} else if (x > curr->value) {
			curr = curr -> right;
		} else {
			ret = curr;
			break;
		}
	}

	if (ret != NULL) {
		splay(ret);
	} else if (prev != NULL) {
		splay(prev);
	}
	return ret;
}

template <class T>
void SplayTree<T>::insert(T x) {
	if (root == NULL) {
		root = new Node<T>(x);
		std::cout << "adding " << x << "\n";
		return;
	}

	Node<T> *curr = this->root;
	while (curr != NULL) {
		if (x < curr->value) {
			if (curr->left == NULL) {
				Node<T> *newNode = new Node<T>(x);
				curr->left = newNode;
				newNode->parent = curr;
				splay(newNode);
				return;
			} else {
				curr = curr->left;
			}
		} else if (x > curr->value) {
			if (curr->right == NULL) {
				Node<T> *newNode = new Node<T>(x);
				curr->right = newNode;
				newNode->parent = curr;
				splay(newNode);
				return;
			} else {
				curr = curr->right;
			}
		} else {
			splay(curr);
			return;
		}
	}
}

template <class T>
Node<T>* SplayTree<T>::subtreeMax(Node<T>*subRoot) {
    Node<T>* curr = subRoot;
    while (curr->right != NULL) {
			curr = curr->right;
		}
    return curr;
}

template <class T>
Node<T>* SplayTree<T>::subtreeMin(Node<T>*subRoot) {
    Node<T>* curr = subRoot;
    while (curr->left != NULL) {
			curr = curr->left;
		}
    return curr;
}

template <class T>
void SplayTree<T>::remove(T x) {
	Node<T> *del = find(x);
	if (del == NULL) {
		return;
	}

	Node<T> *L = del->left;
	Node<T> *R = del->right;
	if (L == NULL && R == NULL) {
		this->root = NULL;
	} else if (L == NULL) {
		Node<T> *M = subtreeMin(R);
		splay(M);
	} else if (R == NULL) {
		Node<T> *M = subtreeMax(L);
		splay(M);
	}	else {
		Node<T> *M = subtreeMax(L);
		splay(M);
		M->right = R;
		R->parent = M;
	}
	delete del;
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
