//Set interface for a collection of distinct elements
#ifndef SET_H
#define SET_H

typedef struct list Set;
extern const size_t SET = sizeof(Set);

Set* newSet();
int put(Set* s, void* item);
Set* union(Set* a, Set* b);
Set* intersect(Set* a, Set* b);
Set* isSubset(Set* a, Set* b);

#endif