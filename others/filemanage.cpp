#include <iostream>
#include <fstream>

using namespace std;
class BILL
{
private:
    unsigned short item_code;
    char item_name[30];
    float unit_price;
    unsigned short quantity;
    float total;

public:
    void get_data()
    {
        cout << "Enter Item Code: ";
        cin >> item_code;
        cout << "Enter Item Name (up to 30 characters): ";
        cin.ignore(); // Ignore the newline character in the buffer
        cin.getline(item_name, 30);
        cout << "Enter Unit Price: ";
        cin >> unit_price;
        cout << "Enter Quantity: ";
        cin >> quantity;
        // Compute total
        total = quantity * unit_price;
    }
    void put_data() const
    {
        cout << item_code << "\t\t" << item_name << "\t\t" << unit_price << "\t\t" << quantity << "\t\t" << total
             << endl;
    }
    void write_to_file() const
    {
        ofstream file("market.data", ios::binary | ios::app);
        if (file.is_open())
        {
            file.write(reinterpret_cast<const char *>(this), sizeof(BILL));
            file.close();
        }
        else
        {
            cout << "Error: Unable to open file for writing.\n";
        }
    }
    void read_from_file() const
    {
        ifstream file("market.data", ios::binary);
        if (file.is_open())
        {
            BILL temp;
            cout << "ITEM CODE\tITEM NAME\tUNIT-PRICE\tQUANTITY\tTOTAL\n";
            while (file.read(reinterpret_cast<char *>(&temp), sizeof(BILL)))
            {
                temp.put_data();
            }
            file.close();
        }
        else
        {
            cout << "Error: Unable to open file for reading.\n";
        }
    }
};
int main()
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
    return 0;
}