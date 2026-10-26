#include <iostream>
#include "evaltree.h"

using namespace std;

int main(int argc, char* argv[]) {
	EvalTree tree("( 3 )");

	cout << "In Order = " << tree.inOrder() << "\n";
	cout << "Pre Order = " << tree.preOrder() << "\n";
	cout << "Post Order = " << tree.postOrder() << "\n";
	cout << "Per Level = " << tree.perLevel() << "\n";
	cout << "In Order = " << tree.inOrder() << "\n";
	cout << "Root depth = " << tree.levels() << "\n";
	cout << "Levels = " << tree.levels() << "\n";
 	cout << "Eval = " << tree.eval() << "\n";
	return 0;
}