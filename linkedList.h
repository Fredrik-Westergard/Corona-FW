#ifndef LINKEDLIST_H__
#define LINKEDLIST_H__

#include "date.h"

/**
 * node structure
 */
struct node{
    unsigned int code;  /** the code */
    date d;             /** the date */
    struct node* next;  /** the link to the next node */
};

/**
 * list structure
 */
typedef struct{
    struct node* head;  /** the link to the first node in the list */
    int length;
}list;

/**
 * function to create list
 * @returns the new list
 */
list* createList();

/**
 * function to create node
 * @returns the new node
 */
struct node* createNode();

/**
 * function to add new node to list
 * @param l the list to add to
 * @param code the code to add
 * @param d the date to add
 */
void addToList(list* l, unsigned int code, date d);

/**
 * function to get node recursively
 * @param n a node to check
 * @param index the index to check
 * @returns the wanted node
 */
struct node* getIndexRecursive(struct node* n, int index);

/**
 * function to get a certain node using getIndexRecursively
 * @param l the list
 * @param the index of the wanted node
 * @returns the wanted node
 */
struct node* getIndex(list* l, int index);

/**
 * function to remove item from list
 * @param l the list
 * @param index the index of the node to be removed
 */
void removeFromList(list* l, int index);

/**
 * functio nto destroy list
 * @param l the list to be destroyed
 */
void destroyList(list* l);

/**
 * function to print the items in the list using printNodes
 * @param l the list to print
 */
void printList(list* l);

/**
 * function to print the nodes in a list
 * @param n the node to print
 */
void printNodes(struct node* n);

bool writeData(list* l);

bool readData(list* l);

/**
 * function to remove old phones recursively
 * @param l a linked list
 * @param n a node in the list
 * @param tooOld the date to compare to
 * @param index the index it's looking at at the moment
 */
void removeOldRecursive(list* l, struct node* n, date tooOld, int index);

/**
 * function to remove old phones using removeOldRecursive
 * @param l the linked list
 */
void removeTooOld(list* l);

#endif