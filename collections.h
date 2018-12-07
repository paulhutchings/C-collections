#ifndef COLLECTIONS_H
#define COLLECTIONS_H

extern const int NODE = sizeof(Node);

typedef struct node {
    void *data;
    struct node *next;
} Node;

int isEmpty(const void* collection);
int contains(const void* collection, void* item);

#endif