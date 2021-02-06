#ifndef DATE_H__
#define DATE_H__

#include <stdbool.h>

/**
 *  date structure 
 */
typedef struct{
    int day;
    int month;
    int year;
}date;

/**
 * function to check if a date is valid
 * @param d the date to be checked
 * @returns true if valid false if not
 */
bool checkDate(date d);

/**
 * funtion to print date in iso 8601 format
 * @param d date to be printed
 */
void printDateISO(date d);

/**
 * funtion to print date in finnish format
 * @param d date to be printed
 */
void printDateFI(date d);

/**
 * function to check if a date is leap year
 * @param d the date to be checked
 * @returns true if leap year, false if not
 */
bool isLeapYear(date d);

/**
 * funtion to get the day before a given date
 * @param d a date
 * @returns the date before the date
 */
date getDayBefore(date d);

/**
 * function to get the date a number of days before a certain date
 * @param current the current date
 * @param num the number of days to go back
 * @returns a date a number of days before the current date
 */
date getDateNumBefore(date current, int num);

int compareDates(date d1, date d2);

date getTodaysDate();

#endif