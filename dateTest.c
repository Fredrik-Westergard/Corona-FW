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
    }
    else{
        printf("date1 not OK\n");
    }
    date d2;
    d2.day = 07;
    d2.month = 02;
    d2.year = 2021;
    if(checkDate(d2)){
        printf("date2 ok: ");
        printDateISO(d2);
        printf("\n");
    }
    else{
        printf("date2 not OK\n");
    }
    date d3;
    d3.day = 07;
    d3.month = 01;
    d3.year = 2021;
    if(checkDate(d3)){
        printf("date3 ok: ");
        printDateISO(d3);
        printf("\n");
    }
    else{
        printf("date3 not OK\n");
    }
    date d4;
    d4.day = 07;
    d4.month = 02;
    d4.year = 2020;
    if(checkDate(d4)){
        printf("date4 ok: ");
        printDateISO(d4);
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
    }
    else{
        printf("date5 not OK\n");
    }
    
    return 0;
}
