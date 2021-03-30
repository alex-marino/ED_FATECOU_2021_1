//
// Created by alex on 26/03/2021.
//

#include "Node.h"



Node* createNode(int v){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->info = v;
    newNode->next = NULL;
    return newNode;
}

void dropNode(Node* n){
    free(n);
}


DNode* createDNode (int v){
    DNode* newNode = (DNode*) malloc(sizeof(DNode));
    newNode->info = v;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void dropDNode(DNode* n) {
    free(n);
}


