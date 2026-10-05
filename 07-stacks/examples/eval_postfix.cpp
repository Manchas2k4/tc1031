// =================================================================
//
// File: balanced_parenthesis.cpp
// Author: Pedro Pérez
// Description: This file converts infix arithmetic expressions into 
//        		Postfix (Reverse Polish) notation
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

/**
 * @file main.cpp
 * @brief Evaluator for Postfix (Reverse Polish Notation) arithmetic expressions.
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

/**
 * @brief Evaluates a space-separated Postfix (Reverse Polish Notation) expression.
 *
 * Parses the input string token by token using standard space delimitation. Numeric 
 * tokens are converted to integers and pushed onto an evaluation stack. When an operator 
 * (+, -, *, /, ^) is encountered, the top two operands are popped, evaluated, and the 
 * resulting integer value is pushed back onto the stack.
 *
 * @param line A string containing space-separated integer operands and supported binary operators.
 * @return int The calculated integer result of the evaluated Postfix expression.
 *
 * @pre Input tokens must be strictly separated by whitespace characters (e.g., "3 4 + 2 *").
 * @pre The input string must represent a valid, well-formed RPN expression.
 * 
 * @throw std::invalid_argument If a non-operator token cannot be converted to an integer via std::stoi.
 * @throw std::out_of_range If a numeric token represents a value beyond the range of an int.
 *
 * @note Exponentiation (`^`) utilizes `std::pow`, which operates on floating-point values 
 *       and is implicitly truncated when cast back to an integer.
 *
 * @warning Calling this function with malformed expressions (e.g., insufficient operands, 
 *          unrecognized symbols, or division by zero) triggers undefined behavior or runtime exceptions.
 */
int eval(string line) {
    stack<int> theStack;
    stringstream input(line);
    string data;

    while (input >> data) {
        if (data == "+" || data == "-" || data == "*" ||
            data == "/" || data == "^") {
            int right = theStack.top(); theStack.pop();
            int left = theStack.top(); theStack.pop();
            if (data == "+") {
                theStack.push(left + right);
            } else if (data == "-") {
                theStack.push(left - right);
            } else if (data == "*") {
                theStack.push(left * right);
            } else if (data == "/") {
                theStack.push(left / right);
            } else {
                theStack.push(pow(left, right));
            }
        } else {
            theStack.push(stoi(data));
        }
    }
    return theStack.top();
}

/**
 * @brief Entry point of the application.
 *
 * Reads lines iteratively from standard input (`cin`), processes each expression through `eval()`,
 * and prints the evaluation result to standard output (`cout`).
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return int Returns 0 upon standard program execution completion.
 */
int main(int argc, char* argv[]) {
    string line;

    while(getline(cin, line)) {
        cout << "eval(" << line << ") = " << eval(line) << "\n";
    }
    return 0;
}