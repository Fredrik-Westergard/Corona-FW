#ifndef UTILITIES_H__
#define UTILITIES_H__

#include "linkedList.h"

void newCode();

void printCodes();

void removeOldRecursive(list* l, struct node* n, date tooOld, int index);

void removeTooOld(list* l);

void newPhone(list* l);

void printPhones(list* l);

void sendAlarm();

int printMenues(int menu, list* l);

int getInput(int items);

void clean_stdin(void);

#endif