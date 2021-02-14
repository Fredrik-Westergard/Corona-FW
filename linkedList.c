#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

//function to create linked list
list* createList(){
    list* l = (list*) malloc(sizeof(list));
    return l;
}
//function to create node
struct node* createNode(){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    return n;
}
//function to add item to list
void addToList(list* l, unsigned int code, date d){
    struct node* n = createNode();
    n->code = code;
    n->d = d;
    if(l->head == NULL){
        n->next = NULL; 
    }
    else{
        n->next = l->head;
    }
    l->head = n;
}
//function to get the next element recursively
struct node* getIndexRecursive(struct node* n, int index){
    if(index == 0){
        return n;
    }
    return getIndexRecursive(n->next, index-1);
}
//function to get a specific element using getIndexRecursive
struct node* getIndex(list* l, int index){
    return getIndexRecursive(l->head, index);
}
//function to remove item from list
void removeFromList(list* l, int index){
    if(l->head != NULL){
        if(index == 0){
            struct node* n = l->head;
            l->head = l->head->next;
            free(n);
        }
        else{
            struct node* toRemove = getIndex(l,index);
            struct node* prev = getIndex(l, index-1);

            prev->next = toRemove->next;
            free(toRemove);
        }
    }
    else{
        printf("List Error: length is 0\n");
    }
}
//function to destroy list
void destroyList(list* l){
    if(l->head == NULL){
        free(l);
        return;
    }
    removeFromList(l,0);
    destroyList(l);
}
//function to print the list using printNodes()
void printList(list* l){
    if(l->head != NULL){
        printNodes(l->head);
    }
}
//function to print nodes recursively
void printNodes(struct node* n){
    printf("%u\t", n->code);
    printDateISO(n->d);
    printf("\n");

    if(n->next == NULL){
        return;
    }
    printNodes(n->next);
} 
//function to get the list length recursively
int getListLengthRec(struct node* n){
    if(n->next == NULL){
        return 0;
    }
    return getListLengthRec(n->next)+1;
}
//function to get the list length using getListLengthRec()
int getListLength(list* l){
    return getListLengthRec(l->head);
}

bool writeData(list* l){

    return false;
}

bool readData(list* l){
    return false;
}