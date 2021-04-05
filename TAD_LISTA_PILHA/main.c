#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "DLinkedList.h"
#include "Stack.h"
#include "Queue.h"

int main() {
    Queue* q = createQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    LLprintAll(q->myQueue);
    deQueue(q);
    LLprintAll(q->myQueue);
    enQueue(q, 1);
    LLprintAll(q->myQueue);
//    LinkedList* ll = LLcreateEmpty();
//    LLaddBegin(ll, 5);
//    LLaddBegin(ll, 6);
//    LLaddBegin(ll, 7);
//    LLaddBegin(ll, 8);
//    LLaddBegin(ll, 9);
//    LLaddBegin(ll, 10);
//    LLaddBegin(ll, 11);
//    LLprintAll(ll);
//    LLdeleteByIdx(ll, 0);
//    LLprintAll(ll);
//    LLaddEnd(ll, 4);
//    LLaddEnd(ll, 3);
//    LLaddEnd(ll, 2);
//    LLprintAll(ll);
//    LLdeleteByVal(ll, 8);
//    LLdeleteByVal(ll, 7);
//    LLprintAll(ll);
//    LLdeleteByVal(ll, 2);
//    LLprintAll(ll);
//    LLprintAll(ll);
//    LLdeleteByVal(ll, 10);
//    LLprintAll(ll);
//    LLdeleteByVal(ll, 5);
//    LLprintAll(ll);
//    LLdrop(ll);
//    printf("---------------------------------------------\n");
//    DLinkedList* dll = DLLcreateEmpty();
//    DLLaddBegin(dll, 10);
//    DLLaddBegin(dll, 9);
//    DLLaddBegin(dll, 8);
//    DLLaddBegin(dll, 7);
//    DLLaddBegin(dll, 6);
//    DLLaddBegin(dll, 5);
//    DLLprintAll(dll);
//    DLLaddEnd(dll, 4);
//    DLLaddEnd(dll, 3);
//    DLLaddEnd(dll, 2);
//    DLLaddEnd(dll, 1);
//    DLLprintAll(dll);
//    DLLdeleteByIdx(dll, 0);
//    DLLdeleteByIdx(dll, 8);
//    DLLdeleteByIdx(dll, 3);
//    DLLprintAll(dll);
//    DLLdeleteByVal(dll, 6);
//    DLLdeleteByVal(dll, 2);
//    DLLdeleteByVal(dll, 10);
//    DLLprintAll(dll);
//    DLLdrop(dll);
//    printf("------------------------------------------------\n");
//    Stack* st = StackCreate();
//    StackPush(st, 5);
//    StackPush(st, 4);
//    StackPush(st, 3);
//    StackPush(st, 2);
//    StackPush(st, 1);
//    StackPrintAll(st);
//    printf("------------------------------------------------\n");
//    int a = StackPop(st);
//    a=StackPop(st);
//    a=StackPop(st);
//    StackPush(st, 45);
//    StackPrintAll(st);

    return 0;
}
