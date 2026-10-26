// =================================================================
// File: evaltree.h
// Author: Pedro Perez
// Description: This file contains the implementation of evaluation
//              tree.
//
// Copyright (c) 2024 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef EVALTREE_H
#define EVALTREE_H

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <stdexcept>

/**
 * @brief Forward declaration of the EvalTree class.
 */
class EvalTree;

/**
 * @class Node
 * @brief Represents an individual node within an expression tree.
 *
 * Each node stores either an operand (numeric value as a string) or a binary operator
 * (+, -, *, /) along with pointers to its left and right child nodes.
 */
class Node {
private:
    std::string value; ///< Symbol or numeric operand represented as a string.
    Node *left;        ///< Pointer to the left child subtree operand.
    Node *right;       ///< Pointer to the right child subtree operand.

    /**
     * @brief Constructs a leaf node storing an operand value.
     * @param val The string representation of the operand.
     */
    Node(std::string val);

    /**
     * @brief Constructs an internal operator node with specified left and right child subtrees.
     * @param val The string representation of the binary operator.
     * @param le Pointer to the left child node.
     * @param ri Pointer to the right child node.
     */
    Node(std::string val, Node* le, Node* ri);

    /**
     * @brief Recursively evaluates the mathematical expression represented by the subtree rooted at this node.
     * @return double The calculated arithmetic value of the subtree.
     * @throw std::invalid_argument If a leaf node value cannot be converted to a double by std::stod.
     * @throw std::out_of_range If a leaf node value exceeds double representation limits.
     */
    double eval() const;

    /**
     * @brief Performs an in-order traversal of the subtree and appends formatted tokens to a stream.
     * @param aux The output stringstream receiving the in-order token sequence.
     */
    void inOrder(std::stringstream& aux) const;

    /**
     * @brief Performs a pre-order traversal of the subtree and appends formatted tokens to a stream.
     * @param aux The output stringstream receiving the pre-order token sequence.
     */
    void preOrder(std::stringstream& aux) const;

    /**
     * @brief Performs a post-order traversal of the subtree and appends formatted tokens to a stream.
     * @param aux The output stringstream receiving the post-order token sequence.
     */
    void postOrder(std::stringstream& aux) const;

    /**
     * @brief Calculates the maximum depth (height) of the subtree rooted at this node.
     * @return int The maximum number of nodes along the longest path to a leaf node.
     */
    int height() const;

    /**
     * @brief Recursively deallocates memory for all descendant child nodes.
     * @post Resets left and right pointers to 0 (null).
     */
    void removeChildren();

    /// Permits EvalTree direct access to private Node members and constructors.
    friend class EvalTree;
};

Node::Node(std::string val) 
    : value(val), left(nullptr), right(nullptr) {}


Node::Node(std::string val, Node *le, Node *ri) 
    : value(val), left(le), right(ri) {}


double Node::eval() const {
    double le = 0, ri = 0;

    if (!left && !right) {
        return stod(value);
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

void Node::inOrder(std::stringstream &aux) const {
    if (left) {
        left->inOrder(aux);
    }
    aux << value << " ";
    if (right) {
        right->inOrder(aux);
    }
}

void Node::preOrder(std::stringstream &aux) const {
    aux << value << " ";
    if (left) {
        left->preOrder(aux);
    }
    if (right) {
        right->preOrder(aux);
    }
}

void Node::postOrder(std::stringstream &aux) const {
    if (left) {
        left->postOrder(aux);
    }
    if (right) {
        right->postOrder(aux);
    }
    aux << value << " ";
}

int Node::height() const {
    int le = 0, ri = 0;

    if (!left && !right) {
        return 1;
    }

    le = 0;
    if (left) {
        le = left->height();
    }

    ri = 0;
    if (right) {
        ri = right->height();
    }

    return ((le > ri)? le : ri) + 1;
}

void Node::removeChildren() {
    if (left) {
        left->removeChildren();
        delete left;
        left = nullptr;
    }

    if (right) {
        right->removeChildren();
        delete right;
        right = nullptr;
    }
}

/**
 * @class EvalTree
 * @brief Represents a binary expression tree for parsing, evaluating, and traversing arithmetic expressions.
 *
 * This class builds an expression tree from a fully-parenthesized, space-separated infix string.
 * It provides methods for computing the numerical result, querying tree structural properties,
 * and obtaining string representations of in-order, pre-order, post-order, and level-order traversals.
 */
class EvalTree {
private:
    Node *root; ///< Pointer to the root node of the binary expression tree.

public:
    /**
     * @brief Constructs an EvalTree by parsing a space-separated infix arithmetic expression string.
     *
     * Parses the string using a operator/operand stack-based approach. Converts sub-expressions enclosed
     * in parentheses into binary tree nodes.
     *
     * @param input A space-separated infix expression string starting with '('.
     *
     * @pre Expression tokens must be strictly separated by whitespace (e.g., "( ( 3 + 5 ) * 2 )").
     * @pre Sub-expressions must be explicitly grouped with matching parentheses.
     *
     * @throw std::invalid_argument If the input expression violates syntax constraints, contains unbalanced
     *        parentheses, lacks operands for an operator, or leaves disconnected nodes.
     */
    EvalTree(std::string input);

    /**
     * @brief Destructor that frees all dynamically allocated nodes in the tree.
     */
    ~EvalTree();

    /**
     * @brief Evaluates the entire binary expression tree.
     * @return double The calculated result of the arithmetic tree expression, or 0 if the tree is empty.
     */
    double eval() const;

    /**
     * @brief Checks whether the evaluation tree is empty.
     * @return true If the tree has no root node; false otherwise.
     */
    bool empty() const;

    /**
     * @brief Generates an in-order traversal string of the expression tree.
     * @return std::string Space-delimited in-order representation enclosed in square brackets `[...]`.
     */
    std::string inOrder() const;

    /**
     * @brief Generates a post-order traversal string of the expression tree.
     * @return std::string Space-delimited post-order representation enclosed in square brackets `[...]`.
     */
    std::string postOrder() const;

    /**
     * @brief Generates a pre-order traversal string of the expression tree.
     * @return std::string Space-delimited pre-order representation enclosed in square brackets `[...]`.
     */
    std::string preOrder() const;

    /**
     * @brief Generates a level-order (breadth-first) traversal string of the expression tree.
     * @return std::string Space-delimited level-order representation enclosed in square brackets `[...]`.
     */
    std::string perLevel() const;

    /**
     * @brief Computes the height of the binary expression tree.
     * @return int The maximum height (number of levels) of the tree, or 0 if empty.
     */
    int height() const;

    /**
     * @brief Computes the total number of levels in the binary expression tree.
     * @return int The level count (equivalent to the tree height), or 0 if empty.
     */
    int levels() const;
};

EvalTree::EvalTree(std::string input) {
    Node *le = nullptr, *ri = nullptr, *r = nullptr;
    std::stack<Node*> operands;
    std::stack<std::string> operators;
    std::stringstream ss(input);
    std::string data;

    if (input.empty()) {
        root = nullptr;
        return;
    }

    if (input[0] != '(') {
        throw std::invalid_argument("Syntax error: The expression must start with an opening parenthesis '('");
    }
    
    while (ss >> data) {
        if (data == "(" || data == "*" || data == "-" || data == "+" || data == "/") {
            operators.push(data);
        } else if (data == ")") {
            if (operators.empty()) {
                throw std::invalid_argument("Syntax error: Unexpected closing parenthesis ')'");
            }

            std::string top = operators.top(); 
            while (top != "(") {
                operators.pop();
                
                if (operands.empty()) {
                    throw std::invalid_argument("Syntax error: Missing right operand for operator '" + top + "'");
                }
                ri = operands.top(); operands.pop(); 
                
                if (operands.empty()) {
                    // Prevent memory leak before throwing
                    delete ri;
                    throw std::invalid_argument("Syntax error: Missing left operand for operator '" + top + "'");
                }
                le = operands.top(); operands.pop();
                
                operands.push(new Node(top, le, ri));

                if (operators.empty()) {
                    throw std::invalid_argument("Syntax error: Unbalanced parentheses, missing opening '('");
                }
                top = operators.top();
            }
            operators.pop(); // Remove '('
        } else {
            operands.push(new Node(data));
        }
    }

    if (!operators.empty()) {
        throw std::invalid_argument("Syntax error: Unclosed operators or missing closing parenthesis ')'");
    }

    if (operands.empty()) {
        throw std::invalid_argument("Build error: Expression produced no valid operands or nodes");
    }

    r = operands.top(); operands.pop();
    if (!operands.empty()) {
        r->removeChildren();
        delete r;
        
        // Clean up remaining dangling nodes in the stack to prevent memory leaks
        while (!operands.empty()) {
            Node* pending = operands.top(); operands.pop();
            pending->removeChildren();
            delete pending;
        }
        throw std::invalid_argument("Syntax error: Extra operands found or disconnected expressions");
    }
    root = r;
}

EvalTree::~EvalTree() {
    if (root) {
        root->removeChildren();
    }
    delete root;
}

double EvalTree::eval() const {
    double result = 0;
    if (root) {
        result = root->eval();
    }
    return result;
}

bool EvalTree::empty() const {
    return (root == nullptr);
}

std::string EvalTree::inOrder() const {
    std::stringstream aux;

    aux << "[";
    if (root) {
        root->inOrder(aux);
    }
    aux << "]";
    return aux.str();
}

std::string EvalTree::preOrder() const {
    std::stringstream aux;

    aux << "[";
    if (root) {
        root->preOrder(aux);
    }
    aux << "]";
    return aux.str();
}

std::string EvalTree::postOrder() const {
    std::stringstream aux;

    aux << "[";
    if (root) {
        root->postOrder(aux);
    }
    aux << "]";
    return aux.str();
}

std::string EvalTree::perLevel() const {
    std::stringstream aux;
    std::queue<Node*> q;

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

int EvalTree::height() const {
    return (root)? root->height() : 0;
}

int EvalTree::levels() const {
    return (root)? root->height() : 0;
}

#endif