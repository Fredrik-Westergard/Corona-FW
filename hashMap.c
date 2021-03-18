#include <stdio.h>
#include "hashMap.h"
#include "date.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utilities.h"
#include <limits.h>
#include <errno.h>
#include <math.h>

//function to get a hash
//should work with dates between 1970-01-01 and a distant future date
// may cause errors for grandchildrens grandchildren

unsigned int hash(date d){
    unsigned int toHash = ((d.year*10000)+(d.month*100)+(d.day))-19700000;
    return toHash;
}

//creates item
item* createItem(date d, unsigned int data){
    item* it = (item*) malloc(sizeof(item));
    it->d = d;
    it->data = data;
    it->next = NULL;
    it->prev = NULL;
    return it;
}

//creates hash table
table* createTable(){
    table* t = (table*) malloc(sizeof(table));
    t->items = (item**) malloc(sizeof(item*)*SIZE);

    for(int i = 0; i < SIZE; i++){
        t->items[i] = NULL;
    }

    return t;
}

//finds open space in hashmap
item* findFree(item* it, unsigned int data){
    if(it->next == NULL){
        return it;
    }
    if(it->data < data){
        return findFree(it->next, data);
    }
    return it;
}

//adds item to hashmap
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

//prints items recursively
void printItemsRec(item* it){
    if(it == NULL){
        return;
    }
    
    printf("%u\t", it->data);
    printDateISO(it->d);
    printf("\n");

    printItemsRec(it->next);
}

//prints items
void printItems(table* t){
    for(int i = 0; i < SIZE; i++){
        printItemsRec(t->items[i]);
    }
}

//gets item recursively
item* getItemRec(item* it, unsigned int data){
    if(it == NULL){
        return NULL;
    }
    else if(it->data == data){
        return it;
    }

    return getItemRec(it->next,data);
}

//gets item 
item* getItem(table* t, date d, unsigned int data){
    return getItemRec(t->items[hash(d)], data);
}

//removes item
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

//removes item with item
void removeItemItem(table* t, item* it){
    if(it != NULL){
        item* prv = it->prev;
        item* nxt = it->next;

        if(prv != NULL){
            prv->next = nxt;
        }
        else{
            t->items[hash(it->d)] = nxt;
        }
        if(nxt != NULL){
            nxt->prev = prv;
        }
        free(it);
    }
}

//destroys item 
void destroyItems(table* t, item* it){
    if(it == NULL){
        return;
    }
    removeItem(t, it->d, it->data);
    destroyItems(t, it->next);
}

// destroys hashmap 
void destroyHashMap(table* t){
    for(int i = 0; i < SIZE; i++){
        destroyItems(t, t->items[i]);
        free(t->items[i]);
    }
    free(t);
}

// reads from file to hashmap
bool readToHashMap(table* t, int id){
    char loc[18] = "coronaSaves";
    char str[7];
    sprintf(str,"%d",id);
    strcat(loc, str);
    FILE* f = fopen(loc,"ab+");

    if(f != NULL){
        bool loop = true;
        while(loop){
            unsigned int data;
            date d;
            char fullChar[17];
            char dataChar[7];
            char dateChar[11];
            int read = fread(fullChar,sizeof(char),16,f);
            
            if(read > 0){
                for(int i = 0; i < 6; i++){
                    dataChar[i] = fullChar[i];
                }
                dataChar[6] = '\0';
                for(int i = 6; i < 17; i++){
                    dateChar[i-6] = fullChar[i];
                }
                dateChar[10] = '\0';

                data = parseUser(dataChar);
                if(data != -1){
                    parseDate(&d, dateChar);
                    if(checkDate(d)){
                        addItem(t,d,data);
                    }
                }
            }
            else{
                loop = false;
            }
        }
        removeOld(t);
        fclose(f);
        return true;
    }
    return false;
}

// writes from hashmap to file 
bool writeHashMap(table* t, int id){
    char loc[18] = "coronaSaves";
    char str[7];
    sprintf(str,"%d",id);
    strcat(loc, str);
    FILE* f = fopen(loc, "wb+");

    if(f != NULL){
        removeOld(t);
        for(int i = 0; i < SIZE; i++){
            item* it = t->items[i];
            while(it != NULL){
                char buffer[17];
                sprintf(buffer, "%u%04d-%02d-%02d",it->data, it->d.year, it->d.month, it->d.day);
                fwrite(buffer,sizeof(char),16,f);
                it = it->next;
            }
        }
        fclose(f);
        return true;
    }

    return false;
}

//function to remove old phones recursively
void removeOldRec(table* t, item* it, date tooOld){
    if(it == NULL){
        return;
    }
    if(compareDates(tooOld, it->d) > 0){
        removeItemItem(t,it);
    }
    removeOldRec(t, it->next, tooOld);
}
//function to remove old phones using removeOldRecursive()
void removeOld(table* t){
    for(int i = 0; i<SIZE; i++){
        if(t->items[i] != NULL){
            removeOldRec(t, t->items[i], getDateNumBefore(getTodaysDate(),21));
        }
    }
}

//function to get the user id from command line arguments
//function modified from stackoverflow
unsigned int parseUser(char* toParse){
    char *c; //character pointer used by strtol
    
    errno = 0; //used for errorchecking, sometimes gives errors in vsCode?
    long conv = strtol(toParse, &c, 10); //converts string to long
    // Check for errors: e.g., the string does not represent an integer
    // or the integer is larger than int
    if (errno != 0 || *c != '\0' || conv > INT_MAX || floor(log10(abs(conv)))+1 != 6 || conv < 0) {
        return -1;
    } else {
        unsigned int user = (unsigned int) conv; //convert long to int   
        return user;
    }
}



