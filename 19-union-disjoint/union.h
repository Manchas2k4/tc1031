#ifndef UNION_H
#define UNION_H

#include <iostream>
#include "exception.h"

typedef unsigned int uint;

class QuickFind {
private:
	uint *ids;
	uint size;

public:
	QuickFind(uint);
	~QuickFind();
	bool find(uint, uint);
	void join(uint, uint);
};

QuickFind::QuickFind(uint n) {
	ids = new uint[n];
	size = n;
	for (uint i = 0; i < n; i++) {
		ids[i] = i;
	}
}

QuickFind::~QuickFind() {
	delete [] ids;
	ids = NULL;
	size = 0;
}

bool QuickFind::find(uint p, uint q) {
	if (p >= size) {
		throw NoSuchElement();
	}
	if (q >= size) {
		throw NoSuchElement();
	}

	return ids[p] == ids[q];
}

void QuickFind::join(uint p, uint q) {
	uint pid;

	if (p >= size) {
		throw NoSuchElement();
	}
	if (q >= size) {
		throw NoSuchElement();
	}

	pid = ids[p];
	for (uint i = 0; i < size; i++) {
		if (ids[i] == pid) {
			ids[i] = ids[q];
		}
	}
}

class QuickUnion {
private:
	uint *ids;
	uint size;

	uint root(uint p);

public:
	QuickUnion(uint);
	~QuickUnion();
	bool find(uint, uint);
	void join(uint, uint);
};

QuickUnion::QuickUnion(uint n) {
	size = n;
	ids = new uint[size];
	for (uint i = 0; i < size; i++) {
		ids[i] = i;
	}
}

QuickUnion::~QuickUnion() {
	delete [] ids;
	ids = NULL;
	size = 0;
}

uint QuickUnion::root(uint p) {
	while (p != ids[p]) {
		p = ids[p];
	}
	return p;
}

bool QuickUnion::find(uint p, uint q) {
	if (p >= size) {
		throw NoSuchElement();
	}
	if (q >= size) {
		throw NoSuchElement();
	}

	return root(p) == root(q);
}

void QuickUnion::join(uint p, uint q) {
	uint pid, qid;

	if (p >= size) {
		throw NoSuchElement();
	}
	if (q >= size) {
		throw NoSuchElement();
	}

	pid = root(p);
	qid = root(q);
	ids[pid] = qid;
}

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
	if (p >= size) {
		throw NoSuchElement();
	}
	if (q >= size) {
		throw NoSuchElement();
	}

	return root(p) == root(q);
}

void WeightQuickUnion::join(uint p, uint q) {
	uint pid, qid;

	if (p >= size) {
		throw NoSuchElement();
	}
	if (q >= size) {
		throw NoSuchElement();
	}

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

#endif /* UNION_H */
