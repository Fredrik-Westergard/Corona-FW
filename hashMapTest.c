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
    e.year = 2021;

    date f;
    f.day = 01;
    f.month = 07;
    f.year = 2021;

    date g;
    g.day = 31;
    g.month = 12;
    g.year = 2000;

    TEST_CASE("create table");
    table* table = createTable();
    VERIFY(table != NULL, "verify that table is not null");

    TEST_CASE("test add1");
    addItem(table, d, 123451);
    VERIFY((getItem(table, d, 123451)->data == 123451), "verify data")
    VERIFY((getItem(table, d, 123451)->d.year == 1997), "verify year")
    VERIFY((getItem(table, d, 123451)->d.month == 1), "verify month")
    VERIFY((getItem(table, d, 123451)->d.day == 1), "verify day")

    TEST_CASE("test add2");
    addItem(table, e, 123457);
    VERIFY((getItem(table, e, 123457)->data == 123457), "verify data")
    VERIFY((getItem(table, e, 123457)->d.year == 2021), "verify year")
    VERIFY((getItem(table, e, 123457)->d.month == 3), "verify month")
    VERIFY((getItem(table, e, 123457)->d.day == 2), "verify day")

    TEST_CASE("test add3");
    addItem(table, f, 123458);
    VERIFY((getItem(table, f, 123458)->data == 123458), "verify data")
    VERIFY((getItem(table, f, 123458)->d.year == 2021), "verify year")
    VERIFY((getItem(table, f, 123458)->d.month == 7), "verify month")
    VERIFY((getItem(table, f, 123458)->d.day == 1), "verify day")

    TEST_CASE("test add4");
    addItem(table, g, 123459);
    VERIFY((getItem(table, g, 123459)->data == 123459), "verify data")
    VERIFY((getItem(table, g, 123459)->d.year == 2000), "verify year")
    VERIFY((getItem(table, g, 123459)->d.month == 12), "verify month")
    VERIFY((getItem(table, g, 123459)->d.day == 31), "verify day")

    TEST_CASE("test add5");
    addItem(table, d, 123450);
    VERIFY((getItem(table, d, 123450)->data == 123450), "verify data")
    VERIFY((getItem(table, d, 123450)->d.year == 1997), "verify year")
    VERIFY((getItem(table, d, 123450)->d.month == 1), "verify month")
    VERIFY((getItem(table, d, 123450)->d.day == 1), "verify day")

    TEST_CASE("test hash");
    VERIFY(hash(d) >= 0 && hash(d) < SIZE, "verify hash 1");
    VERIFY(hash(e) >= 0 && hash(e) < SIZE, "verify hash 2");
    VERIFY(hash(f) >= 0 && hash(f) < SIZE, "verify hash 3");
    VERIFY(hash(g) >= 0 && hash(g) < SIZE, "verify hash 4");

    TEST_CASE("verify print")
    printItems(table);

    TEST_CASE("test remove")
    removeItem(table, e, 123457);
    VERIFY(getItem(table, e, 123457) == NULL, "test that removed is null");

    printf("\n");
    TEST_CASE("verify print")
    printItems(table);

    TEST_CASE("verify read to hashmap")
    VERIFY(readToHashMap(table, 123456), "verify that read to hashmap is successfull")

    printf("\n");
    TEST_CASE("verify print")
    printItems(table);

    TEST_CASE("verify write to hashmap")
    VERIFY(writeHashMap(table, 123456), "verify that read to hashmap is successfull")

    destroyHashMap(table);

    return 0;
}
