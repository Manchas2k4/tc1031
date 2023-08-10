#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  int n;
  string input;
  vector<string> words;
  vector<int> integers;
  vector<vector<int> > matrix;
  

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input;
    words.push_back(input);
  }

  for (int i = 0; i < words.size(); i++) {
    cout << words[i] << "\n";
  }
  
  cout << words[n + 10] << "\n"; 

  return 0;
}
