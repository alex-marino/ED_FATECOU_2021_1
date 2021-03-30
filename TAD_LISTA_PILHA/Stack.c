//
// Created by alex on 29/03/2021.
//

#include "Stack.h"
#include "LinkedList.h"

struct stack {
    LinkedList* top;
    int stkSize;
};

Stack* StackCreate (void) {
    Stack* st = (Stack*) malloc(sizeof(Stack));
    st->top=LLcreateEmpty();
    st->stkSize=0;
}

void StackPush (Stack* st, int v) {
    LLaddBegin(st->top, v);
    st->stkSize++;
}

int StackPop (Stack* st) {
    int ret = st->top->firstNode->info;
    LLdeleteByIdx(st->top, 0);
    st->stkSize--;
    return ret;
}
int StackTop (Stack* st) {
    return st->top->firstNode->info;
}

int StackIsEmpty (Stack* st) {
    return st->stkSize==0;
}

void StackDrop (Stack* st) {
    LLdrop(st->top);
    free(st);
}

void StackPrintAll (Stack* st) {
    LLprintAll(st->top);
}
