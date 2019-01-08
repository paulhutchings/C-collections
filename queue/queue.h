#ifndef QUEUE_H
#define QUEUE_H

typedef struct linkedlist Queue;
extern const size_t QUEUE = sizeof(Queue);

Queue* newQueue();
void* poll(Queue* q);
void* peek(Queue* q);

#endif