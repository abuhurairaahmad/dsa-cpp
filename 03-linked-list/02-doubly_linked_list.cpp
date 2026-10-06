#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Doubly linked list class
class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Function to insert a new node at the beginning of the doubly linked list
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Function to insert a new node at the end of the doubly linked list
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
        newNode->prev = current;
    }

    // Function to add a new node at a given position
    void insertAtPosition(int position, int data) {
        if (position < 0) return; // Invalid position

        if (position == 0) {
            insertAtBeginning(data);
            return;
        }

        Node* current = head;
        int currentPosition = 0;
        while (currentPosition < position - 1 && current != nullptr) {
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr) return; // Position is out of bounds

        Node* newNode = new Node(data);
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
            current->next = newNode;
        }
    }

    void deleteNode(int data) {
        if (head == nullptr) return; // List is empty

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            delete temp;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                if (current->prev != nullptr)
                    current->prev->next = current->next;
                if (current->next != nullptr)
                    current->next->prev = current->prev;
                delete current;
                return;
            }
            current = current->next;
        }
    }

    // Function to display the elements of the doubly linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main(){
    DoublyLinkedList list;
    int choice, data, position;

    do {
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete Node\n";
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
                cout << "Enter position to insert at: ";
                cin >> position;
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertAtPosition(position, data);
                break;
            case 4:
                cout << "Enter data of the node to delete: ";
                cin >> data;
                list.deleteNode(data);
                break;
            case 5:
                list.display();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);
    
    return 0;
}
