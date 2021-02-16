#include <stdio.h>
#include "codesList.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define WHITE "\033[0;37m"

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name);
#define VERIFY(cond, msg) if (cond) printf("%sSUCCESS:%s %s\n", GREEN, WHITE, msg); else printf("%sFAIL:%s %s\n", RED, WHITE, msg);


int main(int argc, char const *argv[])
{    
    codes* c = createCodesList();
    TEST_CASE("VERIFY LIST CREATION")
    VERIFY((c != NULL), "verify that list is not NULL")

    addToCodes(c, 11111111);
    TEST_CASE("VERIFY ADD TO LIST")
    VERIFY((c->head != NULL), "verify that list head is not NULL")

    addToCodes(c, 22222222);
    TEST_CASE("VERIFY ADD TO LIST")
    VERIFY((c->head->code == 22222222), "verify that list items code is correct")

    addToCodes(c, 33333333);
    addToCodes(c, 44444444);
    addToCodes(c, 55555555);
    addToCodes(c, 66666666);
    addToCodes(c, 12345678);
    addToCodes(c, 33343333);
    addToCodes(c, 44454444);
    addToCodes(c, 55565555);
    addToCodes(c, 66676666);
    addToCodes(c, 12345679);

    TEST_CASE("VERIFY OUTPUT")
    printCodesList(c);
    printf("\n");

    int length = c->length;
    TEST_CASE("REMOVING INDEX 3, 0 AND 1")
    removeFromCodes(c, 3);
    removeFromCodes(c, 0);
    removeFromCodes(c, 1);
    VERIFY((c->length == length-3), "verify that the list length is 3 less than before");
    printf("\n");
    
    TEST_CASE("VERIFY OUTPUT")
    printCodesList(c);
    destroyCodes(c);

    codes* d = createCodesList();

    destroyCodes(d);

    return 0;
}
