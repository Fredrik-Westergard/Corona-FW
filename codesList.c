#include "codesList.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


//function to create codes list
codes* createCodesList(){
    codes* c = (codes*) malloc(sizeof(codes));
    c->length = 0;
    c->head = NULL;
    return c;
}

//function to create code node
struct cnode* createCnode(){
    struct cnode* n = (struct cnode*) malloc(sizeof(struct cnode));
    return n;
}

//function to add code to codes list
void addToCodes(codes* c, unsigned int code){
    struct cnode* n = createCnode();
    n->code = code;
    if(c->head == NULL){
        n->next = NULL; 
    }
    else{
        n->next = c->head;
    }
    c->head = n;
    c->length++;
}

//function to get the next element recursively
struct cnode* getCodeIndexRecursive(struct cnode* n, int index){
    if(index == 0){
        return n;
    }
    return getCodeIndexRecursive(n->next, index-1);
}
//function to get a specific element using getCodeIndexRecursive
struct cnode* getCodeIndex(codes* c, int index){
    return getCodeIndexRecursive(c->head, index);
}
//function to remove item from codes list
void removeFromCodes(codes* c, int index){
    if(c->head != NULL){
        if(index == 0){
            struct cnode* n = c->head;
            c->head = c->head->next;
            free(n);
        }
        else{
            struct cnode* toRemove = getCodeIndex(c,index);
            struct cnode* prev = getCodeIndex(c, index-1);

            prev->next = toRemove->next;
            free(toRemove);
        }
        c->length--;
    }
    else{
        printf("List Error: length is 0\n");
    }
}
//function to destroy codes list
void destroyCodes(codes* c){
    if(c->head == NULL){
        free(c);
        return;
    }
    removeFromCodes(c,0);
    destroyCodes(c);
}
//function to print the codes list using printCnodes()
void printCodesList(codes* c){
    if(c->head != NULL){
        printCnodes(c->head);
    }
}
//function to print code nodes recursively
void printCnodes(struct cnode* n){
    printf("%u\n", n->code);

    if(n->next == NULL){
        return;
    }
    printCnodes(n->next);
}

//function to read code from openingCodes file
bool readCodes(codes* c, int id){
    FILE* f = fopen("openingCodes","r");

    if(f != NULL){
        bool loop = true;
        while(loop){
            char ch;
            unsigned int id2;
            if((ch = fgetc(f)) != EOF){
                ungetc(ch,f);
                unsigned int code;
                fscanf(f,"%u - %u\n",&id2, &code);
                if(id2 == id){
                    addToCodes(c,code);
                }   
            }
            else{
                loop = false;
            }
        }
        fclose(f);
        return true;
    }
    return false;
}

//function to compare codes recursively
bool compareRec(unsigned int toCompare, struct cnode* n){
    if(n == NULL){
        return false;
    }
    if(toCompare == n->code){
        return true;
    }
    return compareRec(toCompare, n->next);
}

//function to compare nodes using compareRec()
bool compareCodes(codes* c, codes* d){
    struct cnode* n = c->head;
    for(int i = 0; i < c->length; i++){
        if(compareRec(n->code, d->head)){
            return true;
        }
        n = n->next;
    }
    return false;
}