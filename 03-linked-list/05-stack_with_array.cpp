#include <iostream>
using namespace std;

class Stack {
private:
    int* arr; // Pointer to the array that will hold the stack elements
    int top;  // Index of the top element in the stack
    int capacity; // Maximum number of elements the stack can hold

public:
    // Constructor to initialize the stack with a given capacity
    Stack(int capacity) : capacity(capacity), top(-1) {
        arr = new int[capacity]; // Dynamically allocate memory for the stack
    }

    void push(int element) {
        if (top == capacity - 1) {
            cout << "Stack Overflow! Cannot push " << element << endl;
            return;
        }
        arr[++top] = element; // Increment top and add the new element
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return -1; // Return a sentinel value to indicate underflow
        }
        return arr[top--]; // Return the top element and decrement top
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty! Cannot peek." << endl;
            return -1; // Return a sentinel value to indicate the stack is empty
        }
        return arr[top]; // Return the top element without removing it
    }

    int isEmpty() {
        return top == -1; // Return true if the stack is empty, false otherwise
    }

    ~Stack() {
        delete[] arr; // Free the dynamically allocated memory for the stack
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " "; // Display elements from top to bottom
        }
        cout << endl;
    }
};

int main(){

    Stack stack(5); // Create a stack with a capacity of 5

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    cout << "Popped element: " << stack.pop() << endl;
    stack.display();
    stack.push(40);
    stack.push(50);

    stack.display();
    return 0;
}
