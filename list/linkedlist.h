//Interface definition for a singley linked list
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

extern const size_t NODE = sizeof(Node);
extern const size_t LINKEDLIST = sizeof(LinkedList);

typedef struct node {
    void *data;
    struct node *next;
} Node;

typedef struct linkedlist {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

LinkedList* newLinkedList();
Node* getNode(LinkedList* list, int index);

#endif

