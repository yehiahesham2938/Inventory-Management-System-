#ifndef INVENTORYMANAGEMENTSYSTEM_SPAREPART_H
#define INVENTORYMANAGEMENTSYSTEM_SPAREPART_H
#include <iostream>
#include "DataStructures/LinkedList.h"
#include "DataStructures/Stack.h"
#include "DataStructures/Queue.h"
#include "DataStructures/BinaryTree.h"
#include "SparePartTree.h"
#include "History.h"
#include "Supplier.h"
using namespace std;

class SparePart: public SparePartTree
        {
private:
    string partName;
    int existingParts;
    float Cost;
    Queue<string> spare_part_processing;
protected:
    LinkedList<SparePart> SparePartsList;
public:
    int partNumber;

    void setPartNumber(int partnumber)
    {
        partNumber = partnumber;
    }
    void setExistingParts(int ExistingParts)
    {
        existingParts = ExistingParts;
    }
    void setPartName( string& PartName)
    {
    partName = PartName;
    }
    void setCost(float cost)
    {
        Cost = cost;
    }

    int getPartNumber()
    {
        return partNumber;
    }

    void PutData(SparePart sparePart) {
        string partname;
        int Partnumber, existingparts;
        float cost;
        bool UniquePartNum = false;


        cout << "Enter the Part Name: ";
        cin >> partname;

        while (!UniquePartNum) {
            cout << "Enter the Part Number: ";
            cin >> Partnumber;

            Node<SparePart>* current;
            current = SparePartsList.getHead();
            UniquePartNum = true;

            while (current != nullptr)
            {
                if (current->data.partNumber == Partnumber) {
                    UniquePartNum = false;
                    cout << "Part number already exists. Please enter a unique part number." << endl;
                }
                current = current->next;
            }
        }
        cout <<"Enter the Number of Existing Parts: ";
        cin >> existingparts;
        cout << "Enter the Cost of the Spare Part: ";
        cin >> cost;
        sparePart.setPartName(partname);
        sparePart.setPartNumber(Partnumber);
        sparePart.setExistingParts(existingparts);
        sparePart.setCost(cost);
        SparePartsList.insert(sparePart);
        string processingMessage = "Spare Part " + to_string(Partnumber) + " data processing in progress.";
        spare_part_processing.enqueue(processingMessage);
        cout << processingMessage;
        addsparePart(Partnumber);
        insertInTree(Partnumber);
    }

    void GetData()
    {
        Node<SparePart> *Current = SparePartsList.getHead();
        if (Current == nullptr)
        {
            cout << "There is no spare parts." << endl;
        }
        while (Current != nullptr) {
            cout << "_______________________________" << endl;
            cout << "Part Name: " << Current->data.partName << endl;
            cout << "Part Number: " << Current->data.partNumber << endl;
            cout << "Existing Parts: " << Current->data.existingParts << endl;
            cout << "Cost: " << Current->data.Cost << endl;
            cout << "_______________________________" << endl;
            Current = Current->next;
        }
    }


    void ModifyData() {
        bool found = false;
        if (SparePartsList.getHead() == nullptr) {
            found = false;
        } else {
            cout << "Enter Part Number to Modify: ";
            int ModifiedPartNumber;
            cin >> ModifiedPartNumber;

            Node<SparePart> *current;
            current = SparePartsList.getHead();
            string modificationMessage = "Spare Part " + to_string(ModifiedPartNumber) + " modifying in progress.";

            while (current != nullptr) {
                if (current->data.partNumber == ModifiedPartNumber) {
                    found = true;
                    cout << "Enter new Part Name: ";
                    cin >> current->data.partName;


                    cout << "Enter new Number of Existing Parts: ";
                    cin >> current->data.existingParts;

                    cout << "Enter new Cost: ";
                    cin >> current->data.Cost;
                    cout << modificationMessage;
                }
                current = current ->next;
            };
            spare_part_processing.enqueue(modificationMessage);
            ModifySparePart(ModifiedPartNumber);
        };

        if (!found)
        {
            cout << "Spare part was not found" << endl;
        }

    }

    void DeleteSparePart(int DeleteKey) {
        Node<SparePart>* current = SparePartsList.getHead();
        Node<SparePart>* prev = nullptr;
        bool found = false;

        while (current != nullptr) {
            if (current->data.getPartNumber() == DeleteKey) {
                found = true;
                if (prev == nullptr) {

                    SparePartsList.setHead(current->next);
                } else {

                    prev->next = current->next;
                }

                delete current;
                cout << "Spare Part with Part Number " << DeleteKey << " deleted." << endl;
                DeleteSparepart(DeleteKey);
            }

            prev = current;
            current = current->next;
        }
        if (!found)
        {
            cout << "Spare Part with Part Number " << DeleteKey << " not found." << endl;
        }
        DeleteFromSparePartTree(DeleteKey);

    }

    void printSparePartSearch(int searchKey)
    {
        SearchSparePart(searchKey);
        Node<SparePart>* current;
        current = SparePartsList.getHead();
        while (current != nullptr) {
            if (current->data.partNumber == searchKey) {
                cout << "_______________________________" << endl;
                cout << "Part Name: " << current->data.partName << endl;
                cout << "Part Number: " << current->data.partNumber << endl;
                cout << "Existing Parts: " << current->data.existingParts << endl;
                cout << "Cost: " << current->data.Cost << endl;
                cout << "_______________________________" << endl;
            }
            current = current->next;
        }
    }


};

#endif //INVENTORYMANAGEMENTSYSTEM_SPAREPART_H