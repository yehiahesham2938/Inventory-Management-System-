#ifndef INVENTORYMANAGEMENTSYSTEM_QUEUE_H
#define INVENTORYMANAGEMENTSYSTEM_QUEUE_H
#include "Node.h"
#include <iostream>
using namespace std;
template <typename T>
class Queue
{
private:
    Node<T>* front;
public:
    Queue() : front(nullptr) {}

    void enqueue(T& data)
    {
        Node<T>* newNode = new Node<T>(data);
        newNode->data = data;
        if (front == nullptr)
        {
            front = newNode;
        }
        else
        {
            Node<T>* temp = front;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            return;
        } else {
            Node<T> *temp;
            temp = front;
            front = front->next;
            delete temp;
        }
    }

};
#endif //INVENTORYMANAGEMENTSYSTEM_QUEUE_H
