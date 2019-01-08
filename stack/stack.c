//A stack implementation, featuring push, pop, and peek functions
#include <stdlib.h>
#include "stack.h"
#include "../list/list.h"

Stack* newStack(void* type){
    return (Stack*)newList(type);
}

void push(Stack* stack, void* item){
    add_L(stack, item);
}

void* pop(Stack* stack){
    return removeAt_L(stack, stack->size - 1);
}

void* peek(Stack* stack){
    return get_L(stack, stack->size - 1);
}

void deleteStack(Stack* stack){
    deleteList((List*)stack);
}
