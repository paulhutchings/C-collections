#include <stdlib.h>
#include <stdio.h>
#include "object.h"
#include "list/list.h"
#include "list/stack/stack.h"

int main(){
    Stack* stack = newStack(&INTEGER);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    int* top = (int*)peek(stack);
    printf("%d\n", *top);
    // pop(stack);
    // top = pop(stack);
    // printf("%d\n", *top);

    return 0;
}
