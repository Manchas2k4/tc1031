#include <iostream>
#include "splay.h"

using namespace std;

int main(int argc, char* argv[]) {
    SplayTree<char> sTree;
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.add('D');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.add('I');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.add('N');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.add('O');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.add('S');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.add('A');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.add('U');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.add('R');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.remove('I');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.add('Z');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.remove('S');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.add('S');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.add('S');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.add('S');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.add('O');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    sTree.add('O');
    cout << sTree.preOrder();
    printf("\n---------------------------------------------------------------\n");

    return 0;
}
