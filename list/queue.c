#include "queue.h"
#include "list.h"
#include "linkedlist.h"
#include "new.h"

typedef LinkedList Queue;

//Creates a new empty queue
Queue* newQueue(){
    return newLinkedList();
}

//Adds an item to the end of the queue

//removes the item at the front of the queue
void* poll(Queue* q){
    return removeAt(q, 0);
    // Node* toRemove = q->head;
    // void* toReturn = toRemove->data;
    // q->head = q->head->next;
    // free(toRemove);
    // q->size--;
    // return toReturn;
}

//returns the next item in the front of the queue without removing it
void* peek(Queue* q){
    return get(q, 0);
}