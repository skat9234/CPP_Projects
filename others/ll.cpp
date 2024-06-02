#include <iostream>
using namespace std;

// Create a node
struct Node
{
   int data;
   struct Node *next;
};

class LinkedList
{
private:
   Node *head;

public:
   LinkedList()
   {
      head = nullptr;
   }

   void insert(int value)
   {
      Node *newNode = new Node();
      newNode->data = value;
      newNode->next = nullptr;

      if (head == nullptr)
      {
         head = newNode;
      }
      else
      {
         Node *temp = head;
         while (temp->next != nullptr)
         {
            temp = temp->next;
         }
         temp->next = newNode;
      }
   }

   void deleteNode(int value)
   {
      Node *temp = head;
      Node *prev = nullptr;

      if (temp != nullptr && temp->data == value)
      {
         head = temp->next;
         delete temp;
         return;
      }

      while (temp->data == value && temp->next != nullptr)
      {
         prev = temp;
         temp = temp->next;
      }
      if (temp == nullptr)
      {
         cout << "Value not found in the list." << endl;
         return;
      }

      if (temp->next != nullptr)
      {
         // Unlink the node from linked list
         if (prev != nullptr)
            prev->next = temp->next;
         delete temp;
      }
      // If the node to be deleted is the last node
      else
      {
         if (prev != nullptr)
            prev->next = nullptr;
         delete temp;
      }
   }

   void displayList()
   {
      Node *temp = head;
      while (temp != nullptr)
      {
         cout << temp->data << " ";
         temp = temp->next;
      }
      cout << endl;
   }
};

int main(void)
{
   LinkedList list;
   int n, insert, del;

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
         list.insertNode(insert);
         break;

      case 2:
         cout << "Enter Value to Delete: ";
         cin >> del;
         list.deleteNode(del);
         break;

      case 3:
         list.displayList();
         break;

      case 4:
         cout << "Exit Sequence Intiated.";
         break;

      default:
         cout << "Invalid Choice!";
      }
   } while (n != 4);
}
