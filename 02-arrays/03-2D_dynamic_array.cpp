#include <iostream>
using namespace std;

int main(){
    int** arr = new int*[5];

    for (int i = 0; i < 5; i++) {
        arr[i] = new int[5]; // Dynamically allocate a 2D array of size 5x5
    }

    cout << "Enter 2D array elements (5x5):" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j]; // Input elements into the 2D array
        }
    }

    cout << "The array elements are:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " "; // Output the elements of the 2D array
        }
        cout << endl;
    }

    // Deallocate the dynamically allocated 2D array to free memory
    for (int i = 0; i < 5; i++) {
        delete[] arr[i]; // Deallocate each row of the 2D array
    }

    delete[] arr; // Deallocate the array of pointers
    
    return 0;
}
