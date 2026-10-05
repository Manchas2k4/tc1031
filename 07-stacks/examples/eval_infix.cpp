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
 * @brief Utility for converting infix arithmetic expressions into 
 *        Postfix (Reverse Polish) notation.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

/**
 * @brief Converts a space-separated infix expression into Postfix (RPN) notation.
 *
 * Parses the input string token by token using standard space delimitation. It maintains 
 * an operator stack and an operand stack to restructure arithmetic sub-expressions enclosed 
 * within parentheses into Postfix order.
 *
 * @param line A string containing space-separated tokens representing an infix arithmetic expression.
 * @return string The formatted Postfix (Reverse Polish Notation) expression string.
 *
 * @pre Input tokens must be strictly separated by whitespace characters (e.g., "( 2 + 3 )").
 * @pre Expressions containing binary operators must be fully enclosed in matching parentheses for complete conversion.
 * 
 * @note Despite its identifier, this function converts the input string's syntax structure 
 *       rather than evaluating its numeric result.
 * 
 * @warning Calling this function with malformed input (e.g., unbalanced parentheses or missing operands) 
 *          may trigger undefined behavior due to unguarded stack access.
 */
string eval(string line) {
    stack<string> operands;
    stack<string> operators;
    stringstream input(line);
    string data;

    while (input >> data) {
        if (data == "+" || data == "-" || data == "*" ||
            data == "/" || data == "^" || data == "(") {
            operators.push(data);
        } else if (data == ")") {
            string top = operators.top(); operators.pop();
            while (top != "(") {
                string right = operands.top(); operands.pop();
                string left = operands.top(); operands.pop();
                operands.push(left + " " + right + " " + top);
                top = operators.top(); operators.pop();
            }
        } else {
            operands.push(data);
        }
    }
    return operands.top();
}

/**
 * @brief Entry point of the application.
 *
 * Reads lines iteratively from standard input (`cin`), processes each string through `eval()`,
 * and outputs the resulting expression transformation to standard output (`cout`).
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