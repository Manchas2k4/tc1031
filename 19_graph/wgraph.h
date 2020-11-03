/*
 * graph.h
 *
 *  Created on: 3/11/2018
 *      Author: pperezm
 */

#ifndef WGRAPH_H_
#define WGRAPH_H_

#include "exception.h"
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>

/***********************************************************/
/*********************** WeightedGraph *********************/
/***********************************************************/

template<class Vertex, class Edge>
class WeightedGraph {
public:
	virtual void addEdge(Vertex, Vertex, Edge) = 0;
	virtual bool containsVertex(Vertex) const = 0;
	virtual std::map<Vertex, Edge> getConnectionFrom(Vertex) const = 0;
	virtual std::string toString() const = 0;
};

/***********************************************************/
/************************ WMatrixGraph *********************/
/***********************************************************/
template<class Vertex, class Edge>
class WMatrixGraph : public WeightedGraph<Vertex, Edge>{
private: 
	int next, size;
	bool direction;
	Edge infinite;
	std::vector<Vertex> vertexes;
	std::vector<std::vector<Edge> > edges;
	
	int indexOf(Vertex v) const;
	
public:
	WMatrixGraph(int, Edge, bool dir = true);
	void addEdge(Vertex from, Vertex to, Edge cost);
	bool containsVertex(Vertex v) const;
	std::map<Vertex, Edge> getConnectionFrom(Vertex v) const;
	std::string toString() const;
};

template <class Vertex, class Edge>
WMatrixGraph<Vertex, Edge>::WMatrixGraph(int max, Edge inf, bool dir) {
	size = max;
	if (size == 0) {
        throw RangeError();
	}
	
	next = 0;
	infinite = inf;
	direction = dir;
	vertexes.resize(size);
	edges.resize(size);
	for (int i = 0; i < size; i++) {
		edges[i].resize(size, infinite);
		edges[i][i] = 0;
	}
}

template <class Vertex, class Edge>
int WMatrixGraph<Vertex, Edge>::indexOf(Vertex v) const {
	for (int i = 0; i < next; i++) {
		if (vertexes[i] == v) {
			return i;
		}
	}
	return -1;
}

template <class Vertex, class Edge>
void WMatrixGraph<Vertex, Edge>::addEdge(Vertex from, Vertex to, Edge cost) {
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
	
	edges[fp][tp] = cost;
	if (!direction) {
		edges[tp][fp] = cost;
	}
}

template <class Vertex, class Edge>
bool WMatrixGraph<Vertex, Edge>::containsVertex(Vertex v) const {
	return (indexOf(v) != -1);
}

template <class Vertex, class Edge>
std::map<Vertex, Edge> WMatrixGraph<Vertex, Edge>::getConnectionFrom(Vertex v) const {
	int i = indexOf(v);
	if (i == -1) {
		throw NoSuchElement();
	}
	
	std::map<Vertex, Edge> result;
	for (int j = 0; j < next; j++) {
		if (i != j && edges[i][j] != infinite) {
			result[vertexes[j]] = edges[i][j];
		}
	}
	return result;
}

template <class Vertex, class Edge>
std::string WMatrixGraph<Vertex, Edge>::toString() const {
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
/************************ WListGraph ***********************/
/***********************************************************/

template<class Vertex, class Edge>
class WListGraph : public WeightedGraph<Vertex, Edge>{
private: 
	bool direction;
	std::set<Vertex> vertexes;
	std::map<Vertex, std::map<Vertex, Edge> > edges;
	
public:
	WListGraph(bool dir = true);
	void addEdge(Vertex, Vertex, Edge);
	bool containsVertex(Vertex) const;
	std::map<Vertex, Edge> getConnectionFrom(Vertex) const;
	std::string toString() const;
};

template <class Vertex, class Edge>
WListGraph<Vertex, Edge>::WListGraph(bool dir) {
	direction = dir;
}

template <class Vertex, class Edge>
void WListGraph<Vertex, Edge>::addEdge(Vertex from, Vertex to, Edge cost) {
	typename std::set<Vertex>::iterator it;
	
	it = vertexes.find(from);
	if (it == vertexes.end()) {
		vertexes.insert(from);
	}
	
	it = vertexes.find(to);
	if (it == vertexes.end()) {
		vertexes.insert(to);
	}
	
	edges[from].insert(std::pair<Vertex, Edge>(to, cost));
	if (!direction) {
		edges[to].insert(std::pair<Vertex, Edge>(from, cost));
	}
}

template <class Vertex, class Edge>
bool WListGraph<Vertex, Edge>::containsVertex(Vertex v) const {
	return (vertexes.find(v) != vertexes.end());
}

template <class Vertex, class Edge>
std::map<Vertex, Edge> WListGraph<Vertex, Edge>::getConnectionFrom(Vertex v) const {
	if (!containsVertex(v)) {
		throw NoSuchElement();
	}
	
	std::map<Vertex, Edge> result(edges.at(v).begin(), edges.at(v).end());
	return result;
}

template <class Vertex, class Edge>
std::string WListGraph<Vertex, Edge>::toString() const {
	std::stringstream aux;
	
	typename std::set<Vertex>::iterator i;
	typename std::map<Vertex, Edge>::const_iterator j;
	
	/*
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
*/
	
	for (i = vertexes.begin(); i != vertexes.end(); i++) {
		aux << (*i) << "\t";
		for (j = edges.at((*i)).begin(); j != edges.at((*i)).end(); j++) {
			aux << "(" << j->first << "," << j->second << ")\t";
		}
		aux << "\n";
	}
	aux << "\n";
	return aux.str();
}

/***********************************************************/
/**************************** DFS **************************/
/***********************************************************/

template <class Vertex, class Edge>
std::set<Vertex> dfs(const Vertex& start, const WeightedGraph<Vertex, Edge>* graph) {
	std::set<Vertex> visited;
	std::stack<Vertex> xVisit;
	typename std::map<Vertex, Edge>::iterator itr;
	
	xVisit.push(start);
	while (!xVisit.empty()) {
		Vertex v = xVisit.top(); xVisit.pop();
		if (visited.find(v) == visited.end()) {
			visited.insert(v);
			std::map<Vertex, Edge> connected = graph->getConnectionFrom(v);
			for (itr = connected.begin(); itr != connected.end(); itr++) {
				xVisit.push( itr->first );
			}
		}
	}
	return visited;
}

/***********************************************************/
/**************************** BFS **************************/
/***********************************************************/

template <class Vertex, class Edge>
std::set<Vertex> bfs(const Vertex& start, const WeightedGraph<Vertex, Edge>* graph) {
	std::set<Vertex> visited;
	std::queue<Vertex> xVisit;
	typename std::map<Vertex, Edge>::iterator itr;
	
	xVisit.push(start);
	while (!xVisit.empty()) {
		Vertex v = xVisit.front(); xVisit.pop();
		if (visited.find(v) == visited.end()) {
			visited.insert(v);
			std::map<Vertex, Edge> connected = graph->getConnectionFrom(v);
			for (itr = connected.begin(); itr != connected.end(); itr++) {
				xVisit.push( itr->first );
			}
		}
	}
	return visited;
}

#endif
	
