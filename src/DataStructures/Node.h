#ifndef INVENTORYMANAGEMENTSYSTEM_NODE_H
#define INVENTORYMANAGEMENTSYSTEM_NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T& data) : data(data),next(nullptr) {}
};
#endif //INVENTORYMANAGEMENTSYSTEM_NODE_H
