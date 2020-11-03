/*
 * main.cpp
 *
 *  Created on: 3/11/2018
 *      Author: pperezm
 */
#include <iostream>
#include <cstring>
#include "ugraph.h"
#include "wgraph.h"

int main(int argc, char* argv[]) {
	/***********************************************************/
	/************************ UMatrixGraph *********************/
	/***********************************************************/
	UMatrixGraph<char> umg(5);
	
	umg.addEdge('A', 'B');
	umg.addEdge('B', 'C');
	umg.addEdge('B', 'D');
	umg.addEdge('C', 'E');
	umg.addEdge('D', 'C');
	umg.addEdge('E', 'D');
	
	std::cout << umg.toString();
	
	std::set<char> edges = umg.getConnectionFrom('B');
	std::set<char>::iterator itr;
	
	std::cout << "B ->\t";
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		std::cout << (*itr) << "\t";
	}
	std::cout << "\n\n";
	
	std::cout << "DFS(B) ->\t";
	edges = dfs('B', &umg);
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		std::cout << (*itr) << "\t";
	}
	std::cout << "\n\n";
	
	std::cout << "BFS(B) ->\t";
	edges = bfs('B', &umg);
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		std::cout << (*itr) << "\t";
	}
	std::cout << "\n\n";
	
	/***********************************************************/
	/************************ UListGraph ***********************/
	/***********************************************************/
	UListGraph<char> ulg(5);
	
	ulg.addEdge('A', 'B');
	ulg.addEdge('B', 'C');
	ulg.addEdge('B', 'D');
	ulg.addEdge('C', 'E');
	ulg.addEdge('D', 'C');
	ulg.addEdge('E', 'D');
	
	std::cout << ulg.toString();
	
	edges = ulg.getConnectionFrom('B');
	
	std::cout << "B ->\t";
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		std::cout << (*itr) << "\t";
	}
	std::cout << "\n\n";
	
	std::cout << "DFS(B) ->\t";
	edges = dfs('B', &ulg);
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		std::cout << (*itr) << "\t";
	}
	std::cout << "\n\n";
	
	std::cout << "BFS(B) ->\t";
	edges = bfs('B', &ulg);
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		std::cout << (*itr) << "\t";
	}
	std::cout << "\n\n";
	
	/***********************************************************/
	/************************ WMatrixGraph *********************/
	/***********************************************************/
	
	WMatrixGraph<char, int> wmg(5, 300);
	
	wmg.addEdge('A', 'B', 1);
	wmg.addEdge('B', 'C', 1);
	wmg.addEdge('B', 'D', 1);
	wmg.addEdge('C', 'E', 1);
	wmg.addEdge('D', 'C', 1);
	wmg.addEdge('E', 'D', 1);
	
	std::cout << wmg.toString();
	
	std::map<char, int> wedges = wmg.getConnectionFrom('B');
	std::map<char, int>::iterator witr;
	
	std::cout << "B ->\t";
	for (witr = wedges.begin(); witr != wedges.end(); witr++) {
		std::cout << "(" << witr->first << "," << witr->second << ")\t";
	}
	std::cout << "\n\n";
	
	std::cout << "DFS(B) ->\t";
	edges = dfs('B', &wmg);
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		std::cout << (*itr) << "\t";
	}
	std::cout << "\n\n";
	
	std::cout << "BFS(B) ->\t";
	edges = bfs('B', &wmg);
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		std::cout << (*itr) << "\t";
	}
	std::cout << "\n\n";
	
	/***********************************************************/
	/************************ WListGraph ***********************/
	/***********************************************************/
	WListGraph<char, int> wlg;
	
	wlg.addEdge('A', 'B', 1);
	wlg.addEdge('B', 'C', 1);
	wlg.addEdge('B', 'D', 1);
	wlg.addEdge('C', 'E', 1);
	wlg.addEdge('D', 'C', 1);
	wlg.addEdge('E', 'D', 1);
	
	std::cout << wlg.toString();
	
	wedges = wmg.getConnectionFrom('B');
	
	std::cout << "B ->\t";
	for (witr = wedges.begin(); witr != wedges.end(); witr++) {
		std::cout << "(" << witr->first << "," << witr->second << ")\t";
	}
	std::cout << "\n\n";
	
	std::cout << "DFS(B) ->\t";
	edges = dfs('B', &wlg);
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		std::cout << (*itr) << "\t";
	}
	std::cout << "\n\n";
	
	std::cout << "BFS(B) ->\t";
	edges = bfs('B', &wlg);
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		std::cout << (*itr) << "\t";
	}
	std::cout << "\n\n";
}
