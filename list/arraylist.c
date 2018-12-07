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
int add(List* list, void* item){
    //reallocate the data array if full
    if (list->size == list->capacity){
        //make the new allocation size 150% of what the current capacity is
        int newCapacity = list->capacity + (list->capacity / 2);
        list->data = realloc(list->data, sizeof(void*) * newCapacity);
        list->capacity = newCapacity;
    }
    list->data[list->size] = item;
}

//Removes and returns the item at the specified index
void* removeAt(List* list, int index){
    if (index >= 0 && index < list->size){
        void* toReturn = list->data[index];
        //shift items in array over
        for(size_t i = index; i < list->size; i++)
        {
            list->data[index] = list->data[index + 1];
        }
        //update last item pointer and list size
        list->data[index] = NULL;
        list->size--;

        //check if array is small enough to be downsized. This occurs if the array is less than half full
        if (list->size < list->capacity / 2){
            //downsized capacity is 1/3 less, so that downsizing and upsizing shrink/grow the array by simila amounts
            int newCapacity = list->capacity - (list->capacity / 3);
            list->data = realloc(list->data, sizeof(void*) * newCapacity);
            list->capacity = newCapacity;
        }
        return toReturn;
    }
    else return NULL;
}

//Removes and returns the specified item from the list
void* remove(List* list, void* item){
    return removeAt(list, indexOf(list, item));
}

//Returns the index of the given item's location in the list, or -1 if the item is not found
int indexOf(List* list, void* item){
    for(size_t i = 0; i < list->size; i++)
    {
        if (isEqual(item, list->data[i])){
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
    return indexOf((List*)collection, item) == -1;
}

//Returns the item at the specified index without removing it
void* get(List* list, int index){
    if (index >= 0 && index < list->size){
        return list->data[index];
    }
    else return NULL;
}

//Modifies the element in the list at the given index, and returns the item that was previously there
void* set(List* list, int index, void* element){
    if (index >= 0 && index < list->size){
        void* toReturn = list->data[index];
        list->data[index] = element;
        return toReturn;
    }
    else return NULL;
}