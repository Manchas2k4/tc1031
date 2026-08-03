/**
 * @brief Implements Conway's Game of Life.
 *
 * This file contains the implementation of a cellular automaton simulation
 * based on Conway's Game of Life rules. The board is represented as a
 * one-dimensional vector where each element stores the state of a cell.
 *
 * The simulation initializes a random board configuration and generates
 * successive generations according to the number of alive neighboring cells.
 */

#include <iostream>
#include <vector>
#include "..\..\utils\generator.h"

using namespace std;

/**
 * @brief Number of rows in the game board.
 */
const int ROWS = 30;

/**
 * @brief Number of columns in the game board.
 */
const int COLS = 30;

/**
 * @brief Checks whether a board position is inside valid boundaries.
 *
 * @param row Row index to validate.
 * @param col Column index to validate.
 *
 * @return true if the position is inside the board, false otherwise.
 */
bool isValid(int row, int col) {
    return (row >= 0 && row < ROWS) && (col >= 0 && col < COLS);
}

/**
 * @brief Counts the alive neighbors of a specific cell.
 *
 * Evaluates the eight surrounding positions of the selected cell and counts
 * how many of them contain alive cells.
 *
 * @param matrix Board state represented as a one-dimensional vector.
 * @param row Row index of the cell to evaluate.
 * @param col Column index of the cell to evaluate.
 *
 * @return Number of alive neighboring cells.
 *
 * @note A cell is considered alive when its stored value is 1.
 */
int countNeighbors(const vector<char> &matrix, int row, int col) {
    int counter = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) {
                continue;
            }

            if (isValid(i, j) && (matrix[(i * COLS) + j] == 1)) {
                counter++;
            }
        }
    }
    return counter;
}

/**
 * @brief Generates the next state of the game board.
 *
 * Creates a new generation according to Conway's Game of Life rules:
 * - Alive cells remain alive with two or three alive neighbors.
 * - Dead cells become alive with exactly three alive neighbors.
 *
 * @param matrix Current board state.
 *
 * @return A vector containing the next generation of the board.
 *
 * @note The input matrix is not modified.
 */
vector<char> nextGeneration(const vector<char> &matrix) {
    vector<char> next(ROWS * COLS, 0);
    int count;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            count = countNeighbors(matrix, i, j);
            if (matrix[(i * COLS) + j] == 1) {
                if (count == 2 || count == 3) {
                    next[(i * COLS) + j] = 1;
                }
            } else {
                if (count == 3) {
                    next[(i * COLS) + j] = 1;
                }
            }
        }
    }
    return next;
}

/**
 * @brief Creates an initial random game board.
 *
 * Initializes a board with random cell states using the Generator utility.
 * Each cell receives a binary value representing whether it is alive or dead.
 *
 * @return A vector containing the initialized board state.
 *
 * @note The generated values depend on the behavior of Generator::randomNumber.
 */
vector<char> init() {
    vector<char> m(ROWS * COLS, 0);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            m[(i * COLS) + j] = Generator::randomNumber(1, 100) % 2;
        }
    }
    return m;
}

/**
 * @brief Displays the current state of the game board.
 *
 * Prints the current generation number and renders alive cells using '*'
 * and dead cells using '-'.
 *
 * @param matrix Current board state.
 * @param generation Generation number to display.
 */
void display(const vector<char> &matrix, int generation) {
    cout << "Generation #" << generation << ":\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << ((matrix[(i * COLS) + j])? "*" : "-");
        }
        cout << "\n";
    }
    cout << "\n";
}

/**
 * @brief Application entry point.
 *
 * Executes the Game of Life simulation for the number of generations
 * specified by the user.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 *
 * @return Application exit status.
 *
 * @note Command-line arguments are not used by the current implementation.
 */
int main(int argc, char* argv[]) {
    int number;

    cout << "Max. Generations? ";
    cin >> number;

    vector<char> matrix = init();
    for (int i = 0; i < number; i++) {
        display(matrix, i);
        
        vector<char> next = nextGeneration(matrix);

        matrix = next;
    }
    
    return 0;
}