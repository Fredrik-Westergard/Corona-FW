#ifndef UTILITIES_H__
#define UTILITIES_H__

#include "linkedList.h"
#include <stdbool.h>
#include "codesList.h"

/**
 * function to add new code 
 */
void newCode(list* l, codes* c);

/**
 * function to print codes
 */
void printCodes(codes* c);

/**
 * function to add new phone to linked list
 * @param l the linked list
 */
void newPhone(list* l);

/**
 * function to print phones in linked list
 * @param l the linked list
 */
void printPhones(list* l);

void sendAlarmRec(struct node* n);

/**
 * function to send alarm
 */
void sendAlarm(list* l, codes* c,int id);

/**
 * function to print menus
 * @param menu the menu to be printed
 * @param l a linked list with phones
 * @returns the number of chices in menu
 */
int printMenus(int menu, list* l, codes* c, int id);

/**
 * function to get input
 * @param items the number of items to choose form
 * @returns the input
 */
int getInput(int items);

/**
 * function to clean stdin
 */
void clean_stdin(void);

//gets and checks if the menu input is valid
int getInput(int items);

int getUser(const char* argv);

bool getAlarm(int id);

#endif