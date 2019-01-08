//Queue "class" based on the Linked List implementation
#include "queue.h"
#include "../linkedlist/linkedlist.h"

//Creates a new empty queue
Queue* newQueue(void* type){
    return (Queue*)newLinkedList(type);
}

//Adds an item to the end of the queue
void offer(Queue* q, void* item){
    add_LL(q, item);
}

//removes the item at the front of the queue
void* poll(Queue* q){
    return removeAt_LL(q, 0);
}

//returns the next item in the front of the queue without removing it
void* peekQ(Queue* q){
    return get_LL(q, 0);
}