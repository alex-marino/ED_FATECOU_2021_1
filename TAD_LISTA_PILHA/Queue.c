//
// Created by alex on 30/03/2021.
//

#include "Queue.h"
#include "LinkedList.h"
Queue* createQueue () {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->myQueue = LLcreateEmpty();
    return q;
}

void enQueue (Queue* q, int v) {
    LLaddEnd(q->myQueue, v);
}

int deQueue (Queue* q) {
    int ret = 0;
    if (q->myQueue->listSize!=0){
        ret = q->myQueue->firstNode->info;
        LLdeleteByIdx(q->myQueue, 0);
    }
    return ret;
}

void dropQueue (Queue* q) {
    LLdrop(q->myQueue);
    free(q);
}


void printQueue (Queue* q) {
    LLprintAll(q->myQueue);
}
