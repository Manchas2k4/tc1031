#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int ROWS = 30;
const int COLS = 30;

bool isValid(int row, int col) {
    return (row >= 0 && row < ROWS) && (col >= 0 && col < COLS);
}

int countNeighbors(int* matrix, int row, int col) {
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

int* nextGeneration(int* matrix) {
    int* next = new int[ROWS * COLS];
    int count;

    memset(next, 0, ROWS * COLS * sizeof(int));
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

int* init() {
    int* m = new int[ROWS * COLS];

    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            m[(i * COLS) + j] = rand() % 2;
        }
    }
    return m;
}

void display(int* matrix, int generation) {
    cout << "Generation #" << generation << ":\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << ((matrix[(i * COLS) + j])? "*" : "-");
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(int argc, char* argv[]) {
    int number, *matrix, *next;

    cout << "Max. Generations? ";
    cin >> number;

    matrix = init();
    for (int i = 0; i < number; i++) {
        display(matrix, i);
        
        next = nextGeneration(matrix);

        delete [] matrix;
        matrix = next;
    }

    delete [] matrix;
    
    return 0;
}