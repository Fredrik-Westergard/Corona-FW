#ifndef HASHMAP_H__
#define HASHMAP_H__

#include "date.h"

#define SIZE 131072

typedef struct item{
    date d;
    unsigned int data;
    struct item* next;
}item;

typedef struct{
    item** items;
}table;

unsigned int hash(date d);

item* createItem(date d, unsigned int data);

table* createTable();

item* findFree(item* it);

void addItem(table* t, date d, unsigned int data);

#endif