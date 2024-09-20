#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

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

int main(int argc, char* argv[]) {
	string line;

	while(getline(cin, line)) {
		cout << "eval(" << line << ") = " << eval(line) << "\n";
	}
	return 0;
}