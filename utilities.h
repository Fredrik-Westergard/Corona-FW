#ifndef UTILITIES_H__
#define UTILITIES_H__

#include "linkedList.h"

/**
 * function to add new code 
 */
void newCode(list* l);

/**
 * function to print codes
 */
void printCodes();

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

/**
 * function to send alarm
 */
void sendAlarm();

/**
 * function to print menus
 * @param menu the menu to be printed
 * @param l a linked list with phones
 * @returns the number of chices in menu
 */
int printMenus(int menu, list* l, int id);

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

#endif