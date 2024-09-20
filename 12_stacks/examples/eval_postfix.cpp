#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

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

int main(int argc, char* argv[]) {
	string line;

	while(getline(cin, line)) {
		cout << "eval(" << line << ") = " << eval(line) << "\n";
	}
	return 0;
}