#include <iostream>
#include <map>
#include<limits>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>

using namespace std;

bool cmp(pair<char, int> &a, pair<char, int> &b) {
  if (a.second == b.second) {
    return a.first < b.first;
  } else {
    return a.second > b.second;
  }
}

int main(int argc, char* argv[]) {
  string line;
  map<char, int> leters;
  map<char, int>::const_iterator it1;
  vector<pair<char, int> > values;
  vector<pair<char, int> >::const_iterator it2;
  int n;
  char c;

  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for (int i = 0; i < n; i++) {
    getline(cin, line);
    for (int j = 0; j < line.size(); j++) {
      if (isalpha(line[j])) {
        it1 = leters.find(toupper(line[j]));
        if (it1 == leters.end()) {
          leters.insert(pair<char, int>(toupper(line[j]), 1));
        } else {
          leters[toupper(line[j])]++;
        }
      }
    }
  }
  for (it1 = leters.begin(); it1 != leters.end(); it1++) {
    values.push_back(*it1);
  }
  sort(values.begin(), values.end(), cmp);
  for (it2 = values.begin(); it2 != values.end(); it2++) {
    cout << (*it2).first << " " << (*it2).second << "\n";
  }
  return 0;
}
