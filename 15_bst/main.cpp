#include <iostream>
#include "bst.h"

using namespace std;

int main(int argc, char* argv[]) {
  int adding[] = {50, 25, 75, 12, 40, 60, 80, 5, 18, 30, 45, 55, 80};
  int removing[] = {50, 75, 40, 5, 55};
  BST<int> bst;

  // The periferal

  for(int i = 0; i < 13; i++) {
    cout << "adding " << adding[i] << "\n";
    bst.add(adding[i]);
    cout << "inorder: " << bst.inOrder() << "\n";
    cout << "preorder: " << bst.preOrder() << "\n";
    cout << "postorder: " << bst.postOrder() << "\n";
    cout << "\n\n";
  }

  cout << "searching for 100: " << bst.find(100) << "\n";
  cout << "searching for 55: " << bst.find(55) << "\n";
  cout << "levels: " << bst.levels() << "\n\n\n";

  for(int i = 0; i < 5; i++) {
    cout << "removing " << removing[i] << "\n";
    bst.remove(removing[i]);
    cout << "inorder: " << bst.inOrder() << "\n";
    cout << "preorder: " << bst.preOrder() << "\n";
    cout << "postorder: " << bst.postOrder() << "\n";
    cout << "\n\n";
  }
  return 0;
}
