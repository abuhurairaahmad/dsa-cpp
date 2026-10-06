#include <iostream>
using namespace std;

// Doubly circular linked list node structure
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor to initialize a new node with data
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

// Doubly circular linked list class
class DoublyCircularLinkedList {
private:
    Node* head; // Pointer to the head of the list

public:
    // Constructor to initialize an empty doubly circular linked list
    DoublyCircularLinkedList() : head(nullptr) {}

    ~DoublyCircularLinkedList() {
        // I'll implement the destructor later
    }

    // Function to insert a new node at the beginning of the doubly circular linked list
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Point to itself
            newNode->prev = head; // Point to itself
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert a new node at the end of the doubly circular linked list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Point to itself
            newNode->prev = head; // Point to itself
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }

    // Function to delete the first occurrence of a node with the given data
    void deleteNode(int data) {
        if (head == nullptr) return; // List is empty

        Node* current = head;
        do {
            if (current->data == data) {
                if (current->next == current) { // Only one node in the list
                    delete current;
                    head = nullptr;
                    return;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == head) {
                    head = current->next; // Update head if needed
                }
                delete current;
                return;
            }
            current = current->next;
        } while (current != head);
    }

    // Function to search for a node with the given data
    bool search(int data) {
        if (head == nullptr) return false; // List is empty

        Node* current = head;
        do {
            if (current->data == data) {
                return true; // Node found
            }
            current = current->next;
        } while (current != head);
        return false; // Node not found
    }

    // Function to display the elements of the doubly circular linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " <-> ";
            current = current->next;
        } while (current != head);
        cout << "(back to head)" << endl; // Indicate the circular nature of the list
    }
};

int main(){
    
    return 0;
}
