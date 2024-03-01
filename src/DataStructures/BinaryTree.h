#ifndef INVENTORYMANAGEMENTSYSTEM_BINARYTREE_H
#define INVENTORYMANAGEMENTSYSTEM_BINARYTREE_H

#include "TreeNode.h"
#include <iostream>
using namespace std;

template <typename T>
class BinaryTree {
private:
    TreeNode<T>* root;
public:
    BinaryTree() : root(nullptr) {}

    void setRoot(BinaryTree<T>* NewRoot)
    {
        root = NewRoot;
    }

    void insertNode(TreeNode<T>*& root, const T& item) {
        if (root == nullptr) {
            root = new TreeNode<T>(item);
        }
        else {
            if (item < root->data) {
                insertNode(root->left, item);
            }
            else {
                insertNode(root->right, item);
            }
        }
    }

    void insert(const T& item) {
        insertNode(root, item);
    }



    void search(TreeNode<T>* root, const T& item, bool& found) {
        if (root != nullptr && !found) {
            if (root->data == item) {
                found = true;
            }
            else {
                search(root->left, item, found);
                search(root->right, item, found);
            }
        }
    }

    void search(const T& item, bool& found) {
        search(root, item, found);
    }

    void deleteNode(TreeNode<T>*& root, const T& item) {
        if (root != nullptr) {
            if (root->data == item) {
                if (root->left == nullptr && root->right == nullptr)
                {
                    delete root;
                    root = nullptr;
                }
                else if (root->left == nullptr)
                {
                    TreeNode<T>* temp = root;
                    root = root->right;
                    delete temp;
                }
                else if (root->right == nullptr)
                {
                    TreeNode<T>* temp = root;
                    root = root->left;
                    delete temp;
                }
                else {
                    TreeNode<T>* temp = root->right;
                    while (temp->left != nullptr)
                    {
                        temp = temp->left;
                    }
                    root->data = temp->data;
                    deleteNode(root->right, temp->data);
                }
            } else
            {
                deleteNode(root->left, item);
                deleteNode(root->right, item);
            }
        }
    }

    void deleteNode(const T& item) {
        deleteNode(root, item);
    }
};

#endif //INVENTORYMANAGEMENTSYSTEM_BINARYTREE_H
