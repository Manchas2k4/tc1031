#include <iostream>
#include <fstream>
#include <vector>
#include "utility.h"

using namespace std;

int main(int argc, char* argv[]) {
	char name[100];
	ifstream input;
	ofstream output;
	vector<string> data;
	string line;

	cout << "input filename: ";
	cin >> name;

	input.open(name);
	if (input.is_open()) {
		while (getline(input, line)) {
			data.push_back(line);
		}
	}

	vector<string> aux;
	for (int i = 0; i < 20; i++) {
		aux = split(data[i], ' ');
		for (int j = 0; j < aux.size(); j++) {
			cout << aux[j] << " ";
		}
		cout << "\n";
	}

	cout << "output filename: ";
	cin >> name;

	output.open(name);
	if (output.is_open()) {
		for (int i = 0; i < data.size(); i++) {
				output << data[i] << "\n";
		}
	}

	return 0;
}
