#include <stdio.h>
#include "date.h"

int main(int argc, char const *argv[])
{
    date d1;
    d1.day = 06;
    d1.month = 02;
    d1.year = 2021;
    if(checkDate(d1)){
        printf("date1 ok: ");
        printDateISO(d1);
        printf("\n");
        printf("21 days before: ");
        printDateISO(getDateNumBefore(d1,21));
        printf("\n");
    }
    else{
        printf("date1 not OK\n");
    }
    date d2;
    d2.day = 05;
    d2.month = 02;
    d2.year = 2021;
    if(checkDate(d2)){
        printf("date2 ok: ");
        printDateISO(d2);
        printf("\n");
        printf("21 days before: ");
        printDateISO(getDateNumBefore(d2,21));
        printf("\n");
    }
    else{
        printf("date2 not OK\n");
    }
    date d3;
    d3.day = 18;
    d3.month = 01;
    d3.year = 2021;
    if(checkDate(d3)){
        printf("date3 ok: ");
        printDateISO(d3);
        printf("\n");
        printf("21 days before: ");
        printDateISO(getDateNumBefore(d3,21));
        printf("\n");
    }
    else{
        printf("date3 not OK\n");
    }
    date d4;
    d4.day = 31;
    d4.month = 01;
    d4.year = 2021;
    if(checkDate(d4)){
        printf("date4 ok: ");
        printDateISO(d4);
        printf("\n");
        printf("21 days before: ");
        printDateISO(getDateNumBefore(d4,21));
        printf("\n");
    }
    else{
        printf("date4 not OK\n");
    }
    date d5;
    d5.day = 16;
    d5.month = 01;
    d5.year = 2021;
    if(checkDate(d5)){
        printf("date5 ok: ");
        printDateISO(d5);
        printf("\n");
        printf("21 days before:");
        printDateISO(getDateNumBefore(d5,21));
        printf("\n");
    }
    else{
        printf("date5 not OK\n");
    }

    printf("dates within 21 days of ");
    printDateISO(d1);
    printf("\n");
    if(compareDates(getDateNumBefore(d1,21), d2) <= 0){
        printDateISO(d2);
        printf("\n");
    }
    if(compareDates(getDateNumBefore(d1,21), d3) <= 0){
        printDateISO(d3);
        printf("\n");
    }
    if(compareDates(getDateNumBefore(d1,21), d4) <= 0){
        printDateISO(d4);
        printf("\n");
    }
    if(compareDates(getDateNumBefore(d1,21), d5) <= 0){
        printDateISO(d5);
        printf("\n");
    }
    
    return 0;
}
