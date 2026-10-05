// =================================================================
//
// File: maze.cpp
// Author: Pedro Pérez
// Description: This file builds a square maze of cells using a 
// 				randomized depth-first search
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

/**
 * @file maze.cpp
 * @brief Random maze generator and ASCII renderer.
 *
 * Builds a square maze of cells using a randomized depth-first search
 * (iterative "recursive backtracker") algorithm, where each cell is
 * encoded as a bitmask of its four walls, and prints the resulting
 * maze to standard output using simple ASCII art.
 */

#include <iostream>
#include <random>
#include <cmath>
#include <chrono>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>

using namespace std;

typedef unsigned char uchar;
typedef unsigned int uint;

/**
 * @def NORTH
 * @brief Bitmask used to clear a cell's north-wall bit via `&=`.
 *
 * Applying `cell &= NORTH` removes the north wall of @c cell while
 * leaving its other walls untouched.
 */
#define NORTH 		0x07

/**
 * @def EAST
 * @brief Bitmask used to clear a cell's east-wall bit via `&=`.
 */
#define EAST		0x0B

/**
 * @def SOUTH
 * @brief Bitmask used to clear a cell's south-wall bit via `&=`.
 */
#define SOUTH		0x0D

/**
 * @def WEST
 * @brief Bitmask used to clear a cell's west-wall bit via `&=`.
 */
#define WEST		0x0E

/**
 * @def ALL
 * @brief Initial state of a cell: all four walls present.
 *
 * Also used as the "unvisited" marker during generation: a cell whose
 * value is still @c ALL has not yet been carved into by generate_maze().
 */
#define ALL			0x0F

/**
 * @def HAS_SOUTH
 * @brief Bit tested to determine whether a cell still has its south wall.
 */
#define HAS_SOUTH	0x02

/**
 * @def HAS_EAST
 * @brief Bit tested to determine whether a cell still has its east wall.
 */
#define HAS_EAST	0x04

/**
 * @brief Global Mersenne Twister engine used for all random choices in
 *        this program (random starting cell and direction shuffling).
 *
 * @note Being a global, non-thread-safe generator, this is only safe to
 *       use from a single thread.
 */
random_device rd;
mt19937 gen(rd());

/**
 * @brief Determines whether a (row, column) pair lies inside a square
 *        grid of the given size.
 *
 * @param ren  Row index to validate.
 * @param col  Column index to validate.
 * @param size Side length of the square grid.
 * @return @c true if both @p ren and @p col fall within
 *         `[0, size)`, @c false otherwise.
 */
bool is_valid(int ren, int col, int size) {
	return (ren >= 0 && ren < size && col >= 0 && col < size);
}

/**
 * @brief Carves a random perfect maze into @p maze using an iterative
 *        randomized depth-first search (recursive backtracker).
 *
 * Each element of @p maze represents one grid cell as a 4-bit wall
 * mask (see @ref ALL, @ref NORTH, @ref EAST, @ref SOUTH, @ref WEST). A
 * cell still equal to @ref ALL is considered unvisited. Starting from a
 * random cell, the algorithm repeatedly tries to move to a random
 * unvisited neighbor, knocking down the wall between the current cell
 * and that neighbor; when no unvisited neighbor is available, it
 * backtracks using an explicit stack of previously visited cells until
 * either a cell with an unvisited neighbor is found again or the stack
 * is exhausted, at which point the maze is complete.
 *
 * @param maze Flat row-major representation of a square grid of side
 *             `sqrt(maze.size())`; modified in place so that, on
 *             return, it encodes a fully connected (perfect) maze.
 * @pre `maze.size()` must be a perfect square, and every element must
 *      be initialized to @ref ALL.
 * @post Every cell is reachable from every other cell, and no cycles
 *       exist between cells (a perfect maze).
 * @note The algorithm's correctness depends on @ref ALL being used
 *       exclusively as the "unvisited" sentinel value; this requires
 *       that @p maze contain no cells pre-set to any other value.
 */
void generate_maze(vector<uchar> &maze) {
	bool finished, found;
	int ren, col, newRen, newCol, size = sqrt(maze.size());
	uniform_int_distribution<int> cells(0, size - 1);
	uchar movements[] = {NORTH, EAST, SOUTH, WEST};
	vector<pair<int, int> > coords = {{-1, 0}, {0, +1}, {+1, 0}, {0, -1}};
	vector<int> indexes = {0, 1, 2, 3};
	stack<pair<int, int> > theStack;

	ren = cells(gen);
	col = cells(gen);
	finished = false;
	while (!finished) {
		found = false;
		shuffle(indexes.begin(), indexes.end(), gen);
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

/**
 * @brief Prints a textual representation of @p maze to standard output.
 *
 * Renders the maze as ASCII art: a top border of underscores, then one
 * output line per grid row, where each cell contributes an underscore
 * if its south wall is present (@ref HAS_SOUTH) and a vertical bar if
 * its east wall is present (@ref HAS_EAST), with a leading vertical bar
 * marking the west border of each row.
 *
 * @param maze Flat row-major representation of a square grid of side
 *             `sqrt(maze.size())`, as produced by generate_maze().
 */
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

/**
 * @brief Program entry point: reads the maze size, generates a random
 *        maze of that size, and prints it.
 *
 * @param argc Argument count (unused).
 * @param argv Argument vector (unused).
 * @return @c 0 on successful completion.
 *
 * Input: a single unsigned integer @c size read from standard input,
 * giving the side length of the (square) maze to generate.
 */
int main(int argc, char* argv[]) {
	uint size;
	vector<uchar> maze;

	cin >> size;

	maze.resize(size * size, ALL);

	generate_maze(maze);

	display_maze(maze);

	return 0;
}