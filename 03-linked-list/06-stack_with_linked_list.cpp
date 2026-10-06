#include <iostream>
using namespace std;

class StackDS {
public:
    struct Node {
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head; 

public:
    StackDS() : head(nullptr) {}

    void push(int data) {
        Node* newNode = new Node(data);
        
        if (head == nullptr) {
            head = newNode;
            return;
        } 
        
        newNode->next = head;
        head = newNode;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return -1; // Return a sentinel value to indicate underflow
        }
        
        Node* temp = head;
        int poppedValue = temp->data;
        head = head->next;
        delete temp;
        return poppedValue;
    }

    ~StackDS() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main(){
    StackDS stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    
    return 0;
}
