//
// Created by alex on 26/03/2021.
//
#include "Node.h"
#ifndef DS_3ADS_LINKEDLIST_H
#define DS_3ADS_LINKEDLIST_H

typedef struct linkedList {
    Node* firstNode;
    Node* lastNode;
    int listSize;
    int isEmpty;
} LinkedList;

LinkedList* LLcreateEmpty ();

void LLaddBegin (LinkedList*, int val);

void LLaddEnd (LinkedList*, int val);

void LLdeleteByIdx (LinkedList*, int idx);

void LLdeleteByVal (LinkedList*, int val);

void LLclean (LinkedList*);

void LLdrop (LinkedList*);

void LLprintAll (LinkedList*);

#endif //DS_3ADS_LINKEDLIST_H
