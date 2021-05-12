//
// Created by alex on 28/04/2021.
//

#ifndef HASHTABLE_UTIL_H
#define HASHTABLE_UTIL_H
#include <assert.h>
#include <limits.h>
#define TO_BASE_N (sizeof(unsigned)*CHAR_BIT + 1)
#define TO_BASE(x, b) my_to_base((char [TO_BASE_N]){""}, (x), (b))

char *my_to_base(char buf[TO_BASE_N], unsigned i, int base);
#endif //HASHTABLE_UTIL_H
