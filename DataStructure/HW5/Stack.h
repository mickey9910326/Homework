#ifndef _STACK_H_
#define _STACK_H_

class FullStack{};
class EmptyStack{};

template<typename ItemType>
class Stack
{
    public:
    Stack(int max);
    /*
     * Function: constructor
     * Precondition: none
     * Postcondition: Stack has been initialized
     */

    bool IsEmpty() const;
    /*
     * Function: Determines whether the stack is empty
     * Precondition: Stack has been initialized
     * Postcondition: Function value = (stack is empty)
     */

    bool IsFull() const;
    /*
     * Function: Determines whether the stack is full
     * Precondition: Stack has been initialized
     * Postcondition: Function value = (stack is full)
     */

    void Push(ItemType item);
    /*
     * Function: Add new item to the top of the stack
     * Precondition: Stack has been initialized
     * Postcondition: If (stack is full), exception FullStack is thrown,
     *                else new item is at the top of the stack
     */

    ItemType Pop();
    /*
     * Function: Remove top item from the stack
     * Precondition: Stack has been initialized
     * Postcondition: If (stack is empty), exception EmptyStack is thrown,
     *                else top item has been removed from stack
     */

    ItemType Size() const;
    /*
     * Function: Returns amounts of the items in the stack
     * Precondition: Stack has been initialized
     * Postcondition: None
     */

    ~Stack(void);
    /*
     * Function: destructor
     * Precondition: Stack has been initailized
     * Postcondition: deallocate memory
     */

private:
    int maxStack;
    ItemType* item;
    int top;
};
