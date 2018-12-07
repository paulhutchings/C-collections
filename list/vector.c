//Vector "class" that implements the list "interface" as defined in list.h
#include "vector.h"
#include "collections.h"
#include <stdlib.h>
#include "list.h"
#include "object.h"

Vector* newVector(){
    Vector* this = new(VECTOR);
    this->data = malloc(sizeof(void*) * MIN_CAPACITY);
    this->size = 0;
    this->capacity = MIN_CAPACITY;
    return this;
}

int add(void* list, void* item){
    Vector* self = list;
    //reallocate the data array if full
    if (self->size == self->capacity){
        //make the new allocation size 150% of what the current capacity is
        int newCapacity = self->capacity + (self->capacity / 2);
        self->data = realloc(self->data, sizeof(void*) * newCapacity);
        self->capacity = newCapacity;
    }

    self->data[self->size] = item;
}

void* removeAt(void* list, int index){

}

void* remove(void* list, void* item){
    return removeAt(list, indexOf(list, item));
}

int indexOf(void* list, void* item){
    Vector* self = list;
    void** data = self->data;
    for(size_t i = 0; i < self->size; i++)
    {
        if (isEqual(item, data[i])){
            return i;
        }
    }
    return -1;
}