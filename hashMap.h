#ifndef HASHMAP_H__
#define HASHMAP_H__

#include "date.h"
#include <stdbool.h>

#define SIZE 10000000

typedef struct item{
    date d;
    unsigned int data;
    struct item* next;
    struct item* prev;
}item;

typedef struct{
    item** items;
}table;

unsigned int hash(date d);

item* createItem(date d, unsigned int data);

table* createTable();

item* findFree(item* it, unsigned int data);

void addItem(table* t, date d, unsigned int data);

void printItemsRec(item* it);

void printItems(table* t);

item* getItemRec(item* it, unsigned int data);

item* getItem(table* t, date d, unsigned int data);

void removeItem(table* t, date d, unsigned int data);

void removeItemItem(table* t, item* it);

void destroyItems(table* t, item* it);

void destroyHashMap(table* t);

bool readToHashMap(table* t, int id);

bool writeToHashMap(table* t, int id);

void removeOldRec(table* t, item* it, date tooOld);

void removeOld(table* t);

#endif