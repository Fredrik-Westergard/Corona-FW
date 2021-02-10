#include <stdio.h>
#include "date.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define WHITE "\033[0;37m"

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name);
#define VERIFY(cond, msg) if (cond) printf("%sSUCCESS:%s %s\n", GREEN, WHITE, msg); else printf("%sFAIL:%s %s\n", RED, WHITE, msg);
#define VERIFY_COMPARE(cond, msg) if (cond == 0) printf("%sEQUAL DATES:%s %s\n",  GREEN, WHITE, msg); else if (cond == 1) printf("DATE 1 LARGER: %s\n", msg); else if (cond == -1) printf("DATE 1 SMALLER: %s\n", msg);

int main(int argc, char const *argv[])
{
    date d1;
    d1.day = 6;
    d1.month = 2;
    d1.year = 2021;

    TEST_CASE("TESTING VALID DATE")
    VERIFY(checkDate(d1), "checking if 6.2.2021 is valid.")

    date d2;
    d2.day = 16;
    d2.month = 01;
    d2.year = 2021;

    TEST_CASE("TESTING VALID DATE 21 DAYS BEFORE PREVIOUS DATE")
    VERIFY(checkDate(d1), "checking if 16.1.2021 is valid.")
    VERIFY(compareDates(d1,d2) == 1, "comparing previous two dates, making sure date 1 is larger")
    VERIFY(compareDates(getDateNumBefore(d1,21),d2) == 0, "comparing previous two dates")

    date d3;
    d3.day = 29;
    d3.month = 02;
    d3.year = 2000;

    TEST_CASE("TESTING LEAP DAY DATE")
    VERIFY(checkDate(d3), "checking if 29.02.2000 is valid.")
    VERIFY(isLeapYear(d3), "checking if 29.02.2000 is a leap year.")

    date d4;
    d4.day = 29;
    d4.month = 02;
    d4.year = 2019;
    
    TEST_CASE("TESTING INVALID LEAP DAY DATE")
    VERIFY(!checkDate(d4), "checking if 29.02.2019 is NOT valid.")
    VERIFY(!isLeapYear(d4), "checking if 29.02.2019 is NOT a leap year.")

    date d5;
    d5.day = 10;
    d5.month = 02;
    d5.year = 2021;
    
    TEST_CASE("TESTING LEAP DAY DATE")
    VERIFY(checkDate(d5), "checking if 10.02.2021 is valid.")
    VERIFY(!isLeapYear(d5), "checking if 10.02.2021 is NOT a leap year.")
    VERIFY(compareDates(getTodaysDate(),d5) == 0, "comparing todays date to 10.02.2021")
    
    return 0;
}
