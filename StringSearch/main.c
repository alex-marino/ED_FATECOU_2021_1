#include <stdio.h>
#include "MyString.h"
#include "string.h"

int main() {

    char c1[101];
    char c2[101];



    scanf(" %[^\n]", c1);
    scanf(" %[^\n]", c2);
    if (strcmp(c1, c2)==0){
        printf("%s == %s\n", c1, c2);
    } else {
        printf("%s != %s\n", c1, c2);
    }

    printf ("%s - tam[%d]\n", c2, strlen(c2));

    printf("%s\n", strcat(c2, c1));


    char c3[101];
    strcpy(c3, strcat(c1, c2));
    printf("%s\n", c3);
//    char txt[1500];
//    char pat[15];
//    scanf(" %[^\n]", txt);
//    scanf(" %[^\n]", pat);
//
//    int i;
//    int** dfa = computeDfa(pat);
//
//    printf("Texto             :   %s\n", txt);
//    int offset = kmpSearch(txt, pat, dfa);
//    //int offset = bruteSearchAlt(txt, pat);
//    printf("Padrao            :   ");
//    for (i = 0; i < offset; i++)
//        printf(" ");
//    printf("%s\n",pat);
//    printf("Posicao do padrao = %d\n", offset+1);
}
