//array-based list implementation
#include <stdlib.h>
#include "list.h"
#include "../object.h"

//Instantiates a new list
List* newList(void* type){
    List* this = malloc(LIST);
    this->data = malloc(sizeof(void*) * MIN_CAPACITY);
    this->size = 0;
    this->capacity = MIN_CAPACITY;
    this->isEqual = type;
    return this;
}

//Adds an item to the end of the list
void add_L(List* list, void* item){
    //reallocate the data array if full
    if (list->size == list->capacity){
        reallocate(list, GROW);
    }
    list->data[list->size] = item;
    list->size++;
}

//Removes and returns the item at the specified index
void* removeAt_L(List* list, int index){
    if (index >= 0 && index < list->size){
        void* toReturn = list->data[index];
        //shift items in array over
        for(size_t i = index; i < list->size; i++)
        {
            list->data[index] = list->data[index + 1];
        }
        //update last item pointer and list size
        list->data[index] = NULL;

        //check if array is small enough to be downsized. This occurs if the array is less than half full
        if (list->size < list->capacity / 2){
            reallocate(list, SHRINK);
        }
        list->size--;
        return toReturn;
    }
    else return NULL;
}

//Removes and returns the specified item from the list
// void* remove(void* list, void* item){
//     return removeAt(list, indexOf(list, item));
// }

//Returns the index of the given item's location in the list, or -1 if the item is not found
int indexOf_L(List* list, void* item){
    for(size_t i = 0; i < list->size; i++)
    {
        if ((list->isEqual)(item, list->data[i])){
            return i;
        }
    }
    return -1;
}

int isEmpty_L(List* list){
    return list->size == 0;
}

// //Returns 1 if the list contains the specified item, 0 otherwise
// int contains(void* collection, void* item){
//     return indexOf(collection, item) == -1;
// }

//Returns the item at the specified index without removing it
void* get_L(List* list, int index){
    if (index >= 0 && index < list->size){
        return list->data[index];
    }
    else return NULL;
}

//Modifies the element in the list at the given index, and returns the item that was previously there
void* set_L(List* list, int index, void* element){
    if (index >= 0 && index < list->size){
        void* toReturn = list->data[index];
        list->data[index] = element;
        return toReturn;
    }
    else return NULL;
}

//grows or shrinks the array based on the provided operation flag
void reallocate(List* list, int operation){
    int newCapacity;
    if (operation == GROW){
        //make the new allocation size 150% of what the current capacity is
        newCapacity = list->capacity * GROW_FACTOR;
    }
    else if (operation == SHRINK){
        //downsized capacity is 1/3 less, so that downsizing and upsizing shrink/grow the array by similar amounts
        newCapacity = list->capacity * SHRINK_FACTOR;
    }
    else return; //not a valid operation flag. Quit early to avoid needlessly calling realloc()    
    list->data = realloc(list->data, sizeof(void *) * newCapacity);
    list->capacity = newCapacity;
}

//deletes the provided list and frees the memory. NOTE - does not delete the item references
void deleteList(List* list){
    free(list->data);
    free(list);
}