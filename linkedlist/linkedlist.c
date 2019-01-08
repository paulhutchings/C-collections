//SIngley linked list implementation
#include <stdlib.h>
#include "linkedlist.h"

//Creates a new empty LinkedList 
LinkedList* newLinkedList(void* type){
    LinkedList* this = malloc(sizeof(LinkedList));
    this->size = 0;
    this->head = NULL;
    this->tail = NULL;
    this->isEqual = type;
    return this;
}

//Adds an element to the end of the list
void add_LL(LinkedList* list, void* item){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;

    //If adding first item
    if (list->size == 0){
        list->head = newNode;
        list->tail = list->head;
    }
    else {
        list->tail->next = newNode;
        list->tail = newNode;      
    }
    list->size++;
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
void* removeAt_LL(LinkedList* list, int index){
    if (index >= 0 && index < list->size){
        Node* toRemove =  getNode(list, index);

        //If removing the head
        if (toRemove == list->head){
            list->head = list->head->next;
        }
        //If removing the tail
        else if (toRemove == list->tail){
            list->tail = getNode(list, index - 1);
            list->tail->next = NULL;
        }
        //Removing in the middle
        else {
            Node* before = getNode(list, index - 1);
            before->next = toRemove->next;
            free(before);
        }
        void* toReturn = toRemove->data;
        free(toRemove);
        list->size--;
        return toReturn;
    }
    else return NULL;
}

// //Removes and returns the specified item from the list, or NULL if the item is not found
// void* remove(void* list, void* item){
//     return removeAt(list, indexOf(list, item));
// }

//Returns the index of the first occurance of the specified item in the list, or -1 if the item is not found
// int indexOf(void* list, void* item){
//     LinkedList* this = (LinkedList*)list;    
//     for(size_t i = 0; i < this->size; i++)
//     {
//         Node* temp = getNode(this, i);
//         if (isEqual(item, temp->data)){
//             free(temp);
//             free(this);
//             return i;
//         }
//     }
//     free(this);    
//     return -1;
// }

//returns the item at the index provided, or NULL if index is out of bounds
void* get_LL(LinkedList* list, int index){
    if (index >= 0 && index < list->size){
        return getNode(list, index)->data;
    }
    else return NULL;
}

//replaces the element at the specified index and returns the item that was originally there, or NULL if the index if out of bounds
void* set_LL(LinkedList* list, int index, void* item){
    if (index >= 0 && index < list->size){
        Node* temp = getNode(list, index);
        void* toReturn = temp->data;
        temp->data = item;
        free(temp);
        return toReturn;
    }
    else return NULL;
}

int isEmpty_LL(LinkedList* list){
    return list->size == 0;
}

void deleteLinkedList(LinkedList* list){
    while (list->head != NULL){
        Node* temp = list->head;
        list->head = temp->next;
        free(temp);
    }
    free(list->tail);
    free(list);
}