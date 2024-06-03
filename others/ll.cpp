// Include the necessary header file for input/output operations
#include <iostream>
// Import the entire std namespace to avoid writing std:: before standard library functions and objects
using namespace std;

// Define a structure for a node in a linked list
struct Node
{
   int data;           // Data stored in the node
   struct Node *next;  // Pointer to the next node in the list
};

// Define a class for a linked list
class LinkedList
{
private:
   Node *head;  // Pointer to the head (first node) of the list

public:
   // Constructor for the LinkedList class
   LinkedList()
   {
      head = nullptr;  // Initialize the head pointer to nullptr (empty list)
   }

   // Function to insert a new node at the end of the list
   void insert(int value)
   {
      // Create a new node
      Node *newNode = new Node();
      newNode->data = value;  // Set the data of the new node to the given value
      newNode->next = nullptr;  // Set the next pointer of the new node to nullptr

      // If the list is empty, make the new node the head of the list
      if (head == nullptr)
      {
         head = newNode;
      }
      else
      {
         // Traverse the list to find the last node
         Node *temp = head;
         while (temp->next != nullptr)
         {
            temp = temp->next;
         }
         // Link the new node to the last node in the list
         temp->next = newNode;
      }
   }

   // Function to delete a node with a given value from the list
   void deleteNode(int value)
   {
      Node *temp = head;  // Start from the head of the list
      Node *prev = nullptr;  // Pointer to the previous node

      // If the head node itself holds the value to be deleted
      if (temp != nullptr && temp->data == value)
      {
         head = temp->next;  // Update the head to the next node
         delete temp;  // Delete the current node
         return;
      }

      // Search for the node with the given value
      while (temp != nullptr && temp->data != value)
      {
         prev = temp;  // Keep track of the previous node
         temp = temp->next;  // Move to the next node
      }

      // If the value is not found in the list
      if (temp == nullptr)
      {
         cout << "Value not found in the list." << endl;
         return;
      }

      // Unlink the node from the list
      prev->next = temp->next;
      delete temp;  // Delete the current node
   }

   // Function to display the elements of the list
   void displayList()
   {
      Node *temp = head;  // Start from the head of the list
      while (temp != nullptr)
      {
         cout << temp->data << " ";  // Print the data of the current node
         temp = temp->next;  // Move to the next node
      }
      cout << endl;
   }
};

// The main function where the program execution starts
int main(void)
{
   LinkedList list;  // Create an instance of the LinkedList class
   int n, insert, del;  // Variables for user input

   // Display a menu and perform operations based on user input
   do
   {
      cout << "1. Insertion of Node" << endl
           << "2. Deletion of Node" << endl
           << "3. Display List" << endl
           << "4. Exit" << endl;
      cout << "Which Operation would you like to perform? ";
      cin >> n;

      switch (n)
      {
      case 1:
         cout << "Enter Value to Insert: ";
         cin >> insert;
         list.insert(insert);  // Call the insert function to insert a node with the given value
         break;

      case 2:
         cout << "Enter Value to Delete: ";
         cin >> del;
         list.deleteNode(del);  // Call the deleteNode function to delete a node with the given value
         break;

      case 3:
         list.displayList();  // Call the displayList function to display the elements of the list
         break;

      case 4:
         cout << "Exit Sequence Initiated.";
         break;

      default:
         cout << "Invalid Choice!";
      }
   } while (n != 4);

   return 0;  // Return 0 to indicate successful program execution
}