#include <iostream> // Include the input/output stream library
#include <cstring>

using namespace std; // Use the standard namespace

class Node { // Declare a class named Node
public: // Public access specifier
    char data; // Data member to store character data
    Node* next; // Pointer to the next Node
};

class Stack { // Declare a class named Stack
    private: // Private access specifier
        Node* top; // Pointer to the top Node of the stack

public: // Public access specifier
    char S[30];
    Stack() { // Constructor for the Stack class
        top = nullptr; // Initialize the top pointer to nullptr (empty stack)
    }

    void push(char value) { // Method to push a character onto the stack
        Node* newNode = new Node(); // Create a new Node
        newNode->data = value; // Set the data of the new Node to the given value
        newNode->next = top; // Set the next pointer of the new Node to the current top Node
        top = newNode; // Update the top pointer to point to the new Node
    }

    void pop() { // Method to pop (remove) the top element from the stack
        if (top == nullptr) { // Check if the stack is empty
            cout << "Stack is empty. Cannot Pop." << endl; // Display an error message
            return; // Exit the method
        }
        Node* temp = top; // Create a temporary pointer to the top Node
        top = top->next; // Update the top pointer to point to the next Node
        delete temp; // Delete the temporary pointer (free memory)
    }
    void reverse() {
        cout << "Enter a string: ";
        cin.ignore();
        cin.getline(S, 30); // Assuming input string is not longer than 99 characters
        for (int i = 0; S[i] != 0; ++i) {
            push(S[i]);
        }
    }

    void display() { // Method to display the elements of the stack
        if (top == nullptr) { // Check if the stack is empty
            cout << "Stack is Empty." << endl; // Display a message indicating that the stack is empty
            return; // Exit the method
        }

        Node* current = top; // Create a pointer to traverse the stack starting from the top
        while (current != nullptr) { // Iterate until the end of the stack
            cout << current->data << " "; // Display the data of the current Node
            current = current->next; // Move to the next Node
        }
        cout << endl; // Print a new line after displaying all elements
    }
};

int main(void) { // Main function
    Stack stackObj; // Create an instance of the Stack class named stackObj

    int choice; // Variable to store the user's choice
    char value; // Variable to store the character value entered by the user

    do { // Start a do-while loop
        cout << "1. Push" << endl // Display the menu options
             << "2. Pop" << endl
             << "3. Reverse" << endl
             << "4. Display" << endl
             << "5. Exit" << endl
             << "Enter your choice: ";
        cin >> choice; // Read the user's choice

        switch (choice) { // Start a switch statement based on the user's choice
            case 1: // If the choice is 1
                cout << "Enter character to push onto stack: ";
                cin >> value; // Read the character value from the user
                stackObj.push(value); // Call the push method of the stackObj
                break; // Exit the switch statement

            case 2: // If the choice is 2
                stackObj.pop(); // Call the pop method of the stackObj
                break; // Exit the switch statement
            case 3:
                stackObj.reverse(); 
                break;
    
            case 4: // If the choice is 3
                stackObj.display(); // Call the display method of the stackObj
                break; // Exit the switch statement

            case 5: // If the choice is 4
                cout << "Exiting program." << endl; // Display a message indicating program exit
                break; // Exit the switch statement

            default: // If the choice is not 1, 2, 3, or 4 or 5
                cout << "Invalid choice. Please try again." << endl; // Display an error message
                break; // Exit the switch statement
        }
    } while (choice != 5); // Repeat the loop until the choice is 5 (Exit)
}