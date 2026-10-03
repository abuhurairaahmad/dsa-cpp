#include <iostream>
using namespace std;

class Array {
private:
    int* data;  // Pointer to dynamically allocated array
    int size;   // Size of the array
    int capacity; // Capacity of the array

public:
    Array(int capacity): capacity(capacity), size(0) {
        data = new int[capacity]; // Dynamically allocate memory for the array
    }

    ~Array() {
        delete[] data; // Free the dynamically allocated memory
    }

    // Fuction to insert element at the beginning 
    void insertAtBeginning(int element) {
        if (size < capacity) {
            for (int i = size; i > 0; --i) {
                data[i] = data[i - 1];
            }
            data[0] = element;
            size++;
        } else {
            cout << "Cannot insert element in the beginnig -- Array is full" << endl;
        }
    }

    // Function to insert element at the end
    void insertAtEnd(int element) {
        if (size < capacity) {
            data[size++] = element;
        } else {
            cout << "The Array is full - Cannot instert element at the end" << endl;
        }
    }

    // Function to insert element at a specific index
    void insertAt(int index, int element) {
        if (index >= 0 && index <= size && size < capacity) {
            for (int i = size; i > index; --i) {
                data[i] = data[i - 1];
            }
            data[index] = element;
            size++;
        } else {
            cout << "Invalid index or the array is full - Cannot insert the element" << endl;
        }
    }

    // Function to delete element from the beginning
    void removeFromBeginning() {
        
        if (size > 0) {
            for (int i = 0; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
            size--;
        } else {
            cout << "Array is empty. Cannot remove the element from start" << endl;
        }
    }

    // Function to delete the element at the end
    void removeFromEnd() {
        if (size > 0) {
            size--;
        } else {
            cout << "Array is empty. Cannot remove the element from end" << endl;
        }
    }

    // Function to delete the element at a specific index
    void removeAt(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            size--;
        } else {
            cout << "Invalid index - Cannot remove the element" << endl;
        }
    }

    // Function to access element at a given index
    int get(int index) {
        if (index >= 0 && index < size) {
            return data[index];
        } else {
            cout << "Invalid index. Cannot access the array" << endl;
            return -1;  // Return -1 if the index out of bounds
        }
    }

    // Function to display elements of the array
    void display() {
        cout << "Array Elements: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    int capacity;
    cout << "Enter the capacity of the array: ";
    cin >> capacity;

    Array arr(capacity); // Create an instance of the Array class with the specified capacity

    int choice, element, index;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Index\n";
        cout << "4. Remove from Beginning\n";
        cout << "5. Remove from End\n";
        cout << "6. Remove from Index\n";
        cout << "7. Access Element at Index\n";
        cout << "8. Display Array Elements\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert at beginning: ";
                cin >> element;
                arr.insertAtBeginning(element);
                break;
            case 2:
                cout << "Enter element to insert at end: ";
                cin >> element;
                arr.insertAtEnd(element);
                break;
            case 3:
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter index to insert at: ";
                cin >> index;
                arr.insertAt(index, element);
                break;
            case 4:
                arr.removeFromBeginning();
                break;
            case 5:
                arr.removeFromEnd();
                break;
            case 6:
                cout << "Enter index to remove: ";
                cin >> index;
                arr.removeAt(index);
                break;
            case 7: {
                cout << "Enter index to access: ";
                cin >> index;
                int value = arr.get(index);
                if (value != -1) {
                    cout << "Element at index " << index << ": " << value << endl;
                }
                break;
            }
            case 8:
                arr.display();
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
