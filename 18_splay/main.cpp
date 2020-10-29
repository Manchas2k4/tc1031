#include <iostream>
#include "splay.h"

using namespace std;

int main(int argc, char* argv[]) {
    SplayTree<char> sTree;
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.insert('D');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.insert('I');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.insert('N');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.insert('O');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.insert('S');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.insert('A');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.insert('U');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.insert('R');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.remove('I');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.insert('Z');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.remove('S');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.insert('S');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.insert('S');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.insert('S');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.insert('O');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.insert('O');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    return 0;
}
