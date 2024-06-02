// Define a class named BILL with the following members:
//  i) item_code: of type unsigned short integer under private visibility label.
//  ii)item _name: a character array of size 30 under private visibility label.
//  iii) unit_price,total : of type float under private visibility label.
//  iv) quantity: of type unsigned short integer under private visibility
//      label.
//  v) Define a member function named “get data” to accept data members
//      item_code, item_name,unit_price and quantity. It computes total as quantity *
//      unit_price.
//  vi) Define a member function named “put data” to display data members
//      item_code, item_name,unit _price,quantity and total.
//      Write a menu driven main function to
//          a) Create a binary file named “market.data” containing objects of type BILL.
//          b) Display all the data members of the objects read from file “market.data” in
//              tabular form.
//              SAMPLE OUTPUT
//                  ITEM CODE    ITEM NAME      UNIT-PRICE   QUANTITY    TOTAL
//                  1000             PEN             10.00       5       50.00
//                  2000             PENCIL           5.00       3       15.00

#include <iostream>
#include <fstream>
using namespace std;


// Define a class named BILL
class BILL {
    private:
        // Private data members
        unsigned short item_code, quantity;
        char item_name[30];
        float unit_price, total;

    public:
        // Member function to accept data members
        void get_data() {
            cout << "Enter Item Code: ";
            cin >> item_code;

            cout << "Enter Item Name (30 char): ";
            cin.ignore();
            cin.getline(item_name, 30);

            cout << "Enter Unit Price: ";
            cin >> unit_price;

            cout << "Enter Quantity: ";
            cin >> quantity;

            total = quantity * unit_price;
        }

        // Member function to display data members
        void put_data() const {
            cout << item_code << "\t\t" << item_name << "\t\t" << unit_price << "\t\t" << quantity << "\t\t" << total
                 << endl;
        }

        // Member function to write object data to file
        void write_to_file() const {
            ofstream file("market.data", ios::binary | ios::app);
            if (file.is_open()) {
                file.write(reinterpret_cast<const char*>(this), sizeof(BILL));
                file.close();
            } else {
                cout << "Error: Unable to open file for writing. \n";
            }
        }

        // Member function to read object data from file and display in tabular form
        void read_from_file() const {
            ifstream file("market.data", ios::binary);
            if (file.is_open()) {
                BILL temp;
                cout << "ITEM CODE\tITEM NAME\tUNIT-PRICE\tQUANTITY\tTOTAL\n";
                while (file.read(reinterpret_cast<char*>(&temp), sizeof(BILL))) {
                    temp.put_data();
                }
                file.close();
            } else {
                cout << "Error: Unable to open file for reading. \n";
            }
        }
};

int main(void)
{
    BILL bill;
    int choice;
    do
    {
        cout << "\nMenu:\n1. Add Item to market.data\n2. Display market.data\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bill.get_data();
            bill.write_to_file();
            cout << "Item added to market.data.\n";
            break;
        case 2:
            bill.read_from_file();
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 3);
}

