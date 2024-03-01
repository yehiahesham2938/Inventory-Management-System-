#ifndef INVENTORYMANAGEMENTSYSTEM_SUPPLIER_H
#define INVENTORYMANAGEMENTSYSTEM_SUPPLIER_H
#include <iostream>
#include "DataStructures/LinkedList.h"
#include "History.h"
#include "DataStructures/Queue.h"
#include "DataStructures/Stack.h"
#include "SupplierTree.h"
using namespace std;
class Supplier: public SupplierTree
{
private:
    string SupplierName, Address, Email, Telephone;
    Queue<string> suppliers_processing_Queue;
protected:
    LinkedList<Supplier> SuppliersList;

public:
    int SupplierCode;

    void setSupplierName(string name)
    {
        SupplierName = name;
    }

    void setAddress(string address)
    {
        Address = address;
    }

    void setEmail(string email)
    {
        Email = email;
    }

    void setTelephone(string telephone)
    {
        Telephone = telephone;
    }

    void setSupplierCode(int code)
    {
        SupplierCode = code;
    }

    int getSupplierCode()
    {
        return SupplierCode;
    }

    void PutData(Supplier supplier)
    {
        string SupplierName, Address, Email, Telephone;
        int SupplierCode;
        bool UniqueSupplierCode = false;

        cout << "Enter Supplier Name: ";
        cin >> SupplierName;
        cout << endl
             << "Enter the Address: ";
        cin >> Address;
        cout << endl
             << "Enter the Email: ";
        cin >> Email;
        cout << endl;

        while (!UniqueSupplierCode)
        {
            cout << "Enter the Supplier Code: ";
            cin >> SupplierCode;

            Node<Supplier> *current;
            current = SuppliersList.getHead();
            UniqueSupplierCode = true;

            while (current != nullptr)
            {
                if (current->data.SupplierCode == SupplierCode)
                {
                    UniqueSupplierCode = false;
                    cout << "Supplier Code already exists. Please enter a unique supplier code." << endl;
                }
                current = current->next;
            }
        }
        cout << endl
             << "Enter the Telephone: ";
        cin >> Telephone;
        cout << endl;
        supplier.setSupplierName(SupplierName);
        supplier.setAddress(Address);
        supplier.setEmail(Email);
        supplier.setSupplierCode(SupplierCode);
        supplier.setTelephone(Telephone);

        SuppliersList.insert(supplier);
        string processingMessage = "Supplier" + to_string(SupplierCode) + " data processing in progress";
        suppliers_processing_Queue.enqueue(processingMessage);
        cout << processingMessage << endl;
        addSupplier(SupplierCode);
        InsertInTree(SupplierCode);
    }

    void GetData()
    {
        Node<Supplier> *Current = SuppliersList.getHead();

        if (Current == nullptr)
        {
            cout << "No suppliers " << endl;
        }
        while (Current != nullptr)
        {
            cout << "_______________________________" << endl;
            cout << "Supplier Name: " << Current->data.SupplierName << endl;
            cout << "Address: " << Current->data.Address << endl;
            cout << "Email: " << Current->data.Email << endl;
            cout << "Supplier Code: " << Current->data.SupplierCode << endl;
            cout << "Telephone: " << Current->data.Telephone << endl;
            cout << "_______________________________" << endl;

            Current = Current->next;
        }
    }

    void ModifyData()
    {
        bool found = false;

        if (SuppliersList.getHead() == nullptr)
        {
            found = false;
        }
        else
        {
            cout << "Enter Supplier Code to Modify: ";
            int modifiedSupplierCode;
            cin >> modifiedSupplierCode;

            Node<Supplier> *current;
            current = SuppliersList.getHead();
            string modifyingMessage = "Supplier" + to_string(modifiedSupplierCode) + " modifying in progress";

            while (current != nullptr)
            {
                if (current->data.SupplierCode == modifiedSupplierCode)
                {
                    found = true;

                    cout << "Enter new Supplier Name: ";
                    cin >> current->data.SupplierName;

                    cout << "Enter new Address: ";
                    cin >> current->data.Address;

                    cout << "Enter new Email: ";
                    cin >> current->data.Email;

                    cout << "Enter new Telephone: ";
                    cin >> current->data.Telephone;
                    cout << modifyingMessage;

                }
                current = current->next;
            };

            suppliers_processing_Queue.enqueue(modifyingMessage);
            ModifySupplier(modifiedSupplierCode);
        };

        if (!found)
        {
            cout << "Supplier was not found." << endl;
        }
    }
    bool DeleteSupplier(int supplierCode) {

        DeleteFromSupplierTree(supplierCode);

        Node<Supplier>* current = SuppliersList.getHead();
        Node<Supplier>* prev = nullptr;

        while (current != nullptr) {
            if (current->data.getSupplierCode() == supplierCode) {
                if (prev == nullptr) {
                    SuppliersList.setHead(current->next);
                } else {
                    prev->next = current->next;
                }

                delete current;
                cout << "Supplier with Supplier Code " << supplierCode << " deleted." << endl;
                deleteSupplier(supplierCode);
                return true;
            }

            prev = current;
            current = current->next;
        }

        cout << "Supplier with Supplier Code " << supplierCode << " not found." << endl;
        return false;
    }

    void printSupplierSearch(int searchKey)
    {
        SearchSupplier(searchKey);
        Node<Supplier> *current;
        current = SuppliersList.getHead();

        while (current != nullptr) {
            if (current->data.getSupplierCode() == searchKey)
            {
                cout << "_______________________________" << endl;
                cout << "Supplier Name: " << current->data.SupplierName << endl;
                cout << "Address: " << current->data.Address << endl;
                cout << "Email: " << current->data.Email << endl;
                cout << "Supplier Code: " << current->data.SupplierCode << endl;
                cout << "Telephone: " << current->data.Telephone << endl;
                cout << "_______________________________" << endl;
            }
            current = current->next;
        }

    }



};
#endif // INVENTORYMANAGEMENTSYSTEM_SUPPLIER_H
