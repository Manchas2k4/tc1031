/*
+ Cada muñeca se representa mediante un número entero positivo.
+ Una muñeca que contiene otras muñecas está representada por un número negativo 
(representando la apertura) seguido por el mismo número pero positivo (representando el cierre).
+ El número negativo debe aparecer primero en la secuencia antes que su correspondiente positivo.
+ Para ser una matrioshka válida, debe cumplirse que la suma de los tamaños de las muñecas 
contenidas directamente en una muñeca debe ser menor que el tamaño de la muñeca contenedora.

Por ejemplo, el caso -9 -7 -2 2 -3 -2 -1 1 2 3 7 9 es válido porque cada muñeca contiene otras 
muñecas cuya suma de tamaños es menor que el tamaño de la muñeca contenedora. En cambio, 
-9 -7 -2 2 -3 -1 -2 2 1 3 7 9 no es válido porque una muñeca más pequeña (2) aparece dentro de una 
más grande (1).

Para determinar si una secuencia describe una matrioshka válida, se debe:
+ Verificar que para cada muñeca contenedora, la suma de los tamaños de las muñecas contenidas es 
menor que su tamaño.
+ Asegurarse de que las muñecas están correctamente anidadas, es decir, los números negativos 
aparecen antes que sus correspondientes positivos.
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

bool checkInput(string line) {
    int number, total;
    stack<int> s, acum;
    stringstream input(line);
    
    while (input >> number) {
        if (number < 0) {
            if (!s.empty() && -number >= s.top()) {
                return false;
            }
            s.push(-number);
            acum.push(0);
        } else {
            if (s.empty() || s.top() != number) {
                return false;
            }

            total = acum.top(); acum.pop();
            s.pop();
            if (total >= number) {
                return false;
            }

            if (!acum.empty()) {
                acum.top() += number;
            }
        }
    }
    return s.empty();
}

int main(int argc, char* argv[]) {
    string line;

    while (getline(cin, line)) {
        if (checkInput(line)) {
            cout << ":-) Matrioshka!\n";
        } else {
            cout << ":-( Try again.\n";
        }
    }
    return 0;
}