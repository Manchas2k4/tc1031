#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
    int x = 10;
    int *ptr = &x;

    cout << "address of x = " << (&x) << " value of x = " << x << "\n";
    cout << "address stored in ptr = " << ptr << " value stored = " 
         << (*ptr) << "\n\n";

    cout << "incrementing by one to x via the variable x\n";
    x += 1;
    cout << "address of x = " << (&x) << " value of x = " << x << "\n";
    cout << "address stored in ptr = " << ptr << " value stored = " 
         << (*ptr) << "\n\n";

    cout << "incrementing by one to x via the pointer x\n";
    (*ptr) += 1;
    cout << "address of x = " << (&x) << " value of x = " << x << "\n";
    cout << "address stored in ptr = " << ptr << " value stored = " 
         << (*ptr) << "\n\n";

    return 0;
}
