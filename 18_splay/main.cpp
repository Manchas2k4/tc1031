#include <iostream>
#include "splay.h"

using namespace std;

int main(int argc, char* argv[]) {
  int adding[] = {50, 25, 75, 12, 40, 60, 80, 5, 18, 30, 45, 55, 80};
  int removing[] = {50, 75, 40, 5, 55};
  SplayTree<int> st;

  // The periferal

  for(int i = 0; i < 13; i++) {
    cout << "adding " << adding[i] << "\n";
    st.add(adding[i]);
    cout << "inorder: " << st.inOrder() << "\n";
    cout << "preorder: " << st.preOrder() << "\n";
    cout << "postorder: " << st.postOrder() << "\n";
    cout << "\n\n";
  }

  for (int i = 0; i < 3; i++) {
    cout << "searching for 55: " << st.find(25) << "\n";
    cout << "preorder: " << st.preOrder() << "\n";
  }

  /*
  for(int i = 0; i < 5; i++) {
    cout << "removing " << removing[i] << "\n";
    bst.remove(removing[i]);
    cout << "inorder: " << bst.inOrder() << "\n";
    cout << "preorder: " << bst.preOrder() << "\n";
    cout << "postorder: " << bst.postOrder() << "\n";
    cout << "\n\n";
  }
  */
  return 0;
}
