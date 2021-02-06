#include <stdio.h>
#include "date.h"
#include "linkedList.h"

int main(int argc, char const *argv[])
{   
    int length = 0;
    
    list* l = createList();

    date d1;
    d1.day = 6;
    d1.month = 2;
    d1.year = 2021;
    addToList(l, 123456, d1);
    length++;

    date d2;
    d2.day = 15;
    d2.month = 2;
    d2.year = 2020;
    addToList(l, 222222, d2);
    length++;

    date d3;
    d3.day = 12;
    d3.month = 1;
    d3.year = 2021;
    addToList(l, 333333, d3);
    length++;

    date d4;
    d4.day = 3;
    d4.month = 2;
    d4.year = 2021;
    addToList(l, 444444, d4);
    length++;

    date d5;
    d5.day = 12;
    d5.month = 12;
    d5.year = 2020;
    addToList(l, 555555, d5);
    length++;

    date d6;
    d6.day = 13;
    d6.month = 3;
    d6.year = 1994;
    addToList(l, 666666, d6);
    length++;
    
    printList(l->head);

    removeFromList(l, 0, length);
    length--;
    removeFromList(l, length-1,length);
    length--;
    removeFromList(l, 2, length);
    length--;

    printf("\n");
    printList(l->head);

    destroyList(l, length);

    return 0;
}
