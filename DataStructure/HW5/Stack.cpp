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
