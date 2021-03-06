## HW5_Q6

##### The Question

Implement a stack with a single array. The stack has the operation : push_back, pop_back, size, Isempty

##### My Answer

**STEP1. 規劃TEMPLATE**  
Stack.h :
``` c++
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
```

**STEP2. 實作函式**   
Stack.cpp :

```c++

#include "Stack.h"

template<typename ItemType>
Stack<ItemType>::Stack(int max){
    maxStack = max;
    top = -1;
    item = new ItemType[maxStack];
}

template<typename ItemType>
bool Stack<ItemType>::IsEmpty() const{
    return (top == -1);
}

template<typename ItemType>
bool Stack<ItemType>::IsFull() const{
    return (top == maxStack - 1);
}

template<typename ItemType>
void Stack<ItemType>::Push(ItemType newItem){
    if(IsFull())
        throw FullStack();
    top++;
    item[top] = newItem;
}

template<typename ItemType>
ItemType Stack<ItemType>::Pop(){
    if(IsEmpty())
        throw EmptyStack();
    top--;
    return item[top+1];
}

template<typename ItemType>
ItemType Stack<ItemType>::Size() const{
    return top+1;
}

template<typename ItemType>
Stack<ItemType>::~Stack(){
    delete []item;
}

```
