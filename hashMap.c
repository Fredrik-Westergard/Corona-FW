#include <stdio.h>
#include "hashMap.h"
#include "date.h"
#include <stdlib.h>

unsigned int hash(date d){
    unsigned int toHash = ((d.year*10000)+(d.month*100)+(d.day))-19700000;
    return toHash;
}

item* createItem(date d, unsigned int data){
    item* it = (item*) malloc(sizeof(item));
    it->d = d;
    it->data = data;
    it->next = NULL;
    it->prev = NULL;
    return it;
}

table* createTable(){
    table* t = (table*) malloc(sizeof(table));
    t->items = (item**) malloc(sizeof(item*)*SIZE);

    for(int i = 0; i < SIZE; i++){
        t->items[i] = NULL;
    }

    return t;
}

item* findFree(item* it, unsigned int data){
    if(it->next == NULL){
        return it;
    }
    if(it->data < data){
        return findFree(it->next, data);
    }
    return it;
}

void addItem(table* t, date d, unsigned int data){
    unsigned int hashed = hash(d);
    item* it = createItem(d,data);

    if(t->items[hashed] == NULL){
        t->items[hashed] = it;
    }
    else{
        item* nxt = findFree(t->items[hashed],data);
        item* prv = nxt->prev;
        if(prv != NULL){
            prv->next = it;
        }
        else{
            t->items[hashed] = it;
        }
        if(nxt != NULL){
            nxt->prev = it;
        }        
        it->prev = prv;
        it->next = nxt;
    }
}

void printItemsRec(item* it){
    if(it == NULL){
        return;
    }
    printDateISO(it->d);
    printf(" %u\n", it->data);

    printItemsRec(it->next);
}

void printItems(table* t){
    for(int i = 0; i < SIZE; i++){
        printItemsRec(t->items[i]);
    }
}

item* getItemRec(item* it, unsigned int data){
    if(it == NULL){
        return NULL;
    }
    else if(it->data == data){
        return it;
    }

    return getItemRec(it->next,data);
}

item* getItem(table* t, date d, unsigned int data){
    return getItemRec(t->items[hash(d)], data);
}

void removeItem(table* t, date d, unsigned int data){
    item* it = getItem(t, d, data);

    if(it != NULL){
        item* prv = it->prev;
        item* nxt = it->next;

        if(prv != NULL){
            prv->next = nxt;
        }
        else{
            t->items[hash(d)] = nxt;
        }
        if(nxt != NULL){
            nxt->prev = prv;
        }
        free(it);
    }
}

void destroyItems(table* t, item* it){
    if(it == NULL){
        return;
    }
    destroyItems(t, it->next);
    removeItem(t, it->d, it->data);
}

void destroyHashMap(table* t){
    for(int i = 0; i < SIZE; i++){
        destroyItems(t, t->items[i]);
        free(t->items[i]);
    }
    free(t);
}



