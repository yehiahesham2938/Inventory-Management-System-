#ifndef INVENTORYMANAGEMENTSYSTEM_STACK_H
#define INVENTORYMANAGEMENTSYSTEM_STACK_H
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class stack
{
private:
    Node<T>* top;
public:
    stack()
    {
        top = nullptr;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    void push( T& item)
    {
        Node<T>* newNode = new Node<T>(item);
        newNode->next = top;
        top = newNode;
    }
    T pop()
    {
        if (!isEmpty()) {
            Node<T> *temp = top;
            T poppedItem = temp->data;
            top = top->next;
            delete temp;
            return poppedItem;
        } else {
            cout << "stack is empty";
        }
    }
    void display() {
        Node<T>* current = top;
        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }

};


#endif //INVENTORYMANAGEMENTSYSTEM_STACK_H
