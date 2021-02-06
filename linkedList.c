#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

list* createList(){
    list* l = (list*) malloc(sizeof(list));
    return l;
}

struct node* createNode(){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    return n;
}

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

struct node* getIndexRecursive(struct node* n, int index){
    if(index == 0){
        return n;
    }
    return getIndexRecursive(n->next, index-1);
}

struct node* getIndex(list* l, int index){
    return getIndexRecursive(l->head, index);
}

void removeFromList(list* l, int index, int length){
    if(length > 0){
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
        printf("List Error: lenght is 0\n");
    }
}

void destroyList(list* l, int length){
    if(length == 0){
        free(l);
        return;
    }
    removeFromList(l, length-1, length);
    destroyList(l, length-1);
}

void printList(struct node* n){

    printf("%u, ", n->code);
    printDateISO(n->d);
    printf("\n");

    if(n->next == NULL){
        return;
    }
    printList(n->next);
}
