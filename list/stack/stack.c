//A stack implementation, featuring push, pop, and peek functions
#include <stdlib.h>
#include "stack.h"
#include "../list.h"

Stack* newStack(void* type){
    return (Stack*)newList(type);
}

void push(Stack* stack, void* item){
    add(stack, item);
}

void* pop(Stack* stack){
    return removeAt(stack, stack->size - 1);
}

void* peek(Stack* stack){
    return get(stack, stack->size - 1);
}

void deleteStack(Stack* stack){
    deleteList((List*)stack);
}
