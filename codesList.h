#ifndef CODESLIST_H__
#define CODESLIST_H__

#include <stdbool.h>


/**
 * cnode structure
 */
struct cnode{
    unsigned int code;
    struct cnode* next;
};

/**
 * codes list structure
 */
typedef struct{
    struct cnode* head;
    int length;
}codes;

/**
 * function to create codes List
 * @returns a pointer to a list for codes
 */
codes* createCodesList();

/**
 * function to create cnode
 * @returns a pointer to a cnode
 */
struct cnode* createCnode();

/**
 * function to add codes to list
 * @param c the codes list
 * @param code the code toadd
 */
void addToCodes(codes* c, unsigned int code);
/**
 * function to get the next element recursively
 * @param n the current code node
 * @param index the current index
 * @returns the code node at index 
 */
struct cnode* getCodeIndexRecursive(struct cnode* n, int index);
/**
 * function to get a specific element using getCodeIndexRecursive
 * @param lthe code list
 * @param index the index
 * @returns the code node at index
 */
struct cnode* getCodeIndex(codes* l, int index);

/**
 * function to remove item from codes list
 * @param c the codes list
 * @param index the index of the code node to remove
 */
void removeFromCodes(codes* c, int index);

/**
 * function to destroy codes list
 * @param c the codes list
 */
void destroyCodes(codes* c);

/**
 * function to print the codes list using printCnodes()
 * @param c the codes list
 */
void printCodesList(codes* c);

/**
 * function to print nodes recursively
 * @param n the code node
 */
void printCnodes(struct cnode* n);

/**
 * function to read code from openingCodes file
 * @param c the codes list
 * @param id the user id
 * @returns true if succeded
 */
bool readCodes(codes* c, int id);

/**
 * function to compare codes recursively
 * @param toCompare the code to compare
 * @param n the code node to compare toCompare to
 * @returns true if any of the codes are the same false if not
 */
bool compareRec(unsigned int toCompare, struct cnode* n);

/**
 * function to compare nodes using compareRec()
 * @param c the codes list to compare
 * @param d the codes list to be compared to
 */
bool compareCodes(codes* c, codes* d);

#endif