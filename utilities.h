#ifndef UTILITIES_H__
#define UTILITIES_H__

//#include "linkedList.h"
#include <stdbool.h>
#include "codesList.h"
#include "hashMap.h"

/**
 * function to add new code
 * @param l the list of phones
 * @param c the list of codes 
 */
void newCode(table* t, codes* c);

/**
 * function to print codes
 * @param c the codes to print
 */
void printCodes(codes* c);

/**
 * function to add new phone to linked list
 * @param l the linked list
 */
void newPhone(table* t);

/**
 * function to print phones in linked list
 * @param l the linked list
 */
void printPhones(table* t);

/**
 * function to send alarm recursively
 * @param n the node
 */
void sendAlarmRec(item* it);

/**
 * function to send alarm
 * @param l the list of phones
 * @param c the list of codes
 * @param id the user id
 */
void sendAlarm(table* t, codes* c,int id);

/**
 * function to print menus
 * @param menu the menu to be printed
 * @param l a linked list with phones
 * @param c the linked list with codes
 * @param id the user id
 * @returns the number of chices in menu
 */
int printMenus(int menu, table* t, codes* c, int id);

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

/**
 * gets and checks if the menu input is valid
 * @param items the amount of items in list
 * @returns the chosen menu item
 */
int getInput(int items);

/**
 * function to get the user id from command line arguments
 * @param argv the command line argument
 */
int getUser(const char* argv);

/**
 * function to get alarm from server
 * @param id the user id
 * @returns true if there is an alarm, false if not
 */
bool getAlarm(int id);

#endif