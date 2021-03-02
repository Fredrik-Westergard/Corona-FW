#include <stdio.h>
#include "linkedList.h"
#include "date.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//function to create linked list
list* createList(){
    list* l = (list*) malloc(sizeof(list));
    l->length = 0;
    l->head = NULL;
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
    l->length++;
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
        l->length--;
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

//function to write list to file
bool writeData(list* l, int id){
    char loc[18] = "coronaSaves";
    char str[7];
    sprintf(str,"%d",id);
    strcat(loc, str);
    FILE* f = fopen(loc, "wb+");

    if(f != NULL){
        removeTooOld(l);
        struct node* n = l->head;
        for(int i = 0; i < l->length; i++){
            fprintf(f, "%d, %d-%d-%d\n", n->code, n->d.year, n->d.month, n->d.day);
            n = n->next;
        }
        fclose(f);
        return true;
    }

    return false;
}

//function to read list from file
bool readData(list* l, int id){
    char loc[18] = "coronaSaves";
    char str[7];
    sprintf(str,"%d",id);
    strcat(loc, str);
    FILE* f = fopen(loc,"ab+");

    if(f != NULL){
        bool loop = true;
        while(loop){
            if(!feof(f)){
                unsigned int code;
                date d;
                fscanf(f,"%u, %d-%d-%d\n",&code,&d.year,&d.month,&d.day);
                addToList(l,code,d);
            }
            else{
                loop = false;
            }
        }
        removeTooOld(l);
        fclose(f);
        return true;
    }
    return false;
}

//function to remove old phones recursively
void removeOldRecursive(list* l, struct node* n, date tooOld, int index){
    if(n == NULL){
        return;
    }
    int i = 1;
    if(compareDates(tooOld, n->d) > 0){
        removeFromList(l, index);
        i--;
    }
    removeOldRecursive(l,n->next, getDateNumBefore(getTodaysDate(),21), index+i);
}
//function to remove old phones using removeOldRecursive()
void removeTooOld(list* l){
    if(l->head != NULL){
        removeOldRecursive(l,l->head, getDateNumBefore(getTodaysDate(),21), 0);
    }
}