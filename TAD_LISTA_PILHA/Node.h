//
// Created by alex on 26/03/2021.
//
#include <stdlib.h>
#ifndef DS_3ADS_NODE_H
#define DS_3ADS_NODE_H

typedef struct node {
    int info;
    struct node* next;
} Node;

typedef struct dNode {
    int info;
    struct dNode* next;
    struct dNode* prev;
} DNode;

Node* createNode (int);

DNode* createDNode (int);

void dropDNode(DNode*);

void dropNode(Node*);


#endif //DS_3ADS_NODE_H
