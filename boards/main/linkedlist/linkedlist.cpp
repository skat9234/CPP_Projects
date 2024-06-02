#include <iostream>
using namespace std;

class LinkedList {
    private:    
        struct Node {
            int data;
            Node* link;
        }*first;
    
    public:
        LinkedList() {
            first = nullptr;
        }

        void create(int n) {
            first = new Node;
            cout << "Enter Data for Node-1: ";
            cin >> first->data;
            first -> link = nullptr;

            Node* current = first;

            for (int i=2; i<=n; i++) {
                if (n<=0) {
                    cout << "Invalid Number of Nodes";
                    return;
                }
                cout << "Enter data for Node " << i << ": ";
                current->link = new Node;
                current = current->link;
                cin >> current->data;
                current->link = nullptr;
            }
            cout << endl;
        }

        void display() {
            if (first == nullptr) {
                cout << "List is Empty";
                return;
            }
            Node* current = first;
            cout << "Nodes with data b/w 5 & 50: ";
            while (current != nullptr) {
                if (current->data > 5 && current->data < 50) 
                    cout << current->data << " ";
                current = current->link;
            }
            cout << endl;
        }
};

int main (void) {
    int n;
    LinkedList list;
    cout << "Enter Number of Nodes: ";
    cin >> n;
    list.create(n);
    list.display();
}
