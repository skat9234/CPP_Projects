// Write a menu driven program to implement a queue using singly linked list in which
// each node consists of a single data field of type character and performs the
// following operations:
//   i) Appending a node into the queue.
//   ii) Deleting the first node in the queue.
// Displaying data field of all the nodes in the queue horizontally.

#include <iostream>
using namespace std;

// Class definition for Node
class Node {
    public:
        char data; // Data field of type character
        Node* next; // Pointer to the next node
};

// Class definition for Queue
class Queue {
    private:
        Node* front; // Pointer to the front of the queue
        Node* rear; // Pointer to the rear of the queue
    
    public:
        // Constructor to initialize the front and rear pointers
        Queue() {
            front = nullptr;
            rear = nullptr;
        }

        // Function to append a node into the queue
        void append(char value) {
            Node* newNode =  new Node(); // Create a new node
            newNode->data = value; // Assign the value to the data field of the new node
            newNode->next = nullptr; // Set the next pointer of the new node to nullptr

            if(rear == nullptr) { // If the queue is empty
                front = newNode; // Set both front and rear pointers to the new node
                rear = newNode;
            } else { // If the queue is not empty
                rear->next = newNode; // Set the next pointer of the current rear node to the new node
                rear = newNode; // Update the rear pointer to the new node
            }
        }

        // Function to delete the first node in the queue
        void deleteNode() {
            if (front == nullptr) { // If the queue is empty
                cout << "Queue is empty. Cannot Delete" << endl;
                return;
            }

            Node* temp = front; // Create a temporary pointer to the front node

            if (front == rear) { // If there is only one node in the queue
                front = nullptr; // Set both front and rear pointers to nullptr
                rear = nullptr;
            } else { // If there are more than one nodes in the queue
                front = front->next; // Update the front pointer to the next node
            }
            delete temp; // Delete the temporary pointer
        }

        // Function to display the data field of all the nodes in the queue horizontally
        void display() {
            if (front == nullptr) { // If the queue is empty
                cout << "Queue is Empty." << endl;
                return;
            }

            Node* current = front; // Create a pointer to traverse the queue

            while (current != nullptr) { // Traverse the queue until the end
                cout << current->data << " "; // Print the data field of the current node
                current = current->next; // Move to the next node
            }
            cout << endl;
        }
};

// Main function
int main(void) {
    Queue queue; // Create an instance of the Queue class
    int choice; // Variable to store the user's choice
    char value; // Variable to store the character value entered by the user
    do
    {
        cout << "1. Append" << endl
             << "2. Delete" << endl
             << "3. Display" << endl
             << "4. Exit" << endl
             << "Enter your choice: ";
        cin >> choice; // Read the user's choice
        switch (choice)
        {
        case 1:
            cout << "Enter character to append into the queue: ";
            cin >> value; // Read the character value from the user
            queue.append(value); // Append the character into the queue
            break;
        case 2:
            queue.deleteNode(); // Delete the first node in the queue
            break;
        case 3:
            queue.display(); // Display the data field of all the nodes in the queue
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4); // Repeat the loop until the user chooses to exit
}