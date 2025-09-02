#include <iostream>
#include <stack>
#include <string>
#include "exception.h"

using namespace std;

int isValid(const string &str) {
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

int main(int argc, char* argv[]) {
    string input;

    while(cin >> input) {
        cout << input << "? " << isValid(input) << "\n";
    }
    return 0;
}
