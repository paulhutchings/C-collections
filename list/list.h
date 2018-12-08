//a List interface, providing function definitions for operations universally available for all lists
#ifndef LIST_H
#define LIST_H

//passed to the general new() function defined in new.h
extern const size_t LIST = sizeof(List);

//the initial size when making a new list and the smallest it will shrink to
extern const int MIN_CAPACITY = 10;

//The base format for list-based collections. 
//data - a resizable array (both increasing and decreasing) to hold items
//size - number of items in the data array
//capacity - max number of items that the data array can hold
typedef struct list {
    void** data;
    int size;
    int capacity;
} List;

List* newList();
void add(void* list, void* item);
void* remove(void* list, void* item);
void* removeAt(void* list, int index);
void* get(void* list, int index);
void* set(void* list, int index, void* element);
int indexOf(void* list, void* item);

#endif