#ifndef QUEUE_H
#define QUEUE_H

typedef struct linkedlist Queue;
extern const size_t QUEUE = sizeof(LinkedList);

Queue* newQueue();
void* poll(LinkedList* list);

#endif