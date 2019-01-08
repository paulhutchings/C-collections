//Set "class", implemented using the ArrayList
#include "set.h"
#include "list/list.h"
#include "collections.h"
#include <stdlib.h>

Set* newSet(){
    return newList();
}

//returns 1 if the item was added to the set, otherwise 0 if the set already contains the item
int put(Set* s, void* item){
    if (!contains(s, item)){
        add(s, item);
    }
    else return 0;
}

//removes and returns the specified element from the set, or NULL if the item does not exist in the set
void* remove(void* list, void* item){
    if (contains(list, item)){
        Set* this = (Set*)list;
        //since order does not matter in sets, simply swap the item at the index to be removed with the last item, then set the last item to NULL
        void* toReturn = set(list, indexOf(list, item), this->data[this->size - 1]);
        set(list, this->size - 1, NULL);
        this->size--;
        if (this->size < this->capacity / 2){
            reallocate(this, SHRINK);
        }
        free(this);
        return toReturn;
    }
    else return NULL;
}