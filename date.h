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

bool isLeapYear(date d);

date getDayBefore(date d);

date getDateNumBefore(date current, int num);

int compareDates(date d1, date d2);


#endif