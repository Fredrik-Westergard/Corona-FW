#ifndef __UTILITIES_H__
#define __UTILITIES_H__

struct date{
    int day;
    int month;
    int year;
};

bool checkDate(struct date d);

void newCode();

void printCodes();

void newPhone();

void printPhones();

void sendAlarm();

int printMenues(int menu);

int getInput(int items);

#endif