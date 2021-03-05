#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "date.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>


//fuction to check wether a date is valid
bool checkDate(date d){
    //epoch time variable
    time_t t = time(NULL);
    //time struture for getting day/month/year
    struct tm tm = *localtime(&t);

    //checks if the year is between 1970 and current year
    if(d.year >= 1970 && d.year <= tm.tm_year+1900){
        //checks if it's the current year + month and if the date is under or equal to todays date
        if((d.year == tm.tm_year+1900 && d.month == tm.tm_mon+1) && (d.day > 0 && d.day <= tm.tm_mday)){
            return true;
        }
        //checks if it's a valid month
        if(d.month > 0 && d.month < 13){
            //checks if it's current year, if it's current month and the day is after today or if the month is after current month
            if((d.year == tm.tm_year+1900)&&((d.month == tm.tm_mon+1 && d.day > tm.tm_mday)||(d.month > tm.tm_mon+1))){
                return false;
            }
            //checks if it's february
            if(d.month == 2){
                //checks if it's a leap year
                if(((d.year%4==0) && (d.year%100 != 0)) || (d.year%400 == 0)){
                    //checks if it's between feb 1-29
                    if(d.day > 0 && d.day < 30){
                        return true;
                    }
                }
                //checks if it's between feb 1-28
                else if(d.day > 0 && d.day < 29){
                    return true;
                }         
            }
            //checks if it's a month with 31 days in it
            else if(d.month ==  4 || d.month == 6 || d.month == 9 || d.month == 11){
                //checks if it's between 1-31st
                if(d.day > 0 && d.day < 31){
                    return true;
                }
            }
            //otherwise it checks if it's between 1 and 31
            else if(d.day > 0 && d.day < 32){
                return true;
            }      
        }
    }
    return false;
}
//function to print date in ISO 8601 format
void printDateISO(date d){
    printf("%04d-%02d-%02d", d.year, d.month, d.day);
}
//function to print date in finnish format
void printDateFI(date d){
    printf("%02d-%02d-%04d", d.day, d.month, d.year);
}
//function to check if a date is in a leap year
bool isLeapYear(date d){
    if((d.year%4 == 0)&&(d.year%100 != 0 || d.year%400 == 0)){
        return true;
    }
    return false;
}
//function to get the day before a date
date getDayBefore(date d){
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    d.day--;
    if(d.day < 1){
        d.month--;
        if(d.month < 1){
            d.month = 12;
            d.year--;
        }
        d.day = days[d.month-1];
        if(isLeapYear(d) && d.month == 2){
            d.day++;
        }
    }
    return d;

}
//function to get a date a number of days before the given date
date getDateNumBefore(date current, int num){
    if(num <= 0){
        return current;
    }
    date new = getDateNumBefore(getDayBefore(current), num-1);
    return new;
}
//function to compare dates
int compareDates(date d1, date d2){
    if(d1.year == d2.year){
        if(d1.month == d2.month){
            if(d1.day == d2.day){
                return 0;
            }
            else if(d1.day > d2.day){
                return 1;
            }
            else{
                return -1;
            }
        }
        else if(d1.month > d2.month){
            return 1;
        }
        else{
            return -1;
        }
    }
    else if(d1.year > d2.year){
        return 1;
    }
    else{
        return -1;
    }
}
//function to get todays date
date getTodaysDate(){
    time_t t = time(NULL);
    struct tm* ts = localtime(&t);
    date d;
    d.day = ts->tm_mday;
    d.month = ts->tm_mon+1;
    d.year = ts->tm_year+1900;
    return d;
}

void parseDate(date* d, const char* argv){
    if(strlen(argv) == 10){
        date e;
        e.year = (((*argv)-48)*1000)+(((*(argv+1))-48)*100)+(((*(argv+2))-48)*10)+(((*(argv+3))-48));
        e.month = (((*(argv+5))-48)*10)+((*(argv+6))-48);
        e.day = (((*(argv+8))-48)*10)+((*(argv+9))-48);
        if(checkDate(e)){
            d->year = e.year;
            d->month = e.month;
            d->day = e.day;
        }
        else{
            exit(0);
        }
    }
}