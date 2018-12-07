//Stack "class", a subset of the list featuring the push, pop, and peek operations
#include "stack.h"
#include "list.h"

typedef List Stack;

Stack* newStack(){
    return newList();
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