// =================================================================
//
// File: balanced_parenthesis.cpp
// Author: Pedro Pérez
// Description: This file checks if the parentheses are correctly 
//              matched and nested
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

/**
 * @file balanced_parenthesis.cpp
 * @brief Checks whether the bracket characters in a string are balanced.
 *
 * Reads whitespace-separated tokens from standard input and, for each
 * one, reports whether its parentheses, square brackets and curly
 * braces are correctly matched and nested, using a stack-based
 * algorithm.
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * @brief Determines whether the brackets in @p str are balanced.
 *
 * Scans @p str once, pushing each opening bracket (`{`, `[`, `(`) onto a
 * stack. For each closing bracket encountered, the string is rejected
 * if the stack is empty or if the bracket does not match the type on
 * top of the stack; otherwise the matching opening bracket is popped.
 * Characters other than the six bracket characters are not inspected
 * and do not affect the result.
 *
 * @param str String to validate.
 * @return @c true (as a nonzero @c int) if every opening bracket in
 *         @p str has a matching, correctly nested closing bracket and
 *         none are left unmatched; @c false (0) otherwise.
 */
bool isValid(const string &str) {
    stack<char> s;
    int i;
    char top;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            s.push(str[i]);
        } else {
            if (s.empty()) {
                return false;
            }
            if (str[i] == '}' && s.top() != '{') {
                return false;
            }
            if (str[i] == ']' && s.top() != '[') {
                return false;
            }
            if (str[i] == ')' && s.top() != '(') {
                return false;
            }
            s.pop();
        }
    }

    return (s.empty());
}

/**
 * @brief Program entry point: reads tokens from standard input and
 *        reports whether each one has balanced brackets.
 *
 * @param argc Argument count (unused).
 * @param argv Argument vector (unused).
 * @return @c 0 on successful completion.
 *
 * Input: a stream of whitespace-separated tokens read from standard
 * input until end-of-file or a read failure. For each token, prints
 * the token followed by `isValid`'s result (`1` for balanced, `0`
 * otherwise).
 */
int main(int argc, char* argv[]) {
    string input;

    while(cin >> input) {
        cout << input << "? " << isValid(input) << "\n";
    }
    return 0;
}