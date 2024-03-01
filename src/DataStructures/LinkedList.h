#ifndef INVENTORYMANAGEMENTSYSTEM_LINKEDLIST_H
#define INVENTORYMANAGEMENTSYSTEM_LINKEDLIST_H

#include "Node.h"
template <typename T>
class LinkedList
{
private:
    Node <T> *head;
public:
    LinkedList()
    {
        head = nullptr;
    }

    void insert(T& Data)
    {
        Node <T>* newnode = new Node<T>(Data);
        newnode->next = head;
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            newnode ->next = head;
            head = newnode;
        }

    }

    void setHead(Node<T>* newHead) {
        head = newHead;
    }

    Node<T>* getHead()
    {
        return head;
    }
};

#endif //INVENTORYMANAGEMENTSYSTEM_LINKEDLIST_H
