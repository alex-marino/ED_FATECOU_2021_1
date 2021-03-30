//
// Created by alex on 28/03/2021.
//
#include <stdio.h>
#include "DLinkedList.h"

DLinkedList* DLLcreateEmpty () {
    DLinkedList* dll = (DLinkedList*) malloc(sizeof(DLinkedList));
    dll->listSize=0;
    dll->lastNode=NULL;
    dll->firstNode=NULL;
}

void DLLaddBegin (DLinkedList* dll, int val) {
    DNode* newNode = createDNode(val);
    if (dll->firstNode==NULL){
        newNode->prev=NULL;
        newNode->next=NULL;
        dll->firstNode=newNode;
        dll->lastNode=newNode;
    } else {
        newNode->prev=NULL;
        newNode->next=dll->firstNode;
        newNode->next->prev=newNode;
        dll->firstNode=newNode;
    }
    dll->listSize++;
}

void DLLaddEnd (DLinkedList* dll, int val) {
    DNode* newNode = createDNode(val);
    if (dll->firstNode==NULL){
        dll->firstNode=newNode;
        dll->lastNode=newNode;
    } else {
        newNode->prev=dll->lastNode;
        dll->lastNode->next=newNode;
        newNode->next=NULL;
        dll->lastNode=newNode;
    }
    dll->listSize++;
}

void DLLdeleteByIdx (DLinkedList* dll, int idx) {
    DNode* curr = dll->firstNode;
    if (idx==0){
        dll->firstNode=curr->next;
        dll->firstNode->prev=NULL;
        dropDNode(curr);
        dll->listSize--;
    } else{
        int i;
        curr=curr->next;
        for(i=1; i<dll->listSize; curr=curr->next){
            if (idx==i){
                if (curr==dll->lastNode){
                    dll->lastNode->prev->next=NULL;
                    dll->lastNode=dll->lastNode->prev;
                    dropDNode(curr);
                    dll->listSize--;
                    break;
                } else{
                    curr->prev->next=curr->next;
                    curr->next->prev=curr->prev;
                    dropDNode(curr);
                    dll->listSize--;
                    break;
                }
            }
            i++;
        }
    }

}

void DLLdeleteByVal (DLinkedList* dll, int val) {
    DNode* curr = dll->firstNode;
    if (curr->info==val){
        dll->firstNode=curr->next;
        dll->firstNode->prev=NULL;
        dropNode(curr);
        dll->listSize--;
    } else{
        int i;
        curr=curr->next;
        for(i=1; i<dll->listSize; curr=curr->next){
            if (curr->info==val){
                if (dll->lastNode==curr){
                    dll->lastNode->prev->next=NULL;
                    dll->lastNode=dll->lastNode->prev;
                    dropNode(curr);
                    dll->listSize--;
                    break;
                } else{
                    curr->prev->next=curr->next;
                    curr->next->prev=curr->prev;
                    dropNode(curr);
                    dll->listSize--;
                    break;
                }
            }
        }
    }
}

void DLLdrop (DLinkedList* dll) {
    DNode* curr = dll->firstNode;
    DNode* aux;
    while (curr->next!=NULL){
        aux=curr;
        curr=curr->next;
        free(aux);
    }
    free(dll);
}

void DLLprintAll (DLinkedList* dll) {
    printf("%d ", dll->firstNode->info);
    Node* curr = dll->firstNode->next;
    while (curr!=dll->lastNode){
        printf("- %d ", curr->info);
        curr=curr->next;
    }
    printf("- %d #SIZE=%d\n", curr->info, dll->listSize);
}

int DLLisEmpty (DLinkedList* dll) {
   return (dll->listSize==0);
}
