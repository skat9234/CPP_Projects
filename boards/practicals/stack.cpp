#include <iostream>

using namespace std;

class Node {
public:
    char data;
    Node* next;
};

class Stack {
    private:
        Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot Pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is Empty." << endl;
            return;
        }

        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main(void) {
    Stack stackObj;

    int choice;
    char value;

    do {
        cout << "1. Push" << endl
             << "2. Pop" << endl
             << "3. Display" << endl
             << "4. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter character to push onto stack: ";
                cin >> value;
                stackObj.push(value);
                break;
            case 2:
                stackObj.pop();
                break;
            case 3:
                stackObj.display();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);
}
