#include <iostream>
#include <string>
#include <stack>
#include "exception.h"

using namespace std;

int main(int argc, char* argv[]) {
    string input;
    int result, left, right;
    stack<int> s;

    while (cin >> input) {
        if (input == "+" || input == "-" || input == "*" || input == "/") {
            if (s.empty()) {
                throw NoSuchElement();
            }
            right = s.top(); s.pop();
            if (s.empty()) {
                throw NoSuchElement();
            }
            left = s.top(); s.pop();
            if (input == "+") {
                result = left + right;
            } else if (input == "-") {
                result = left - right;
            } else if (input == "*") {
                result = left * right;
            } else {
                result = left / right;
            }
            s.push(result);
        } else {
            s.push(stoi(input));
        }
    }
    cout << "result = " << s.top() << "\n";
    return 0;
}
