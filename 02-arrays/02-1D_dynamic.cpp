#include <iostream>
using namespace std;

int main(){
    int* arr = new int[5]{1, 3, 5, 7, 9}; // Dynamically allocate an array of size 5 and initialize it

    cout << "Elements of the dynamically allocated array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " "; // Access and print each element of the dynamically allocated array
    }
    cout << endl;
    delete[] arr; // Deallocate the dynamically allocated array to free memory

    int* num = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Dynamically allocate an array of size 10 and initialize it
    int sum = 0, average = 0;
    for (int i = 0; i < 10; i++) {
        sum += num[i]; // Calculate the sum of the dynamically allocated array elements
    }
    average = sum / 10; 

    cout << "Sum of the dynamically allocated array elements: " << sum << endl;
    cout << "Average of the dynamically allocated array elements: " << average << endl;

    delete[] num; // Deallocate the dynamically allocated array to free memory

    return 0;
}
