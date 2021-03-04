#include <stdio.h>
#include "hashMap.h"
#include "date.h"
#include <stdlib.h>

unsigned int hash(date d){
    unsigned int toHash = ((d.year*10000)+(d.month*100)+(d.day))-19700101;
    return toHash % SIZE;
}

item* createItem(date d, unsigned int data){
    item* it = (item*) malloc(sizeof(item));
    it->d = d;
    it->data = data;
    it->next = NULL;
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

item* findFree(item* it){
    if(it == NULL){
        return it;
    }
    return findFree(it->next);
}

void addItem(table* t, date d, unsigned int data){
    unsigned int hashed = hash(d);
    item* it = createItem(d,data);

    if(t->items[hashed] == NULL){
        t->items[hashed] = it;
    }
    else{
        item* prev = findFree(t->items[hashed]->next);
        prev->next = it;
    }
}
