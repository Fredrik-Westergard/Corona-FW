#include <stdio.h>
#include "hashMap.h"
#include "date.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define WHITE "\033[0;37m"

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name);
#define VERIFY(cond, msg) if (cond) printf("%sSUCCESS:%s %s\n", GREEN, WHITE, msg); else printf("%sFAIL:%s %s\n", RED, WHITE, msg);

int main(int argc, char const *argv[])
{
    date d;
    d.day = 01;
    d.month = 01;
    d.year = 1997;

    date e;
    e.day = 02;
    e.month = 03;
    e.year = 2121;

    date f;
    f.day = 01;
    f.month = 07;
    f.year = 2021;

    date g;
    g.day = 31;
    g.month = 12;
    g.year = 2800;

    table* table = createTable();
    addItem(table, d, 123456);
    addItem(table, e, 123457);
    addItem(table, f, 123458);
    addItem(table, g, 123459);
    addItem(table, d, 123450);
    printf("%u\n", hash(d));
    printf("%u\n", hash(e));
    printf("%u\n", hash(f));
    printf("%u\n", hash(g));
    printItems(table);

    removeItem(table, e, 123457);
    printf("\n");
    printItems(table);

    readToHashMap(table, 123456);

    printItems(table);

    writeHashMap(table, 123459);

    destroyHashMap(table);

    return 0;
}
