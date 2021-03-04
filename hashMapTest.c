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
    d.year = 1970;

    table* table = createTable();
    addItem(table, d, 123456);
    
    return 0;
}
