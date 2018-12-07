//a List interface, providing function definitions for operations universally available for all lists
#ifndef LIST_H
#define LIST_H

//the initial size when making a new list and the smallest it will shrink to
extern const int MIN_CAPACITY = 10;

//passed to the general new() function defined in new.h
extern const size_t LIST = sizeof(List);

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
int add(List* list, void* item);
void* remove(List* list, void* item);
void* removeAt(List* list, int index);
void* get(List* list, int index);
void* set(List* list, int index, void* element);
int indexOf(List* list, void* item);

#endif