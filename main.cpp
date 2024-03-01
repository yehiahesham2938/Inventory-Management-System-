#include <iostream>
#include "src/SparePart.h"
#include "src/Supplier.h"
#include "src/Connections.h"
#include "src/History.h"

int main()
{
    int NumberOfSpareParts, NumberOfSuppliers, choice;
    SparePart sparePart;
    Supplier supplier;
    connections connections;
    while (true)
    {
        cout << endl << "1. Add Spare Part" << endl;
        cout << "2. Modify Spare Part" << endl;
        cout << "3. Delete Spare Part" << endl;
        cout << "4. Search Spare Part" << endl;
        cout << "5. Get Spare Part Data" << endl;
        cout << "6. Add Supplier" << endl;
        cout << "7. Modify Supplier" << endl;
        cout << "8. Delete Supplier" << endl;
        cout << "9. Search Supplier" << endl;
        cout << "10. Get Suppliers Data" << endl;
        cout << "11. Print Interaction History" << endl;
        cout << "12. Add Connections" << endl;
        cout << "13. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter number of spare parts you want to add: " << endl;
            cin >> NumberOfSpareParts;
            while (NumberOfSpareParts > 100)
            {
                cout << "Sorry, the maximum number of spare parts to handle is 100 please choose a number from [ 1 - 100 ]";
                cin >> NumberOfSpareParts;
            }
            for (int i = 0; i < NumberOfSpareParts; i++)
            {
                sparePart.PutData(sparePart);

                cout << endl << "Spare part was added successfully" << endl;
            }
            break;

        case 2:
            sparePart.ModifyData();
            break;

        case 3:
            int deletePartNumber;
                cout << "Enter Part Number to delete: ";
                cin >> deletePartNumber;

                sparePart.DeleteSparePart(deletePartNumber);
                break;
        case 4:
            int searchPartNumber;
            cout << "Enter Part Number to search: ";
             cin >> searchPartNumber;
             sparePart.printSparePartSearch(searchPartNumber);
             break;
        case 5:
            sparePart.GetData();
            break;
        case 6:

            cout << "Enter Number of Suppliers you want to add: " << endl;
            cin >> NumberOfSuppliers;
            while (NumberOfSuppliers > 20)
            {
                cout << "Sorry, the maximum number of suppliers to add is 20 please choose a valid number from [1 - 20] ";
                cin >> NumberOfSuppliers;
            }
            for (int i = 0; i < NumberOfSuppliers; i++)
            {
                supplier.PutData(supplier);
                cout << endl << "Supplier was added successfully" << endl;
            }
            break;
        case 7:
            supplier.ModifyData();
            break;

        case 8:
            int deleteSupplierCode;
                cout << "Enter Supplier Code to delete: ";
                cin >> deleteSupplierCode;

                supplier.DeleteSupplier(deleteSupplierCode);
                break;
        case 9:
            int searchSupplierCode;
                cout << "Enter Supplier Code to search: ";
                cin >> searchSupplierCode;

                supplier.printSupplierSearch(searchSupplierCode);
                break;
        case 10:
            supplier.GetData();
            break;
        case 11:
            InteractionHistory();
            break;

        case 12:
            connections.Connections();
            break;

        case 13:
            cout << "Exiting program.";
            return 0;


        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}
