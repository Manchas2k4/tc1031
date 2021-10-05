#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(const string &str) {
    stack<char> s;
    queue<char> q;

    for (int i = 0; i < str.size(); i++) {
        if (!isblank(str[i])) {
            s.push(str[i]);
            q.push(str[i]);
        }
    }
    while (!s.empty() && !q.empty()) {
        if (s.top() != q.front()) {
            return false;
        }
        s.pop();
        q.pop();
    }
    return true;
}

int main(int argc, char* argv[]) {
    string s;

    getline(cin, s);
    cout << "isPalindrome? " << isPalindrome(s) << "\n";
    return 0;
}
