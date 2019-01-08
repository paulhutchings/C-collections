//Interface definition for a singley linked list
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
    void *data;
    struct node *next;
} Node;

typedef struct linkedlist {
    Node* head;
    Node* tail;
    int size;
    int (*isEqual)(void* a, void* b); 
} LinkedList;

#define NODE sizeof(Node)
#define LINKEDLIST sizeof(LinkedList)

LinkedList* newLinkedList(void* type);
Node* getNode(LinkedList* list, int index);
void* get_LL(LinkedList* list, int index);
void* set_LL(LinkedList* list, int index, void* item);
void add_LL(LinkedList* list, void* item);
void* removeAt_LL(LinkedList* list, int index);
void deleteLinkedList(LinkedList* list);
int isEmpty_LL(LinkedList* list);

#endif

