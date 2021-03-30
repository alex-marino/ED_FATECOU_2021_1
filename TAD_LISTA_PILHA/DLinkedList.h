//
// Created by alex on 28/03/2021.
//

#ifndef DS_3ADS_DLINKEDLIST_H
#define DS_3ADS_DLINKEDLIST_H

#include "Node.h"

typedef struct dLinkedList {
    DNode* firstNode;
    DNode* lastNode;
    int listSize;
    int isEmpty;
} DLinkedList;

DLinkedList* DLLcreateEmpty ();

void DLLaddBegin (DLinkedList*, int val);

void DLLaddEnd (DLinkedList*, int val);

void DLLdeleteByIdx (DLinkedList*, int idx);

void DLLdeleteByVal (DLinkedList*, int val);

void DLLclean (DLinkedList*);

void DLLdrop (DLinkedList*);

void DLLprintAll (DLinkedList*);

int DLLisEmpty (DLinkedList* dll);

#endif //DS_3ADS_DLINKEDLIST_H
