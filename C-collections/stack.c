#include "collections.h"
#include "object.h"
#include "new.h"
#include "stack.h"
#include <stdlib.h>
#include "vector.h"

Stack* newStack(){
    return newVector();
}

void push(Stack* self, void* item){
    add(self, item);
}

void* pop(Stack* self){
    
}

void* peek(Stack* self){
    
}



