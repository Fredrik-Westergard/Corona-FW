#ifndef LINKEDLIST_H__
#define LINKEDLIST_H__

#include "date.h"

struct node{
    int code;
    date d;
    struct node* next;
};

typedef struct{
    struct node* head;
}list;

list* createList();

struct node* createNode();

void addToList(list* l);

struct node* getIndexRecursive(struct node* n, int index)

struct node* getIndex(list* l, int index);

void removeFromList(list* l, int index);

void destroyList(list* l);

#endif