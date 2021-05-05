//
// Created by alexmarino on 05/03/2020.
//
#include <string.h>
#ifndef STRINGSEARCH_MYSTRING_H
#define STRINGSEARCH_MYSTRING_H

int bruteSearch(char*, char*);

int bruteSearchAlt(char*, char*);

int** computeDfa(char*);

int kmpSearch(char*, char*, int**);


#endif //STRINGSEARCH_MYSTRING_H
