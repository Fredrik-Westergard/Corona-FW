#ifndef LINKEDLIST_H__
#define LINKEDLIST_H__

#include "date.h"

struct node{
    unsigned int code;
    date d;
    struct node* next;
};

typedef struct{
    struct node* head;
}list;

list* createList();

struct node* createNode();

void addToList(list* l, unsigned int code, date d);

struct node* getIndexRecursive(struct node* n, int index);

struct node* getIndex(list* l, int index);

void removeFromList(list* l, int index, int length);

void destroyList(list* l, int length);

void printList(list* l);

void printNodes(struct node* n);

#endif