//LinkedList "class" that implements the list interface through a single linked list
#include "collections.h"
#include "list.h"
#include "linkedlist.h"
#include "new.h"
#include "object.h"
#include <stdlib.h>

//Creates a new empty LinkedList 
LinkedList* newLinkedList(){
    LinkedList* this = new(LINKEDLIST);
    this->size = 0;
    this->head = NULL;
    this->tail = NULL;
    return this;
}

//Adds an element to the end of the list
void add(void* list, void* item){
    LinkedList* this = (LinkedList*)list;
    Node* newNode = new(NODE);
    newNode->data = item;
    newNode->next = NULL;

    //If adding first item
    if (this->size == 0){
        this->head = newNode;
        this->tail = this->head;
    }
    else {
        this->tail->next = newNode;
        this->tail = newNode;      
    }
    this->size++;
}

//Returns the node at the specified index, or NULL if outside the bounds of the list size
Node* getNode(LinkedList* list, int index){
    Node* temp = list->head;
    int count = 0;
    while (temp != NULL){
        if (count == index){
            return temp;
        }
        count++;
        temp = temp->next;
    }
    free(temp);
    return NULL;
}

//Removes and returns the item at the given index, or NULL if index is outside bounds of the list size
void* removeAt(void* list, int index){
    LinkedList* this = (LinkedList*)list;
    if (index >= 0 && index < this->size){
        Node* toRemove =  getNode(this, index);

        //If removing the head
        if (toRemove == this->head){
            this->head = this->head->next;
        }
        //If removing the tail
        else if (toRemove == this->tail){
            this->tail = getNode(this, index - 1);
            this->tail->next = NULL;
        }
        //Removing in the middle
        else {
            Node* before = getNode(this, index - 1);
            before->next = toRemove->next;
            free(before);
        }
        void* toReturn = toRemove->data;
        free(toRemove);
        free(this);
        return toReturn;
    }
    free(this);
    return NULL;
}

//Removes and returns the specified item from the list, or NULL if the item is not found
void* remove(void* list, void* item){
    return removeAt(list, indexOf(list, item));
}

//Returns the index of the first occurance of the specified item in the list, or -1 if the item is not found
int indexOf(void* list, void* item){
    LinkedList* this = (LinkedList*)list;    
    for(size_t i = 0; i < this->size; i++)
    {
        Node* temp = getNode(this, i);
        if (isEqual(item, temp->data)){
            free(temp);
            free(this);
            return i;
        }
    }
    free(this);    
    return -1;
}

//returns the item at the index provided, or NULL if index is out of bounds
void* get(void* list, int index){
    LinkedList* this = (LinkedList*)list;
    if (index >= 0 && index < this->size){
        return getNode(this, index)->data;
    }
    free(this);
    return NULL;
}

//replaces the element at the specified index and returns the item that was originally there, or NULL if the index if out of bounds
void* set(void* list, int index, void* element){
    LinkedList* this = (LinkedList*)list;
    if (index >= 0 && index < this->size){
        Node* temp = getNode(this, index);
        void* toReturn = temp->data;
        temp->data = element;
        free(temp);
        free(this);
        return toReturn;
    }
    free(this);
    return NULL;
}

int isEmpty(void* collection){
    return ((LinkedList*)collection)->size == 0;
}

int contains(void* collection, void* item){
    return indexOf(collection, item) == -1;
}