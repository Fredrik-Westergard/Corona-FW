#include <stdio.h>
#include "date.h"
#include "linkedList.h"
#include "utilities.h"

int main(int argc, char const *argv[])
{    
    list* l = createList();

    date d1;
    d1.day = 6;
    d1.month = 2;
    d1.year = 2021;
    addToList(l, 123456, d1);

    date d2;
    d2.day = 15;
    d2.month = 2;
    d2.year = 2020;
    addToList(l, 222222, d2);

    date d3;
    d3.day = 12;
    d3.month = 1;
    d3.year = 2021;
    addToList(l, 333333, d3);

    date d4;
    d4.day = 3;
    d4.month = 2;
    d4.year = 2021;
    addToList(l, 444444, d4);

    date d5;
    d5.day = 12;
    d5.month = 12;
    d5.year = 2020;
    addToList(l, 555555, d5);

    date d6;
    d6.day = 13;
    d6.month = 3;
    d6.year = 1994;
    addToList(l, 666666, d6);

    date d7;
    d7.day = 9;
    d7.month = 2;
    d7.year = 2021;
    addToList(l, 123456, d7);

    date d8;
    d8.day = 18;
    d8.month = 1;
    d8.year = 2021;
    addToList(l, 222222, d8);

    date d9;
    d9.day = 19;
    d9.month = 1;
    d9.year = 2021;
    addToList(l, 333333, d9);

    date d10;
    d10.day = 4;
    d10.month = 2;
    d10.year = 2021;
    addToList(l, 444444, d10);

    date d11;
    d11.day = 12;
    d11.month = 12;
    d11.year = 1992;
    addToList(l, 555555, d11);

    date d12;
    d12.day = 13;
    d12.month = 3;
    d12.year = 1994;
    addToList(l, 666666, d12);
    
    printList(l);

    removeTooOld(l);

    printf("\n");
    printList(l);

    removeFromList(l, 4);
    removeFromList(l, 0);
    removeFromList(l, 2);


    printf("\n");
    printList(l);

    destroyList(l);

    return 0;
}
