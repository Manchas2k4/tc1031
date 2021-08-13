#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
  int n;
  std::string input;
  std::vector<std::string> words;

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> input;
    words.push_back(input);
  }

  for (int i = 0; i < words.size(); i++) {
    std::cout << words[i] << "\n";
  }

  return 0;
}
