/*
 * graph.h
 *
 *  Created on: 3/11/2018
 *      Author: pperezm
 */

#ifndef UGRAPH_H_
#define UGRAPH_H_

#include "exception.h"
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>

#include <iostream>

/***********************************************************/
/********************** UnweightedGraph ********************/
/***********************************************************/

template<class Vertex>
class UnweightedGraph {
public:
	virtual void addEdge(Vertex, Vertex) = 0;
	virtual bool containsVertex(Vertex) const = 0;
	virtual std::set<Vertex> getConnectionFrom(Vertex) const = 0;
	virtual std::string toString() const = 0;
};

/***********************************************************/
/************************ UMatrixGraph *********************/
/***********************************************************/
template<class Vertex>
class UMatrixGraph : public UnweightedGraph<Vertex>{
private: 
	int next, size;
	bool direction;
	std::vector<Vertex> vertexes;
	std::vector<std::vector<bool> > edges;
	
	int indexOf(Vertex v) const;
	
public:
	UMatrixGraph(int, bool dir = true);
	void addEdge(Vertex from, Vertex to);
	bool containsVertex(Vertex v) const;
	std::set<Vertex> getConnectionFrom(Vertex v) const;
	std::string toString() const;
};

template <class Vertex>
UMatrixGraph<Vertex>::UMatrixGraph(int max, bool dir) {
	size = max;
	if (size == 0) {
        throw RangeError();
	}
	
	next = 0;
	direction = dir;
	vertexes.resize(size);
	edges.resize(size);
	for (int i = 0; i < size; i++) {
		edges[i].resize(size, false);
		edges[i][i] = true;
	}
}

template <class Vertex>
int UMatrixGraph<Vertex>::indexOf(Vertex v) const {
	for (int i = 0; i < next; i++) {
		if (vertexes[i] == v) {
			return i;
		}
	}
	return -1;
}

template <class Vertex>
void UMatrixGraph<Vertex>::addEdge(Vertex from, Vertex to) {
	int fp = indexOf(from);
	if (fp == -1) {
		if (next == size) {
			throw OutOfMemory();
		}
		
		vertexes[next++] = from;
		fp = next - 1;
	}
	
	int tp = indexOf(to);
	if (tp == -1) {
		if (next == size) {
			throw OutOfMemory();
		}
		
		vertexes[next++] = to;
		tp = next - 1;
	}
	
	edges[fp][tp] = true;
	if (!direction) {
		edges[tp][fp] = true;
	}
}

template <class Vertex>
bool UMatrixGraph<Vertex>::containsVertex(Vertex v) const {
	return (indexOf(v) != -1);
}

template <class Vertex>
std::set<Vertex> UMatrixGraph<Vertex>::getConnectionFrom(Vertex v) const {
	int i = indexOf(v);
	if (i == -1) {
		throw NoSuchElement();
	}
	
	std::set<Vertex> result;
	for (int j = 0; j < next; j++) {
		if (i != j && edges[i][j]) {
			result.insert(vertexes[j]);
		}
	}
	return result;
}

template <class Vertex>
std::string UMatrixGraph<Vertex>::toString() const {
	std::stringstream aux;
	
	for (int i = 0; i < next; i++) {
		aux << vertexes[i] << "\t";
		for (int j = 0; j < next; j++) {
			aux << edges[i][j] << "\t";
		}
		aux << "\n";
	}
	aux << "\n";
	return aux.str();
}

/***********************************************************/
/************************ UListGraph ***********************/
/***********************************************************/

template<class Vertex>
class UListGraph : public UnweightedGraph<Vertex>{
private: 
	bool direction;
	std::set<Vertex> vertexes;
	std::map<Vertex, std::list<Vertex> > edges;
	
public:
	UListGraph(bool dir = true);
	void addEdge(Vertex from, Vertex to);
	bool containsVertex(Vertex v) const;
	std::set<Vertex> getConnectionFrom(Vertex v) const;
	std::string toString() const;
};

template <class Vertex>
UListGraph<Vertex>::UListGraph(bool dir) {
	direction = dir;
}

template <class Vertex>
void UListGraph<Vertex>::addEdge(Vertex from, Vertex to) {
	typename std::set<Vertex>::iterator it;
	
	it = vertexes.find(from);
	if (it == vertexes.end()) {
		vertexes.insert(from);
	}
	
	it = vertexes.find(to);
	if (it == vertexes.end()) {
		vertexes.insert(to);
	}
	
	edges[from].push_back(to);
	if (!direction) {
		edges[to].push_back(from);
	}
}

template <class Vertex>
bool UListGraph<Vertex>::containsVertex(Vertex v) const {
	return (vertexes.find(v) != vertexes.end());
}

template <class Vertex>
std::set<Vertex> UListGraph<Vertex>::getConnectionFrom(Vertex v) const {
	if (!containsVertex(v)) {
		throw NoSuchElement();
	}
	
	std::set<Vertex> result(edges.at(v).begin(), edges.at(v).end());
	return result;
}

template <class Vertex>
std::string UListGraph<Vertex>::toString() const {
	std::stringstream aux;
	
	typename std::set<Vertex>::iterator i;
	typename std::list<Vertex>::const_iterator j;
	
	for (i = vertexes.begin(); i != vertexes.end(); i++) {
		aux << (*i) << "\t";
		for (j = edges.at((*i)).begin(); j != edges.at((*i)).end(); j++) {
			aux << (*j) << "\t";
		}
		aux << "\n";
	}
	aux << "\n";
	return aux.str();
}

/***********************************************************/
/**************************** DFS **************************/
/***********************************************************/

template <class Vertex>
std::set<Vertex> dfs(const Vertex& start, const UnweightedGraph<Vertex>* graph) {
	std::set<Vertex> visited;
	std::stack<Vertex> xVisit;
	typename std::set<Vertex>::iterator itr;
	
	xVisit.push(start);
	while (!xVisit.empty()) {
		Vertex v = xVisit.top(); xVisit.pop();
		if (visited.find(v) == visited.end()) {
			visited.insert(v);
			std::set<Vertex> connected = graph->getConnectionFrom(v);
			for (itr = connected.begin(); itr != connected.end(); itr++) {
				xVisit.push( (*itr) );
			}
		}
	}
	return visited;
}

/***********************************************************/
/**************************** BFS **************************/
/***********************************************************/

template <class Vertex>
std::set<Vertex> bfs(const Vertex& start, const UnweightedGraph<Vertex>* graph) {
	std::set<Vertex> visited;
	std::queue<Vertex> xVisit;
	typename std::set<Vertex>::iterator itr;
	
	xVisit.push(start);
	while (!xVisit.empty()) {
		Vertex v = xVisit.front(); xVisit.pop();
		if (visited.find(v) == visited.end()) {
			visited.insert(v);
			std::set<Vertex> connected = graph->getConnectionFrom(v);
			for (itr = connected.begin(); itr != connected.end(); itr++) {
				xVisit.push( (*itr) );
			}
		}
	}
	return visited;
}

#endif
	
