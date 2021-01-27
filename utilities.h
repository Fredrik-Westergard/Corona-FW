#ifndef __UTILITIES_H__
#define __UTILITIES_H__

//date structure
struct date{
    int day;
    int month;
    int year;
};

//function to check whether a date is valid
bool checkDate(struct date d);

//function to input new opening code
void newCode();

//function to print the stored codes
void printCodes();

//function to add a new phone
void newPhone();

//function to print the stored phones
void printPhones();

//function to send an alarm
void sendAlarm();

//function to print the menus
int printMenues(int menu);

/*
    function taken from stackoverflow, fflush did not work on linux for some reason.
    this does what fflush is supposed to do.
*/
void clean_stdin(void);

//gets and checks if the menu input is valid
int getInput(int items);

#endif