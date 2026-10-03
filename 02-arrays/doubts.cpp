#include <iostream>
using namespace std;

int main(){
    int* arr1d = new int[5]{1, 2, 3, 4, 5}; 
    int** arr2d = new int*[2];
    arr2d[0] = new int[3]{1, 2, 3};
    arr2d[1] = new int[2]{4, 5};

    cout << "Elements of the dynamically allocated 1D array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr1d[i] << " "; 
    }
    cout << endl;

    cout << "Elements of the dynamically allocated 2D array: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < (i == 0 ? 3 : 2); j++) {
            cout << arr2d[i][j] << " ";
        }
        cout << endl;
    }

    // Don't forget to free the allocated memory
    delete[] arr1d;
    delete[] arr2d[0];
    delete[] arr2d[1];
    delete[] arr2d;

    return 0;
}
