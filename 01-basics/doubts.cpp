#include <iostream>
using namespace std;

int main(){
    int x = 10;
    int& lref = x; // lref is a reference to x
    int&& rref = 20; // rref is an rvalue reference to a
    // int* ptr = &&10; // ptr is a pointer to an rvalue

    cout << "Value of x: " << x << endl;
    cout << "Value of lref: " << lref << endl;
    cout << "Value of rref: " << rref << endl;
    // cout << "Value of ptr: " << *ptr << endl;
    return 0;
}
