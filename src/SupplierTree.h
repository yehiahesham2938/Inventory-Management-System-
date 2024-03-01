#ifndef INVENTORYMANAGEMENTSYSTEM_SUPPLIERTREE_H
#define INVENTORYMANAGEMENTSYSTEM_SUPPLIERTREE_H

#include "DataStructures/BinaryTree.h"
#include "Supplier.h"

class SupplierTree {
private:
    BinaryTree<int> supplierTree;
public:

    void InsertInTree(int supplierCode) {
        supplierTree.insert(supplierCode);
    }

    void SearchSupplier(int SearchKey) {
        bool Found = false;
        supplierTree.search(SearchKey , Found);
        if (Found)
        {
            cout << SearchKey << " is Found." << endl;
        } else
        {
            cout << SearchKey << " is not Found." << endl;
        }
    }

    void DeleteFromSupplierTree(int supplierCode) {
        supplierTree.deleteNode(supplierCode);
    }

};


#endif //INVENTORYMANAGEMENTSYSTEM_SUPPLIERTREE_H
