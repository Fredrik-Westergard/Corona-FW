#include <stdio.h>
#include "date.h"
#include "linkedList.h"
#include "utilities.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define WHITE "\033[0;37m"

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name);
#define VERIFY(cond, msg) if (cond) printf("%sSUCCESS:%s %s\n", GREEN, WHITE, msg); else printf("%sFAIL:%s %s\n", RED, WHITE, msg);


int main(int argc, char const *argv[])
{    
    list* l = createList();
    TEST_CASE("VERIFY LIST CREATION")
    VERIFY((l != NULL), "verify that list is not NULL")

    date d1;
    d1.day = 6;
    d1.month = 2;
    d1.year = 2021;
    addToList(l, 111111, d1);
    TEST_CASE("VERIFY ADD TO LIST")
    VERIFY((l->head != NULL), "verify that list head is not NULL")

    date d2;
    d2.day = 15;
    d2.month = 2;
    d2.year = 2020;
    addToList(l, 222222, d2);
    TEST_CASE("VERIFY ADD TO LIST")
    VERIFY((l->head->code == 222222), "verify that list items code is correct")

    date d3;
    d3.day = 12;
    d3.month = 1;
    d3.year = 2021;
    addToList(l, 333333, d3);
    TEST_CASE("VERIFY ADD TO LIST")
    VERIFY((l->head->d.day == 12), "verify that list items day is correct")

    date d4;
    d4.day = 3;
    d4.month = 2;
    d4.year = 2021;
    addToList(l, 444444, d4);
    TEST_CASE("VERIFY ADD TO LIST")
    VERIFY((l->head->d.month == 2), "verify that list items month is correct")

    date d5;
    d5.day = 12;
    d5.month = 12;
    d5.year = 2020;
    addToList(l, 555555, d5);
    TEST_CASE("VERIFY ADD TO LIST")
    VERIFY((l->head->d.year == 2020), "verify that list items year is correct")

    date d6;
    d6.day = 13;
    d6.month = 3;
    d6.year = 1994;
    addToList(l, 666666, d6);
    TEST_CASE("VERIFY ADD TO LIST")
    VERIFY(((l->head->d.day == 13)&&(l->head->d.month == 3)&&(l->head->d.year == 1994)&&(l->head->code == 666666)), "verify that list everything in list item is correct")

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

    TEST_CASE("VERIFY OUTPUT")
    printList(l);
    printf("\n");
    TEST_CASE("REMOVING TOO OLD, VERIFY OUTPUT")
    removeTooOld(l);
    printList(l);

    int length = l->length;
    TEST_CASE("REMOVING INDEX 3, 0 AND 1")
    removeFromList(l, 3);
    removeFromList(l, 0);
    removeFromList(l, 1);
    VERIFY((l->length == length-3), "verify that the list length is 3 less than before");
    printf("\n");
    
    TEST_CASE("VERIFY OUTPUT")
    printList(l);

    destroyList(l);

    return 0;
}
