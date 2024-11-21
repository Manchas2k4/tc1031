#include <iostream>
#include <algorithm>

using namespace std;

class WeightQuickUnion {
private:
	uint *ids;
	uint *szs;
	uint size;

	uint root(uint p);

public:
	WeightQuickUnion(uint);
	~WeightQuickUnion();
	bool find(uint, uint);
	void join(uint, uint);
	int getMaxSize() const;
};

WeightQuickUnion::WeightQuickUnion(uint n) {
	size = n;
	ids = new uint[size];
	szs = new uint[size];
	for (uint i = 0; i < size; i++) {
		ids[i] = i;
		szs[i] = 1;
	}
}

WeightQuickUnion::~WeightQuickUnion() {
	delete [] ids;
	ids = NULL;
	delete [] szs;
	szs = NULL;
	size = 0;
}

uint WeightQuickUnion::root(uint p) {
	while (p != ids[p]) {
		ids[p] = ids[ids[p]];
		p = ids[p];
	}
	return p;
}

bool WeightQuickUnion::find(uint p, uint q) {
	return root(p) == root(q);
}

void WeightQuickUnion::join(uint p, uint q) {
	uint pid, qid;

	pid = root(p);
	qid = root(q);
	if (szs[pid] < szs[qid]) {
		ids[pid] = qid;
		szs[qid] += szs[pid];
	} else {
		ids[qid] = pid;
		szs[pid] += szs[qid];
	}
}

int WeightQuickUnion::getMaxSize() const {
	uint result = 0;
	for (int i = 0; i < size; i++) {
		result = max(result, szs[i]);
	}
	return result;
}

int main(int argc, char* argv[]) {
	int cases, m, n, p, q;
	
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> n >> m;
		
		WeightQuickUnion set(n + 1);
		for (int i = 0; i < m; i++) {
			cin >> p >> q;
			if (!set.find(p, q)) {
				set.join(p, q);
			}
		}
		
		cout << set.getMaxSize() << "\n";
	}
	return 0;
}
