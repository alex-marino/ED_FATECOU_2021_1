//
// Created by alex on 29/03/2021.
//
#include "LinkedList.h"

#ifndef DS_3ADS_STACK_H
#define DS_3ADS_STACK_H

typedef struct stack Stack;

Stack* StackCreate (void);

void StackPush (Stack* st, int v);

int StackPop (Stack* st);

int StackTop (Stack* st);

int StackIsEmpty (Stack* st);

void StackDrop (Stack* st);

void StackPrintAll (Stack* st);


#endif //DS_3ADS_STACK_H
