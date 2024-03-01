#ifndef INVENTORYMANAGEMENTSYSTEM_SPAREPARTTREE_H
#define INVENTORYMANAGEMENTSYSTEM_SPAREPARTTREE_H

#include "DataStructures/BinaryTree.h"
#include "SparePart.h"
#include <iostream>

class SparePartTree{
private:
    BinaryTree<int> sparePartTree;
public:
    SparePartTree():sparePartTree(){}

    void insertInTree(int partNumber)
    {
        sparePartTree.insert(partNumber);
    }

    void SearchSparePart(int SearchKey) {
        bool Found = false;
        sparePartTree.search( SearchKey , Found);
        if (Found) {
            cout << SearchKey << " is Found." << endl;
        } else {
            cout << SearchKey << " is not Found." << endl;
        }

    }


    void DeleteFromSparePartTree(int partNumber) {
        sparePartTree.deleteNode(partNumber);
    }

};


#endif //INVENTORYMANAGEMENTSYSTEM_SPAREPARTTREE_H
