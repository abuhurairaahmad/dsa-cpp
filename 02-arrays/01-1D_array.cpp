#include <iostream>
using namespace std;

int main(){
    int arr[5] = {1, 2, 3, 4, 5}; // Declare and initialize an array of size 5
    cout << "Elements of the array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " "; // Access and print each element of the array
    }
    cout << endl;

    int sum = 0, average = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i]; // Calculate the sum of the array elements
    }
    average = sum / 5; // Calculate the average of the array elements
    
    cout << "Sum of the array elements: " << sum << endl;
    cout << "Average of the array elements: " << average << endl;

    return 0;
}
