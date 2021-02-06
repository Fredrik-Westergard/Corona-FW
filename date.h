#ifndef DATE_H__
#define DATE_H__

#include <stdbool.h>

typedef struct{
    int day;
    int month;
    int year;
}date;

bool checkDate(date d);

void printDateISO(date d);

void printDateFI(date d);

#endif