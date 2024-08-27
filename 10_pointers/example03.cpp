#include <iostream>
#include <iomanip>

using namespace std;

void swap(int *array, int i, int j) {
    int aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}

void bubbleSort(int *arr, int size, bool (*fn) (int, int)) {
	for(int i = size - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if( fn(arr[j], arr[j + 1]) ){
				swap(arr, j, j + 1);
			}
		}
	}
}

bool ascendente(int a, int b) {
    return a > b;
}

bool descendente(int a, int b) {
    return a < b;
}

int main(int argc, char* argv[]) {
    int arr1[] = {31, 18, 4, 8, 2};

    bubbleSort(arr1, 5, ascendente);
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    } 
    cout << "\n";

    bubbleSort(arr1, 5, descendente);
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    } 
    cout << "\n";

    return 0;
}

