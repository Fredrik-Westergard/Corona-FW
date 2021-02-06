#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "date.h"


//fuction to check wether a date is valid
bool checkDate(struct date d){
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