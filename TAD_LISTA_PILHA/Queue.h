//
// Created by alex on 30/03/2021.
//
#include "LinkedList.h"

#ifndef DS_3ADS_QUEUE_H
#define DS_3ADS_QUEUE_H

typedef struct queue {
    LinkedList* myQueue;
} Queue;

Queue* createQueue ();

void enQueue (Queue*, int);

int deQueue (Queue*);

void dropQueue (Queue*);

void printQueue (Queue*);


#endif //DS_3ADS_QUEUE_H
