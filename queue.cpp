#include <cassert>
#include "node2.h"

template <class Item>
void queue<Item>::enq(const Item& entry)
{
    // add node to the rear of the queue
  if(sizeq() == 0){
      list_head_insert(front, entry);
  }
  else{
      list_insert(rear, entry);
  }
  size++;
    
}

template <class Item>
void queue<Item>::deq()
{
  // check if queue is empty
  assert(!empty());   
 
  // remove node from the top of the queue
  list_head_remove(front);
  size--;
}

template <class Item>
Item queue<Item>::qfront() const
{
  // check queue not empty
  assert(!empty());
  // return the top element
  return front->data();
}


