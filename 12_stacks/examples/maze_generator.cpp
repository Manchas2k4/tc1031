#include <iostream>
#include <iomanip>
#include <random>
#include <tuple>
#include <cmath>
#include <chrono>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
using namespace std;

typedef unsigned char uchar;
typedef unsigned int uint;

#define NORTH 		0x07
#define EAST		0x0B
#define SOUTH		0x0D
#define WEST		0x0E
#define ALL			0x0F
#define HAS_SOUTH	0x02
#define HAS_EAST	0x04

bool is_valid(int ren, int col, int size) {
	return (ren >= 0 && ren < size && col >= 0 && col < size);
}

void generate_maze(vector<uchar> &maze) {
	/*
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	*/
	bool finished, found;
	int ren, col, newRen, newCol, size = sqrt(maze.size());
	default_random_engine generator(12345);
    uniform_int_distribution<int> cells(0, size - 1);
	uchar movements[] = {NORTH, EAST, SOUTH, WEST};
	vector<pair<int, int> > coords = {{-1, 0}, {0, +1}, {+1, 0}, {0, -1}};
	vector<int> indexes = {0, 1, 2, 3};
	stack<pair<int, int> > theStack;

	ren = cells(generator);
	col = cells(generator);
	finished = false;
	while (!finished) {
		found = false;
		random_shuffle(indexes.begin(), indexes.end());
		for(int i : indexes) {
			newRen = ren + coords[i].first;
			newCol = col + coords[i].second;
			if (!is_valid(newRen, newCol, size)) {
				continue;
			}

			if (maze[(newRen * size) + newCol] == ALL) {
				switch(movements[i]) {
					case NORTH: 
						maze[(ren * size) + col] &= NORTH;
						maze[(newRen * size) + newCol] &= SOUTH;
						break;
					case EAST: 
						maze[(ren * size) + col] &= EAST;
						maze[(newRen * size) + newCol] &= WEST;
						break;
					case SOUTH: 
						maze[(ren * size) + col] &= SOUTH;
						maze[(newRen * size) + newCol] &= NORTH;
						break;
					case WEST: 
						maze[(ren * size) + col] &= WEST;
						maze[(newRen * size) + newCol] &= EAST;
						break;
				}
				found = true;
				theStack.push({ren, col});
				ren = newRen;
				col = newCol;
				break;
			}
		}

		if (!found) {
			if (theStack.empty()) {
				finished = true;
				continue;
			}

			pair<int, int> top = theStack.top(); theStack.pop();
			ren = top.first;
			col = top.second;
		}
	}
}

void display_maze(const vector<uchar> &maze) {
	int size = sqrt(maze.size());
	for (int i = 0; i < size; i++) {
		cout << " _";
	}
	cout << "\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j == 0) {
				cout << "|";
			}

			if (maze[(i * size) + j] & HAS_SOUTH) {
				cout << "_";
			} else {
				cout << " ";
			}

			if (maze[(i * size) + j] & HAS_EAST) {
				cout << "|";
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}
}

int main(int argc, char* argv[]) {
	uint size;
	vector<uchar> maze;

	cin >> size;
	
	maze.resize(size * size, ALL);
	
	generate_maze(maze);
	
	display_maze(maze);

	return 0;
}