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
