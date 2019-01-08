//array-based list implementation
#include <stdlib.h>
#include "../collections.h"
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
void add(void* list, void* item){
    List* this = (List*)list;
    //reallocate the data array if full
    if (this->size == this->capacity){
        reallocate(this, GROW);
    }
    this->data[this->size] = item;
    this->size++;
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
            reallocate(this, SHRINK);
        }
        this->size--;
        return toReturn;
    }
    else return NULL;
}

//Removes and returns the specified item from the list
// void* remove(void* list, void* item){
//     return removeAt(list, indexOf(list, item));
// }

//Returns the index of the given item's location in the list, or -1 if the item is not found
int indexOf(void* list, void* item){
    List* this = (List*)list;
    for(size_t i = 0; i < this->size; i++)
    {
        if ((this->isEqual)(item, this->data[i])){
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
    free(&list->size);
    free(&list->capacity);
    free(list);
}