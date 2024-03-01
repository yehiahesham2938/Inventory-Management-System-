#ifndef INVENTORYMANAGEMENTSYSTEM_TREENODE_H
#define INVENTORYMANAGEMENTSYSTEM_TREENODE_H
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(const T& item) : data(item), left(nullptr), right(nullptr) {}
};



#endif //INVENTORYMANAGEMENTSYSTEM_TREENODE_H
