#ifndef STACK_H
#define STACK_H

extern const int STACK = sizeof(List);

Stack* newStack();
void push(struct stack* self, const void* item);
void* pop(struct stack *self);
void* peek(struct stack *self);

#endif