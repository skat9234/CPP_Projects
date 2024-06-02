// Write a menu driven program to implement a singly linked list in which each node consists of
// the following data fields:
//  i) M.N,Q: of type short unsigned integer under private visibility label.
//  ii) roll- of type unsigned short integer.
//  iii) name- an array of maximum 30 characters.
//  iv) percent- of type float
//      And perform the following operations:
//          a) Creation of a linear linked list containing “n” nodes.
//          b) Display the linear linked list in the following format:
//                  ROLL NAME PERCENT
//                  1000 SACHIN 89.9
//                  2000 KARUN 75.52
//                  3000 KIERA 65.18


#include <iostream> // Include the input/output stream library
#include <cstring> // Include the string manipulation library
using namespace std; // Use the standard namespace

class Node { // Declare a class named Node
    private: // Access specifier: private
        short unsigned roll; // Declare a private member variable of type short unsigned integer named roll
        char name[31]; // Declare a private member variable of type character array with size 31 named name
        float percent; // Declare a private member variable of type float named percent
        Node *next; // Declare a private member variable of type Node pointer named next
    
    public: // Access specifier: public
        Node(short unsigned r=0, const char* n="", float p = 0.0) : roll(r), percent(p), next(nullptr) { // Constructor with default arguments
            strncpy(name, n, 30); // Copy at most 30 characters from n to name
            name[30] = '\0'; // Set the last character of name as null terminator
        }
        friend class LinkedList; // Declare LinkedList class as a friend of Node class
};

class LinkedList { // Declare a class named LinkedList
    private: // Access specifier: private
        Node* head; // Declare a private member variable of type Node pointer named head
    
    public: // Access specifier: public
        LinkedList() : head(nullptr) {} // Constructor: Initialize head as nullptr

        void insertNode(short unsigned r, const char* n, float p) { // Define a member function named insertNode
            Node* newNode =  new Node(r,n,p); // Create a new Node object with given arguments
            newNode -> next = head; // Set the next pointer of newNode to the current head
            head = newNode; // Update head to point to newNode
        }

        void displayList() { // Define a member function named displayList
            cout << "ROLL\tHEAD\t\tPERCENT" << endl; // Print the column headers
            Node* current = head; // Create a pointer named current and initialize it with head
            while (current != nullptr) { // Loop until current becomes nullptr
                cout << current -> roll << "\t" << current -> name << "\t\t" << current -> percent << endl; // Print the roll, name, and percent of the current node
                current = current -> next; // Move current to the next node
            }
        }

        ~LinkedList() { // Destructor
            Node* current = head; // Create a pointer named current and initialize it with head
            Node* nextNode; // Declare a pointer named nextNode
            while (current != nullptr) { // Loop until current becomes nullptr
                nextNode = current -> next; // Store the next node in nextNode
                delete current; // Delete the current node
                current = nextNode; // Move current to the next node
            }
            head = nullptr; // Set head to nullptr
        }
};

int main(void) { // Main function
    LinkedList linkedList; // Create an object of LinkedList class named linkedList
    int choice; // Declare an integer variable named choice

    do { // Start a do-while loop
        cout << "\nMenu:\n1. Insert a Node\n2. Display Linked List\n3. Exit\nEnter your choice: "; // Print the menu options
        cin >> choice; // Read the choice from the user

        switch (choice) { // Start a switch statement based on the choice
            case 1: // If choice is 1
                short unsigned roll; // Declare a short unsigned integer variable named roll
                char name[31]; // Declare a character array variable with size 31 named name
                float percent; // Declare a float variable named percent
                cout << "Enter Roll: "; // Prompt the user to enter the roll
                cin >> roll; // Read the roll from the user
                cout << "Enter Name: "; // Prompt the user to enter the name
                cin.ignore(); // Ignore the newline character in the input buffer
                cin.getline(name, 30); // Read the name from the user
                cout << "Enter Percent: "; // Prompt the user to enter the percent
                cin >> percent; // Read the percent from the user
                linkedList.insertNode(roll, name, percent); // Call the insertNode function of linkedList object with the entered values
                break; // Exit the switch statement
            
            case 2: // If choice is 2
                linkedList.displayList(); // Call the displayList function of linkedList object
                break; // Exit the switch statement
            
            case 3: // If choice is 3
             cout << "Exiting Program \n"; // Print a message indicating program exit
             break; // Exit the switch statement

             default: // If choice is not 1, 2, or 3
                cout << "Invalid Choice. Please enter a Valid Input. \n"; // Print an error message
        }
    } while (choice != 3); // Repeat the loop until choice is not 3

    return 0; // Return 0 to indicate successful program execution
}