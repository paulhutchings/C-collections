#include "../linkedlist/linkedlist.h"
#ifndef QUEUE_H
#define QUEUE_H

typedef LinkedList Queue;
#define QUEUE sizeof(Queue)

Queue* newQueue(void* type);
void offer(Queue* q, void* item);
void* poll(Queue* q);
void* peekQ(Queue* q);

#endif