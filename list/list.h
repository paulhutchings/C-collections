//a List interface, providing function definitions for operations universally available for all lists
#ifndef LIST_H
#define LIST_H

extern const int MIN_CAPACITY = 10;

int add(void* list, void* item);
void* remove(void* list, void* item);
void* removeAt(void* list, int index);
void* get(void* list, int index);
void* set(void* list, int index, void* element);
int indexOf(void* list, void* item);

#endif