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

void addToList(list* l, int code, date d){
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

void removeFromList(list* l, int index){

}

void destroyList(list* l){

}