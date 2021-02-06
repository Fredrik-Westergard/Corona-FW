#ifndef UTILITIES_H__
#define UTILITIES_H__

#include "linkedList.h"

void newCode();

void printCodes();

void newPhone(list* l, int* length);

void printPhones(list* l);

void sendAlarm();

int printMenues(int menu, list* l, int* length);

int getInput(int items);

void clean_stdin(void);

#endif