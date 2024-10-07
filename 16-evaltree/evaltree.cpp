// =================================================================
//
// File: evaltree.cpp
// Author: Pedro Perez
// Description: This file contains the implementation of evaluation
//				tree.
//
// Copyright (c) 2024 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class EvalTree;

// =================================================================
// Definition of the Node class
// =================================================================
class Node {
private:
	string value;
	Node *left, *right;

	Node(string);
	Node(string, Node*, Node*);

	double eval() const;

	void inOrder(stringstream&) const;
	void preOrder(stringstream&) const;
	void postOrder(stringstream&) const;

	void removeChilds();

	friend class EvalTree;
};

// =================================================================
// Constructor. Initializes the value of the node. The variables
// left and right a initialized to null.
//
// @param val, stored value in the node.
// =================================================================
Node::Node(string val) 
	: value(val), left(0), right(0) {}


// =================================================================
// Constructor. Initializes all instances variables.
//
// @param val, stored value in the node.
// @param le, left child of the node.
// @param ri, right child of the node.
// =================================================================
Node::Node(string val, Node *le, Node *ri) 
	: value(val), left(le), right(ri) {}


// =================================================================
// Perform the node evaluation. 
//
// @return, the evaluation of the node
// =================================================================
double Node::eval() const {
	double le, ri;

	if (!left && !right) {
		return stoi(value);
	}

	if (left) {
		le = left->eval();
	}

	if (right) {
		ri = right->eval();
	}

	if (value == "+") {
		return le + ri;
	} else if (value == "-") {
		return le - ri;
	} else if (value == "*") {
		return le * ri;
	} else if (value == "/") {
		return le / ri;
	}

	return 0;
}

// =================================================================
// Go through the tree in inorder.
//
// @param aux, a stringstream used to create the string to display.
// =================================================================
void Node::inOrder(stringstream &aux) const {
	if (left) {
		left->inOrder(aux);
	}
	aux << value << " ";
	if (right) {
		right->inOrder(aux);
	}
}

// =================================================================
// Go through the tree in preorder.
//
// @param aux, a stringstream used to create the string to display.
// =================================================================
void Node::preOrder(std::stringstream &aux) const {
	aux << value << " ";
	if (left) {
		left->preOrder(aux);
	}
	if (right) {
		right->preOrder(aux);
	}
}

// =================================================================
// Go through the tree in postorder.
//
// @param aux, a stringstream used to create the string to display.
// =================================================================
void Node::postOrder(std::stringstream &aux) const {
	if (left) {
		left->postOrder(aux);
	}
	if (right) {
		right->postOrder(aux);
	}
	aux << value << " ";
}

// =================================================================
// Removes, recursively, the childs of a parent node.
//
// =================================================================
void Node::removeChilds() {
	if (left) {
		left->removeChilds();
		delete left;
		left = 0;
	}

	if (right) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

// =================================================================
// Definition of the Evaluation Tree class.
// =================================================================
class EvalTree {
private:
	Node *root;

public:
	EvalTree(string);
	~EvalTree();

	double eval() const;
	bool empty() const;

	string inOrder() const;
	string postOrder() const;
	string preOrder() const;
	string perLevel() const;
};

// =================================================================
// Constructor. Builds the tree from a text input.
// =================================================================
EvalTree::EvalTree(string input) {
	Node *le, *ri;
	stack<Node*> operands;
	stack<string> operators;
	stringstream ss(input);
	string data;

	root = 0;
	while (ss >> data) {
		if (data == "(" || data == "*" || data == "-" ||
			data == "+" || data == "/") {
			operators.push(data);
		} else if (data == ")") {
			string top = operators.top(); operators.pop();
			while (top != "(") {
				ri = operands.top(); operands.pop();
				le = operands.top(); operands.pop();
				operands.push(new Node(top, le, ri));
				top = operators.top(); operators.pop();
			}
		} else {
			operands.push(new Node(data));
		}
	}
	if (!operands.empty()) {
		root = operands.top();
	}
}


// =================================================================
// Destructor method
// =================================================================
EvalTree::~EvalTree() {
	root->removeChilds();
	root = 0;
}

// =================================================================
// Perform the tree evaluation. 
//
// @return, the evaluation of the tree
// =================================================================
double EvalTree::eval() const {
	double result = 0;
	if (root) {
		result = root->eval();
	}
	return result;
}

// =================================================================
// Returns if evaluation tree is empty or not.
//
// returns true is the root node is NULL. False, if the evaluation
// 			tree.
// =================================================================
bool EvalTree::empty() const {
	return (root == 0);
}

// =================================================================
// Go through the tree in inorder.
//
// returns a string with the result of the tree's inorder traverse
// =================================================================
string EvalTree::inOrder() const {
	stringstream aux;

	aux << "[";
	if (root) {
		root->inOrder(aux);
	}
	aux << "]";
	return aux.str();
}

// =================================================================
// Go through the tree in preorder.
//
// returns a string with the result of the tree's preorder traverse
// =================================================================
string EvalTree::preOrder() const {
	stringstream aux;

	aux << "[";
	if (root) {
		root->preOrder(aux);
	}
	aux << "]";
	return aux.str();
}

// =================================================================
// Go through the tree in postorder.
//
// returns a string with the result of the tree's postorder traverse
// =================================================================
string EvalTree::postOrder() const {
	stringstream aux;

	aux << "[";
	if (root) {
		root->postOrder(aux);
	}
	aux << "]";
	return aux.str();
}

// =================================================================
// Go through the tree in order level.
//
// returns a string with the result of the tree's level traverse
// =================================================================
string EvalTree::perLevel() const {
	stringstream aux;
	queue<Node*> q;

	aux << "[";
	if (root) {
		q.push(root);
		while (!q.empty()) {
			Node* n = q.front(); q.pop();
			if (n->left) {
				q.push(n->left);
			}
			if (n->right) {
				q.push(n->right);
			}
			aux << n->value << " ";
		}
	}
	aux << "]";
	return aux.str();
}

int main(int argc, char* argv[]) {
	EvalTree tree("( ( ( 3 * 2 ) + ( 8 / 2 ) ) + 7 )");

	cout << "In Order = " << tree.inOrder() << "\n";
	cout << "Pre Order = " << tree.preOrder() << "\n";
	cout << "Post Order = " << tree.postOrder() << "\n";
	cout << "Per Level = " << tree.perLevel() << "\n";
	cout << "Eval = " << tree.eval() << "\n";
	return 0;
}