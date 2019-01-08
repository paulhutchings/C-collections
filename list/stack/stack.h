#include "../list.h"
#ifndef STACK_H
#define STACK_H

//Stack is a special type of list
typedef List Stack;
#define STACK sizeof(Stack)

Stack* newStack(void* type);
void push(Stack* self, void* item);
void* pop(Stack* self);
void* peek(Stack* self);
void deleteStack(Stack* stack);

#endif