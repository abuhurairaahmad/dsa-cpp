#include <iostream>
using namespace std;

// Singly linked list node structure
struct Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a new node with data
    Node(int value) : data(value), next(nullptr) {}
};

// Singly linked list class
class LinkedList {

public:
    Node* head; // Pointer to the head of the list

    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Destructor to free the memory allocated for the linked list
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current; // Free the current node
            current = nextNode; // Move to the next node
        }
    }

    // Function to insert a new node at the beginning of the linked list
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data); // Create a new node with the given data
        newNode->next = head;           // Point the new node's next to the current head
        head = newNode;                 // Update the head to point to the new node
    }
    
    // Function to insert a new node at the end of the linked list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Function to insert a new node after a given node
    void insertAfter(Node* prevNode, int data) {
        if (prevNode == nullptr) {
            cout << "The given previous node cannot be null." << endl;
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    // Function to delete the first occurrence of a node with the given data
    void deleteNode(int data) {
        if (head == nullptr) return; // List is empty
        
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    // Function to search for a node with the given data
    bool search(int data) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                return true; // Data found
            }
            current = current->next;
        }
        return false; // Data not found
    }

    // Function to update a node's data with a new value
    void update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData; // Update the data
                return;
            }
            current = current->next;
        }
        cout << "Node with data " << oldData << " not found." << endl;
    }

    // Function to display the elements of the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl; // Indicate the end of the list
    }
};




int main(){
    LinkedList list;
    int choice, data, prevData;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Delete a Node\n";
        cout << "5. Search for a Node\n";
        cout << "6. Update a Node\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
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
                cout << "Enter data of the previous node: ";
                cin >> prevData;
                cout << "Enter data to insert after the previous node: ";
                cin >> data;
                if (list.search(prevData)) {
                    Node* current = list.head;
                    while (current != nullptr) {
                        if (current->data == prevData) {
                            list.insertAfter(current, data);
                            break;
                        }
                        current = current->next;
                    }
                } else {
                    cout << "Node with data " << prevData << " not found in the list." << endl;
                }
                    
                break;
            case 4:
                cout << "Enter data of the node to delete: ";
                cin >> data;
                list.deleteNode(data);
                break;
            case 5:
                cout << "Enter data to search for: ";
                cin >> data;
                if (list.search(data)) {
                    cout << "Node with data " << data << " found." << endl;
                } else {
                    cout << "Node with data " << data << " not found." << endl;
                }
                break;
            case 6:
                cout << "Enter old data to update: ";
                cin >> prevData;
                cout << "Enter new data: ";
                cin >> data;
                list.update(prevData, data);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
