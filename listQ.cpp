// listQ.cpp - implements queue as linked list
// Qi Guo, 11/15/2018

#include "listQ.h"
#include <cassert>

template <class Item>
Queue<Item>::Queue() {front = nullptr; rear = nullptr; size =0;}  

template <class Item>
Queue<Item>::~Queue() {
    while(front != nullptr){
        node *deletednode = front;
        //front -> data = NULL;
        front = front -> next; 
        delete deletednode;
        rear = nullptr;
    }
    size = 0;
}

template <class Item>
void Queue<Item>::enqueue(const Item& n) {
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

template<class Item>
void Queue<Item>::dequeue() {
    node *deletednode = front;
    Item value = front -> data;
    front -> data = 0;
    front = front -> next;
    delete deletednode;
    size--;
    if (isEmpty())
        rear = nullptr; 
}

template<class Item>
bool Queue<Item>::isEmpty() const {
    if(size == 0)
        return true; 
    else
        return false;
}

template<class Item>
int Queue<Item>::getSize() const {
    return size;
}

template<class Item>
Item Queue <Item>::qfront() const{
    assert(!isEmpty());
    return front -> data;
}
