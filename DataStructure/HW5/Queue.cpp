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
