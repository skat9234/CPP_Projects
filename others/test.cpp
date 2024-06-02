// Things to Learn:
// 1. Linked List (Create, Insert, Remove, Display) 
// 2. Queue (Create, Insert, Remove, Display) + Stack (Create, Insert, Remove, Display)
// 3. Copy Details of One File to Another File with Conditions
// 4. Abstract Class Decleration + Parameterized COnstructor (Q33)
// 5. Solve All 3 mk Code Qs
// 6. Inheritance + Members Accessible + Order of Exec. of Constructors
// 7. Boolean Algebra (SOP + POS) + NAND & NOR Gate Realization 
// 8. Count the Number of Letters w/ conditions
// 9. Theory

void insert(int p) {
        if (start == nullptr) {
            cout << "Linked list is empty. Cannot insert at position " << p << "." << endl;
            return;
        }

        node* newNode = new node;
        // Data for New Node
        cout << "Enter the data for the new node:" << endl;
        cout << "Roll No: ";
        cin >> newNode->rno;
        cout << "Score: ";
        cin >> newNode->score;

        if (p == 1) {
            newNode->link = start;
            start = newNode;
            cout << "Node inserted at position " << p << "." << endl;
            return;
        }

        node* temp = start;
        for (int i = 1; i < p - 1 && temp != nullptr; ++i) {
            temp = temp->link;
        }

        if (temp == nullptr) {
            cout << "Cannot insert at position " << p << ". List shorter than position." << endl;
            delete newNode;
            return;
        }

        newNode->link = temp->link;
        temp->link = newNode;
        cout << "Node inserted at position " << p << "." << endl;
    }

void remove(int p) {
    if (start == nullptr) {
        cout << "Linked list is empty. Cannot remove node at position " << p << "." << endl;
        return;
    }

    if (p == 1) {
        node* temp = start;
        start = start->link;
        delete temp;
        cout << "Node removed from position " << p << "." << endl;
        return;
    }

    node* temp = start;
    for (int i = 1; i < p - 1 && temp != nullptr; ++i) {
        temp = temp->link;
    }

    if (temp == nullptr || temp->link == nullptr) {
        cout << "Cannot remove node at position " << p << ". List shorter than position." << endl;
        return;
    }

    node* toDelete = temp->link;
    temp->link = toDelete->link;
    delete toDelete;
    cout << "Node removed from position " << p << "." << endl;
    }    