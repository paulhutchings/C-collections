//ArrayList "class" that implements the list "interface"
#include "collections.h"
#include <stdlib.h>
#include "list.h"
#include "object.h"
#include "new.h"

typedef List ArrayList;

//Instantiates a new list
List* newList(){
    List* this = new(LIST);
    this->data = malloc(sizeof(void*) * MIN_CAPACITY);
    this->size = 0;
    this->capacity = MIN_CAPACITY;
    return this;
}

//Adds an item to the end of the list
void add(void* list, void* item){
    List* this = (List*)list;
    //reallocate the data array if full
    if (this->size == this->capacity){
        //make the new allocation size 150% of what the current capacity is
        int newCapacity = this->capacity + (this->capacity / 2);
        this->data = realloc(this->data, sizeof(void*) * newCapacity);
        this->capacity = newCapacity;
    }
    this->data[this->size] = item;
}

//Removes and returns the item at the specified index
void* removeAt(void* list, int index){
    List* this = (List*)list;
    if (index >= 0 && index < this->size){
        void* toReturn = this->data[index];
        //shift items in array over
        for(size_t i = index; i < this->size; i++)
        {
            this->data[index] = this->data[index + 1];
        }
        //update last item pointer and list size
        this->data[index] = NULL;

        //check if array is small enough to be downsized. This occurs if the array is less than half full
        if (this->size < this->capacity / 2){
            //downsized capacity is 1/3 less, so that downsizing and upsizing shrink/grow the array by simila amounts
            int newCapacity = this->capacity - (this->capacity / 3);
            this->data = realloc(this->data, sizeof(void*) * newCapacity);
            this->capacity = newCapacity;
        }
        this->size--;
        return toReturn;
    }
    else return NULL;
}

//Removes and returns the specified item from the list
void* remove(void* list, void* item){
    return removeAt(list, indexOf(list, item));
}

//Returns the index of the given item's location in the list, or -1 if the item is not found
int indexOf(void* list, void* item){
    List* this = (List*)list;
    for(size_t i = 0; i < this->size; i++)
    {
        if (isEqual(item, this->data[i])){
            return i;
        }
    }
    return -1;
}

int isEmpty(void* collection){
    return ((List*)collection)->size == 0;
}

//Returns 1 if the list contains the specified item, 0 otherwise
int contains(void* collection, void* item){
    return indexOf(collection, item) == -1;
}

//Returns the item at the specified index without removing it
void* get(void* list, int index){
    List* this = (List*)list;
    if (index >= 0 && index < this->size){
        return this->data[index];
    }
    else return NULL;
}

//Modifies the element in the list at the given index, and returns the item that was previously there
void* set(void* list, int index, void* element){
    List* this = (List*)list;
    if (index >= 0 && index < this->size){
        void* toReturn = this->data[index];
        this->data[index] = element;
        return toReturn;
    }
    else return NULL;
}