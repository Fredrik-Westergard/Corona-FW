#include <stdio.h>
#include "hashMap.h"
#include "date.h"

unsigned int hash(date d){
    unsigned int toHash = (d.year*10000)+(d.month*100)+(d.day);
    printf("%u\n", toHash);
    return toHash % SIZE;
}