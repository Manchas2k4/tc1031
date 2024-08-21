#include <iostream>
#include <iomanip>

using namespace std;

#define SIZE 1000000000 //1e9

int main(int argc, char* argv[]) {
    int *array = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        array[i] = i;
    }

    for (int i = 0; i < 100; i++) {
        cout << i << " ";
    }
    cout << "\n";
    delete [] array;
    return 0;
}