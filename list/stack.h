#ifndef STACK_H
#define STACK_H

typedef struct list Stack;
extern const size_t STACK = sizeof(List);

Stack* newStack();
void push(Stack* self, const void* item);
void* pop(Stack* self);
void* peek(Stack* self);

#endif