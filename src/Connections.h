#ifndef INVENTORYMANAGEMENTSYSTEM_CONNECTIONS_H
#define INVENTORYMANAGEMENTSYSTEM_CONNECTIONS_H

#include <iostream>
#include "DataStructures/LinkedList.h"
#include "SparePart.h"
#include "Supplier.h"
using namespace std;

class connections: public SparePart, public Supplier
{
private:
    LinkedList<connections> ConnectionsList;
    int SparePartNumber, SupplierCode;
public:

    void setSparePartNumber(int sparePartNumber)
    {
        SparePartNumber = sparePartNumber;
    }

    void setSupplierCode(int supplierCode)
    {
        SupplierCode = supplierCode;
    }

    int getSparePartNumber()
    {
        return SparePartNumber;
    }

    int getSupplierCode()
    {
        return SupplierCode;
    }


    void addConnection(int SparePartNumber, int SupplierKey, LinkedList<Supplier> &SuppliersList, LinkedList<SparePart> &SparePartsList)
    {
        Node<Supplier> *currentSupplier;
        currentSupplier = SuppliersList.getHead();
        bool foundSupplier = false;

        while (currentSupplier != nullptr)
        {
            if (currentSupplier->data.getSupplierCode() == SupplierKey)
            {
                foundSupplier = true;
                cout << "Supplier was found" << endl;
            }
            currentSupplier = currentSupplier->next;
        }

        if (!foundSupplier)
        {
            cout << "Supplier was not found" << endl;
        }

        Node<SparePart> *current;
        current = SparePartsList.getHead();
        bool foundSparepart = false;
        while (current != nullptr)
        {
            if (current->data.getPartNumber() == SparePartNumber)
            {
                foundSparepart = true;
                if (foundSupplier)
                {
                    connections connection;
                    connection.setSparePartNumber(SparePartNumber);
                    connection.setSupplierCode(SupplierKey);
                    ConnectionsList.insert(connection);
                    cout << "Connection was added successfully" << endl;
                }
            }
            current = current->next;
        }
        if (!foundSparepart)
        {
            cout << "Spare Part was not found" << endl;
        }
    }
    void Connections()
    {
        cout << "Enter the Spare Part Number to connect with: ";
        int SparePartNumber;
        cin >> SparePartNumber;
        cout << "Enter the Supplier Code: ";
        int SupplierCode;
        cin >> SupplierCode;
        addConnection(SparePartNumber, SupplierCode, SuppliersList, SparePartsList);
    }

};

#endif //INVENTORYMANAGEMENTSYSTEM_CONNECTIONS_H
