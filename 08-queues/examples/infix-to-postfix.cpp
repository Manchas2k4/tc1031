#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <stack>

using namespace std;

queue<string> tokenize(string str) {
    int i = 0;
    int length = str.size();
    string aux;
    queue<string> result;

    while (i < length) {
        if (isdigit(str[i])) {
            aux.clear();

            do {
                aux += str[i];
                i++;
            } while (i < length && isdigit(str[i]));

            result.push(aux);
        }
        else if (isspace(str[i])) {
            i++;
        }
        else {
            aux.clear();
            aux += str[i];
            result.push(aux);
            i++;
        }
    }

    return result;
}

bool shouldPopOperator(const string &stackTop, const string &op) {
	return !((stackTop == string("+") || stackTop == string("-")) &&
			 (op == string("*")       || op == string("/")));
}

string convertInfixToPostfix(const string &expr) {
	queue<string> input;
	queue<string> result;
	stack<string> stack;

	input = tokenize(expr);
	while (!input.empty()) {
        string token = input.front(); input.pop();
        if (isdigit(token[0])) {
            result.push(token);
        } else if (token == "(") {
            stack.push(token);
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            while (!stack.empty() && stack.top() != "(") {
                if (shouldPopOperator(stack.top(), token)) {
                    result.push(stack.top());
                    stack.pop();
                } else {
                    break;
                }
            }
            stack.push(token);
        } else if (token == ")") {
            while (!stack.empty() && stack.top() != "(") {
                result.push(stack.top());
                stack.pop();
            }
            if (!stack.empty()) {
                stack.pop();
            }
        }
	}

    while (!stack.empty()) {
        result.push(stack.top());
        stack.pop();
    }

    string output;
    while (!result.empty()) {
        output += result.front();
        result.pop();

        if (!result.empty()) {
            output += " ";
        }
    }

	return output;
}

/*
"42"
"(1 + 2)"
"1 * 2 + 3"
"(1 + (2 + (3 + 4)))"
"1 + 2 * 3 + 4"
"(1 + 2) * (3 + 4)"
"1 + 2 - 3 * 4 / 5"
*/
int main(int argc, char* argv[]) {
    string expression;

    while (getline(cin, expression)) {
        cout << "Infex: " << expression 
            << " Postfix: " << convertInfixToPostfix(expression) << "\n";
    }
    return 0;
}