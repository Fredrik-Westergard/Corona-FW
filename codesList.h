#ifndef CODESLIST_H__
#define CODESLIST_H__

struct cnode{
    unsigned int code;
    struct cnode* next;
};

typedef struct{
    struct cnode* head;
    int length;
}codes;

codes* createCodesList();

struct cnode* createCnode();

void addToCodes(codes* c, unsigned int code);

//function to get the next element recursively
struct cnode* getIndexRecursive(struct cnode* n, int index);

//function to get a specific element using getIndexRecursive
struct cnode* getCodeIndex(codes* l, int index);

//function to remove item from list
void removeFromCodes(codes* c, int index);

//function to destroy list
void destroyCodes(codes* c);

//function to print the list using printNodes()
void printCodes(codes* c);

//function to print nodes recursively
void printCnodes(struct cnode* n);

#endif