#include <stdio.h>
#include "Util.h"
int main() {
    printf("Hello, World!\n");
    int ip1 = 0x7FFFFFFF;
    int ip2 = 0xfffffffc;
    printf("%s %s\n", TO_BASE(ip1, 16), TO_BASE(ip2, 16));
    printf("%s %s\n", TO_BASE(ip1, 2), TO_BASE(ip2, 2));
    printf("%s\n", TO_BASE(ip1&ip2, 10));
    printf("%x", -4);

    return 0;
}
