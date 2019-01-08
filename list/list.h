//a List interface for an array-based list
#ifndef LIST_H
#define LIST_H

//the initial size when making a new list and the smallest it will shrink to
#define MIN_CAPACITY 10

#define GROW_FACTOR 1.5
#define SHRINK_FACTOR 0.67

#define GROW 1
#define SHRINK 0

//The base format for list-based collections. 
//data - a resizable array (both increasing and decreasing) to hold items
//size - number of items in the data array
//capacity - max number of items that the data array can hold
//isEqual - function used to compare the data type stored in the list
typedef struct list {
    void** data;
    int size;
    int capacity;
    int (*isEqual)(void* a, void* b); 
} List;

//passed to the general new() function defined in new.h
#define LIST sizeof(List)

List* newList(void* type);
void add(void* list, void* item);
// void* remove(void* list, void* item);
void* removeAt(void* list, int index);
void* get(void* list, int index);
void* set(void* list, int index, void* element);
int indexOf(void* list, void* item);
void reallocate(List* list, int operation);
void deleteList(List* list);

#endif