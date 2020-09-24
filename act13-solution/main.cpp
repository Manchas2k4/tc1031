#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utility.h"
#include "record.h"
#include "merge.h"
#include "search.h"

using namespace std;

int main(int argc, char* argv[]) {
	char name[100];
	ifstream input;
	ofstream output;
	vector<string> aux;
	vector<Record> records;
	string line, msg;
	string month, day;
	Record startDate, endDate;

	cout << "input filename: ";
	cin >> name;

	input.open(name);
	if (input.is_open()) {
		while (getline(input, line)) {
			aux = split(line, ' ');
			msg = "";
			for (int i = 4; i < aux.size(); i++) {
				msg = msg + " " + aux[i];
			}
			records.push_back(Record(aux[0], aux[1], aux[2], aux[3], msg));
		}
	}
	input.close();

	mergeSort(records);

	do {
		cout << "Start date \nmonth: ";
		cin >> month;
		cout << "day: ";
		cin >> day;
		startDate = Record(month, day);

		cout << "End date \nmonth: ";
		cin >> month;
		cout << "day: ";
		cin >> day;
		endDate = Record(month, day);

		if (startDate > endDate) {
			cout << "The start date is after the end date\n";
		}
	} while (startDate > endDate);


	int start = alternativeBinarySearch(records, startDate);
	if (start == -1) {
		start = 0;
	} else {
		while (start >= 0 && records[start] == startDate) {
			start--;
		}
	}
	cout << "start = " << start << "\n";
	cout << records[start].toString() << "\n";

	int end = alternativeBinarySearch(records, endDate);
	if (end == -1) {
		end = records.size();
	} else {
		while (end < records.size() && records[end] == endDate) {
			end++;
		}
	}
	cout << "end = " << end << "\n";
	cout << records[end].toString() << "\n";

	cout << "output filename: ";
	cin >> name;

	output.open(name);
	if (output.is_open()) {
		for (int i = start + 1; i < end; i++) {
			cout << records[i].toString() << "\n";
			output << records[i].toString() << "\n";
		}
	}
	output.close();

	return 0;
}
