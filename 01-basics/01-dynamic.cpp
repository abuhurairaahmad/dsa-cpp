#include <iostream>
using namespace std;

int main()
{
    // int *arr = (int*)malloc(5 * sizeof(int));
    //  to allocate and initialize a block of memory to garbege value
    int *value1 = new int;

    // int *arr = (int*) calloc(5, sizeof(int));
    // to allocate and initialize a block of memory to zero
    int *value2 = new int();

    // Assiging the value including DMA
    int *value3 = new int(3);

    // Allocate a memory of five ints and intialize them
    int *arr = new int[10]{}; // {} initializes to zero, similar to = {0}
    int *arr1 = new int[10];       // {} initializes to zero, similar to = {0}

    cout << *value1 << endl;
    cout << *value2 << endl;
    cout << *value3 << endl;

    cout << "\n\n\n";

    cout << "Values of array:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    // Deallocate the memory
    delete[] arr;
    delete value1;
    delete value2;
    delete value3;

    /*
    In C, realloc is used to resize a previously allocated block of memory.
    In C++, you can use new[] to allocate an array of elements and delete[]
    to deallocate the entire array. Resizing is not directly supported by new and delete
    so you may need to manually allocate a new array, copy elements,
    and then deallocate the old array.
    */

    // int *resized_arr= (int*) realloc(arr, 10 * sizeof(int));
    int* resized_arr = new int[10];
    delete resized_arr;

    return 0;
}