// listQ.cpp - implements queue as linked list
// Qi Guo, 11/15/2018

#include "listQ.h"

Queue::Queue() {front = nullptr; rear = nullptr; size =0;}  

Queue::~Queue() {
    while(front != nullptr){
        node *deletednode = front;
        //front -> data = NULL;
        front = front -> next; 
        delete deletednode;
        rear = nullptr;
    }
    size = 0;
}

void Queue::enqueue(int n) {
    node *newnode = new node(n);
    if(isEmpty()){
        front = newnode;
        rear = newnode;
        size++;
    }
    else{
        rear -> next = newnode;
        rear = newnode;
        size++;
    }
}

int Queue::dequeue() {
    if (isEmpty())
        throw EmptyQueue();
    node *deletednode = front;
    int value = front -> data;
    front -> data = 0;
    front = front -> next;
    delete deletednode;
    size--;
    if (isEmpty())
        rear = nullptr;
    return value; 
}

void Queue::clear() {
     while(front != nullptr){
        node *deletednode = front;
        //front -> data = NULL;
        front = front -> next; 
        delete deletednode;
        rear = nullptr;
    }
    size = 0;
   
}

bool Queue::isEmpty() const {
    if(size == 0)
        return true; 
    else
        return false;
}

int Queue::getSize() const {
    return size;
}
