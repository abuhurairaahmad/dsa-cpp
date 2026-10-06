#include <iostream>
using namespace std;

// Singly circular linked list node structure
struct Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a new node with data
    Node(int data) : data(data), next(nullptr) {}
};

// Singly circular linked list class
class CircularLinkedList {
private:
    Node* head; // Pointer to the head of the list

public:
    // Constructor to initialize an empty circular linked list
    CircularLinkedList() : head(nullptr) {}

    // Destructor to free the memory allocated for the circular linked list
    ~CircularLinkedList() {
        // I'll implement the destructor later
    }

    // Function to insert a new node at the beginning of the circular linked list
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            newNode->next = head;
            current->next = newNode;
            head = newNode; // Update head to the new node
        }
    }

    // Function to insert a new node at the end of the circular linked list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head; // Point back to head
        }
    }

    // Function to delete the first occurrence of a node with the given data
    void deleteNode(int data) {
        if (head == nullptr) return; // List is empty

        Node* current = head;
        Node* prev = nullptr;
        do {
            if (current->data == data) {
                if (prev == nullptr) { // Deleting the head node
                    Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                    delete current;
                } else {
                    prev->next = current->next;
                    delete current;
                }
                return;
            }
            prev = current;
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

    // Function to display the elements of the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "(back to head)" << endl; // Indicate the circular nature of the list
    }
};


int main(){
    CircularLinkedList list;
    int choice, data;

    do {
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete Node\n";
        cout << "4. Search Node\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at beginning: ";
                cin >> data;
                list.insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data to insert at end: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter data of the node to delete: ";
                cin >> data;
                list.deleteNode(data);
                break;
            case 4:
                cout << "Enter data to search for: ";
                cin >> data;
                if (list.search(data)) {
                    cout << "Node with data " << data << " found." << endl;
                } else {
                    cout << "Node with data " << data << " not found." << endl;
                }
                break;
            case 5:
                list.display();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}