## HW5_Q7

##### The Question

Implement a queue with a single array. The queue has the operation : push_back, pop_front, size, Isempty

##### My Answer

**STEP1. 規劃TEMPLATE**  
Queue.h :
``` c++
#ifndef _QUEUE_H_
#define _QUEUE_H_

class FullQueue{};
class EmptyQueue{};

template<typename ItemType>
class Queue
{
    public:
    Queue(int max);
    /*
     * Function: constructor
     * Precondition: none
     * Postcondition: Queue has been initialized
     */

    bool IsEmpty() const;
    /*
     * Function: Determines whether the queue is empty
     * Precondition: Queue has been initialized
     * Postcondition: Function value = (queue is empty)
     */

    bool IsFull() const;
    /*
     * Function: Determines whether the queue is full
     * Precondition: Queue has been initialized
     * Postcondition: Function value = (queue is full)
     */

    void Push(ItemType item);
    /*
     * Function: Add new item to the top of the queue
     * Precondition: Queue has been initialized
     * Postcondition: If (queue is full), exception FullQueue is thrown,
     *                else new item is at the top of the queue
     */

     ItemType Pop();
    /*
     * Function: Get and remove first item from the queue
     * Precondition: Queue has been initialized
     * Postcondition: If (queue is empty), exception EmptyQueue is thrown,
     *                else first item has been removed from queue
     */

    ItemType Size() const;
    /*
     * Function: Returns amounts of the items in the queue
     * Precondition: Queue has been initialized
     * Postcondition: None
     */

    ~Queue(void);
    /*
     * Function: destructor
     * Precondition: Queue has been initailized
     * Postcondition: deallocate memory
     */

private:
    int maxQueue;
    ItemType* item;
    int top;
};
```

**STEP2. 實作函式**   
Queue.cpp :

```c++

#include "Queue.h"

template<typename ItemType>
Queue<ItemType>::Queue(int max){
    maxQueue = max;
    top = -1;
    item = new ItemType[maxQueue];
}

template<typename ItemType>
bool Queue<ItemType>::IsEmpty() const{
    return (top == -1);
}

template<typename ItemType>
bool Queue<ItemType>::IsFull() const{
    return (top == maxQueue - 1);
}

template<typename ItemType>
void Queue<ItemType>::Push(ItemType newItem){
    if(IsFull())
        throw FullQueue();
    top++;
    item[top] = newItem;
}

template<typename ItemType>
PopItem Queue<ItemType>::Pop(){
    if(IsEmpty())
        throw EmptyQueue();
    top--;
    ItemType PopItem = item[0];
    for (int i = 0; i < top; i++) {
        item[i] = item[i+1];
    }
    return PopItem;
}

template<typename ItemType>
ItemType Queue<ItemType>::Size() const{
    return top+1;
}

template<typename ItemType>
Queue<ItemType>::~Queue(){
    delete []item;
}

```
