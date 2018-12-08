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
void add(void* list, void* item){
    Queue* this = (Queue*)list;
    Node* end = new(NODE);
    end->data = item;
    end->next = NULL;
    
}