#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    
}

int main(){
    int a = 2, b = 3;

    swap(a, b);

    cout << "The value of a is:" << a << endl;
    cout << "The value of b is:" << b << endl;

    return 0;
}
