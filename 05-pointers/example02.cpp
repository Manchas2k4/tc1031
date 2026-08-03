#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

#define SIZE 1000000000 //1e9

int main(int argc, char* argv[]) {
    int *array;

    array = new int[SIZE];
    // array = (int*) malloc(SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++) {
        *(array + i) = (i + 1);
    }

    for (int i = 0; i < 50; i++) {
        cout << (*array + i) << " ";
    }

    delete [] array;
    //free(array);

   /*
    for (int *ptr = array; ptr != (array + 50); ptr++) {
        cout << (*ptr) << " ";
    }
    */

   /*
   for (int *ptr = &array[0]; ptr != &array[50]; ptr++) {
        cout << (*ptr) << " ";
    }
    */
    return 0;
}