#ifndef HASHMAP_H__
#define HASHMAP_H__

#include "date.h"

#define SIZE 131072

struct hashmap{
    date d;
    int data;
};

unsigned int hash(date d);

#endif