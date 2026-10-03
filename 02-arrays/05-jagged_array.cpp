#include <iostream>
using namespace std;

int main(){
    int* jaggedArray[3]; // Declare an array of 3 pointers (jagged array)
    
    jaggedArray[0] = new int[2]{1, 2}; // First row with 2 elements
    jaggedArray[1] = new int[3]{3, 4, 5}; // Second row with 3 elements
    jaggedArray[2] = new int[4]{6, 7, 8, 9}; // Third row with 4 elements

    // print the elements of the jagged array
    cout << "Elements of the jagged array: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < (i == 0 ? 2 : (i == 1 ? 3 : 4)); j++) {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // Free the dynamically allocated memory of the rows
    for (int i = 0; i < 3; i++) {
        delete[] jaggedArray[i]; // Free each row
    }
    
    return 0;
}
