#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Drug {
public:
	int id, period, next;
	string name;
};

class Comparison {
public:
  bool operator() (const Drug &left, const Drug &right) const {
    if (left.next == right.next) {
    	return (left.id > right.id);
    } else {
    	return (left.next > right.next);
    }
  }
};

int main(int argc, char* argv[]) {
	priority_queue<Drug, vector<Drug>, Comparison> q;
	string name;
	int cases, n, k, period;
	
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> n >> k;
		
		for (int j = 0; j < n; j++) {
			cin >> name >> period;
			
			Drug d;
			d.id = j;
			d.name = name;
			d.period = period;
			d.next = period;
			
			q.push(d);
		}
		
		for (int j = 0; j < k; j++) {
			Drug d1 = q.top(); q.pop();
			cout << d1.next << " " << d1.name << "\n";
			
			Drug d2;
			d2.id = d1.id;
			d2.name = d1.name;
			d2.period = d1.period;
			d2.next = d1.next + d1.period;
			q.push(d2);
		}
	}
	
	return 0;
}
