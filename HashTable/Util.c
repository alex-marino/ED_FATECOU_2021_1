//
// Created by alex on 28/04/2021.
//

#include "Util.h"
#include <assert.h>
#include <limits.h>


// Tailor the details of the conversion function as needed
// This one does not display unneeded leading zeros
// Use return value, not `buf`
char *my_to_base(char buf[TO_BASE_N], unsigned i, int base) {
    assert(base >= 2 && base <= 36);
    char *s = &buf[TO_BASE_N - 1];
    *s = '\0';
    do {
        s--;
        *s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i % base];
        i /= base;
    } while (i);

    // Could employ memmove here to move the used buffer to the beginning
    // size_t len = &buf[TO_BASE_N] - s;
    // memmove(buf, s, len);

    return s;
}